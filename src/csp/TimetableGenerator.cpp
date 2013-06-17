/*
 * Copyright (C) Software Liberation Maniacs Cracow
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "TimetableGenerator.hpp"
#include "TimetableAttribute.hpp"
#include <iostream>
#include <algorithm>
#include <utility>

slimak::TimetableGenerator::TimetableGenerator (
	int given_number_of_days,
	int given_number_of_slots,
	std::map< int, TimetableGroup > given_groups,
	std::map< int, TimetableTeacher > given_teachers,
	std::map< int, TimetableSubject > given_subjects,
	std::map< int, TimetableClassroom > given_classrooms,
	std::vector< TimetableConstraint * > given_constraints
) {

	number_of_days = given_number_of_days;
	number_of_slots = given_number_of_slots;

	global_domain = generateGlobalDomain (
		given_teachers, given_subjects, given_classrooms, given_constraints
	);

	std::cerr << "[CSP] Domain generation results:" << std::endl;
	std::cerr << "[CSP] <teacher> <subject> <classroom>" << std::endl;
	for ( std::vector< TimetableColor >::iterator it = global_domain.begin();
		it != global_domain.end(); ++it ) {
		std::cerr << "[CSP] " << it->teacher.id << ' ' << it->subject.id
			<< ' ' << it->classroom.id << std::endl;
	}
	
	slots_domains = generateSlotsDomains( given_constraints );
	
	std::cerr << "[CSP] Slots domain generation results:" << std::endl;
	std::cerr << "[CSP] <teacher> <subject> <classroom>" << std::endl;

	for (int day = 0; day < number_of_days; ++day ) {
		std::cerr << "[CSP] - day " << day << ": " << std::endl;

		for (int slot = 0; slot < number_of_slots; ++slot) {
			std::cerr << "[CSP] - - slot " << slot << ": " << std::endl;

			for ( std::vector< TimetableColor >::iterator it = 
				slots_domains.colors[day][slot].begin();
				it != slots_domains.colors[day][slot].end();
				++it ) {

				std::cerr << "[CSP] - - - " << it->teacher.id << ' ' << it->subject.id
					<< ' ' << it->classroom.id << std::endl;

			}
		}
	}

}

std::vector< slimak::TimetableColor >
slimak::TimetableGenerator::generateGlobalDomain (
	std::map< int, TimetableTeacher > given_teachers,
	std::map< int, TimetableSubject > given_subjects,
	std::map< int, TimetableClassroom > given_classrooms,
	std::vector< TimetableConstraint * > given_constraints
) {

	std::vector< slimak::TimetableColor > result;

	std::cerr << "[CSP] Generating global domain..." << std::endl;

	for ( std::map< int, TimetableTeacher >::iterator ti = given_teachers.begin();
		ti != given_teachers.end(); ++ti ) {

		slimak::TimetableTeacher teacher_i = ti->second;
		std::cerr << "[CSP] - Subjects of teacher with id " << teacher_i.id << ": " << std::endl;

		for (int j = 0; j < teacher_i.subjects.size(); ++j ) {

			slimak::TimetableSubject subject_j = given_subjects[ teacher_i.subjects[j] ];
			std::cerr << "[CSP] - - Subject " << subject_j.id << " classrooms: " << std::endl;
			std::cerr << "[CSP] - - - " ;

			for (int k = 0; k < subject_j.classrooms.size(); ++k) {

				slimak::TimetableClassroom classroom_k =
					given_classrooms[ subject_j.classrooms[k] ];

				std::cerr << classroom_k.id;

				slimak::TimetableColor new_color( teacher_i, subject_j, classroom_k );
				
				if ( consistent( new_color, given_constraints ) ) {
					result.push_back( new_color );
					std::cerr << ", ";
				} else {
					std::cerr << " (inconsistent), ";
				}

			}

			std::cerr << std::endl;

		}

	}

	return result;

}

slimak::TimetablePlan slimak::TimetableGenerator::generateForGroup ( 
	slimak::TimetableGroup given_group
) {
	resetPlan( given_group.id );

	// Meaning:
	// remaining_lessons[ subject_id ] = remaining_subject_lessons
	std::vector< int > remaining_lessons = given_group.subjects_lessons;
	
	// Meaning:
	// assigned_teachers[ subject_id ] = assigned_teacher_id
	std::vector< int > assigned_teachers (
		given_group.subjects.size(), -1
	);

	std::vector< std::pair< int, int > > slots_queue;
	// Start from monday 8:00
	slots_queue.push_back( std::pair< int, int > (0, 0) );

	// Construct
	while ( slots_queue.size() > 0 ) {

		/* Search what to pop */
		int max_suitability = -1;
		std::vector< std::pair< int, int > >::iterator
			max_suitability_slot = slots_queue.end();

		for ( std::vector< std::pair< int, int > >::iterator
			it = slots_queue.begin();
			it != slots_queue.end();
			++it
		) {

			int day = it->first;
			int slot = it->second;

			if ( !groups_timetables[ given_group.id ].slots[day][slot].isEmpty() ) {
				// slots_queue.erase( it ); // Psuje iteracje
				continue;
			}

			/* Check the suitability */
			int it_domain_size = slots_domains.colors[day][slot].size();
			int it_suitability = 0;
			for (int j = 0; j < it_domain_size; ++j) {

				slimak::TimetableColor
					color_j = slots_domains.colors[day][slot][j];
				if ( isSuitableForGroup ( 
					color_j, 
					given_group,
					remaining_lessons,
					assigned_teachers
					)
				)
					++it_suitability;
			}

			if (it_suitability > max_suitability) {
				max_suitability = it_suitability;
				max_suitability_slot = it;
			}

		}

		// The most suitable slot:
		int day = max_suitability_slot->first;
		int slot = max_suitability_slot->second;
		slots_queue.erase( max_suitability_slot );

		// Expand
		if ( day < number_of_days-1 )
			slots_queue.push_back( std::pair< int, int > (day+1, slot) );
		if ( slot < number_of_slots-1 )
			slots_queue.push_back( std::pair< int, int > (day, slot+1) );
		
		// Color
		slimak::TimetableColor color_result(true);
		int slot_domain_size = slots_domains.colors[day][slot].size();
		for (int i = 0; i < slot_domain_size; ++i) {

			slimak::TimetableColor
				color_i = slots_domains.colors[day][slot][i];

			if ( isSuitableForGroup ( 
				color_i,
				given_group,
				remaining_lessons,
				assigned_teachers
				)
			) {
				color_result = color_i;
				break;
			}
		}

		std::vector< int >::iterator
			subject_k = std::find (
				given_group.subjects.begin(),
				given_group.subjects.end(),
				color_result.subject.id
			);

		int group_subject_number =
			std::distance (
				given_group.subjects.begin(),
				subject_k
			);

		if ( !color_result.isBlank() ) {
			if ( assigned_teachers [group_subject_number] == -1 ) {
				assigned_teachers [group_subject_number] = color_result.teacher.id;
			}
			remaining_lessons[group_subject_number] =
			remaining_lessons[group_subject_number] - 1;
		}
		
		groups_timetables[ given_group.id ].slots[day][slot] = color_result;

		if ( !color_result.isBlank() ) {
			for ( std::vector< slimak::TimetableColor >::iterator
				color_it = slots_domains.colors[day][slot].begin();
				color_it != slots_domains.colors[day][slot].end();
				++color_it ) {

					if ( (color_it->teacher.id == color_result.teacher.id)
						&& (color_it->subject.id == color_result.subject.id)
						&& (color_it->classroom.id == color_result.classroom.id)
					) {
						slots_domains.colors[day][slot].erase( color_it );
						break;
					}
			}
		}

	}

	return groups_timetables[ given_group.id ];

}


bool slimak::TimetableGenerator::isSuitableForGroup ( 
	slimak::TimetableColor given_color,
	slimak::TimetableGroup given_group,
	std::vector< int > remaining_lessons,
	std::vector< int > assigned_teachers
) {

	std::vector< int >::iterator
		subject_k = std::find (
			given_group.subjects.begin(),
			given_group.subjects.end(),
			given_color.subject.id
		);

	if ( subject_k == given_group.subjects.end() )
		return false;

	int group_subject_number =
		std::distance (
			given_group.subjects.begin(),
			subject_k
		);

	if ( 
		( remaining_lessons [group_subject_number] > 0 
		) && ( 
			(
				assigned_teachers [group_subject_number] == -1
			) || (
				assigned_teachers [group_subject_number] == given_color.teacher.id
			)
		) 
	) {

		return true;
			
	}

	return false;

}

bool slimak::TimetableGenerator::consistent (
	TimetableColor given_color,
	std::vector< TimetableConstraint * > given_constraints
) {

	for ( std::vector< TimetableConstraint * >::iterator constraint_i = 
		given_constraints.begin();
		constraint_i != given_constraints.end();
		++constraint_i ) {

		if ( !(*constraint_i)->consistentWith( given_color ) )
			return false;

	}

	return true;

}


bool slimak::TimetableGenerator::fitsTeacher (
	slimak::TimetableColor given_color,
	int given_day, int given_slot
) {
	slimak::TimetableTeacher color_teacher = given_color.teacher;

	if ( color_teacher.slots[ given_day ].size() == 0 )
		return false;

	if ( 
		std::find ( 
			color_teacher.slots[ given_day ].begin(),
			color_teacher.slots[ given_day ].end(),
			given_slot

		) != color_teacher.slots[ given_day ].end()
	) {
		return true;
	} else
		return false;
}


void slimak::TimetableGenerator::resetPlan( int given_group_id ) {

	//TODO:
	// When resetting plan, recover freed colors, selecting them
	// from global_domain and adding back to slots_domains.

	groups_timetables[ given_group_id ] = slimak::TimetablePlan();
	std::map< int, slimak::TimetableColor > empty_day;

	for (int slot = 0; slot < number_of_slots; ++slot) {
		empty_day[ slot ] = slimak::TimetableColor(false);
	}

	for (int day = 0; day < number_of_days; ++ day) {
		std::map< int, slimak::TimetableColor > new_day (
			empty_day.begin(), empty_day.end()
		);
		groups_timetables[ given_group_id ].slots[ day ] = new_day;
	}

}


slimak::TimetablePlanDomains
slimak::TimetableGenerator::generateSlotsDomains (
	std::vector< TimetableConstraint * > given_constraints
) {
	
	slimak::TimetablePlanDomains result_domains;
	std::cerr << "[CSP] Generating slots domains..." << std::endl;

	for (int day = 0; day < number_of_days; ++day ) {
	for (int slot = 0; slot < number_of_slots; ++slot) {
		std::cerr << "[CSP] - Day " << day << ", slot " << slot << ": " << std::endl;
		
		std::vector< slimak::TimetableColor > current_slot_domain;

		for (int i = 0; i < global_domain.size(); ++i) {
			std::cerr << "[CSP] - - Color " << i; 

			slimak::TimetableColor color_i = global_domain[i];
			std::cerr << " (" << color_i.teacher.id << "," << color_i.subject.id
			<< "," << color_i.classroom.id << ")";

			if ( fitsTeacher( color_i, day, slot ) ) {

				for ( std::vector< TimetableConstraint * >::iterator constraint_j = 
					given_constraints.begin();
					constraint_j != given_constraints.end();
					++constraint_j ) {

					if ( (*constraint_j)->consistentWith( color_i ) )
						current_slot_domain.push_back( color_i );
					else
						std::cerr << " [DELETED] [conflict with constraint]";

				}

			} else {
				std::cerr << " [DELETED] [not fits teacher]";
			}

			std::cerr << std::endl;

		}

		result_domains.colors[ day ][ slot ] = current_slot_domain;

	}
	}

	return result_domains;

}
