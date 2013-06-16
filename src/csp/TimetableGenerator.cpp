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
	int given_group_id,
	std::map< int, TimetableTeacher > given_teachers,
	std::map< int, TimetableSubject > given_subjects,
	std::map< int, TimetableClassroom > given_classrooms,
	std::vector< TimetableConstraint * > given_constraints
) {
	resetPlan( given_group_id );

	return groups_timetables[ given_group_id ];

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

	groups_timetables[ given_group_id ] = slimak::TimetablePlan();
	std::map< int, slimak::TimetableColor > empty_day;

	for (int slot = 0; slot < number_of_slots; ++slot) {
		empty_day[ slot ] = slimak::TimetableColor(3);
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
