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

slimak::TimetableGenerator::TimetableGenerator (
	int number_of_days,
	int number_of_slots,
	std::map< int, TimetableGroup > given_groups,
	std::map< int, TimetableTeacher > given_teachers,
	std::map< int, TimetableSubject > given_subjects,
	std::map< int, TimetableClassroom > given_classrooms,
	std::vector< TimetableConstraint * > given_constraints
) {

	std::vector< slimak::TimetableColor > global_domain;
	global_domain = generateGlobalDomain (
		given_teachers, given_subjects, given_classrooms, given_constraints
	);

	std::cerr << "[CSP] Domain generation results:" << std::endl;
	std::cerr << "[CSP] <teacher> <subject> <classroom>" << std::endl;
	for ( std::vector< TimetableColor >::iterator it = global_domain.begin();
		it != global_domain.end(); ++it ) {
		std::cerr << "[CSP] " << it->teacher.id << ' ' << it->subject.id << ' ' << it->classroom.id << std::endl;
	}

	std::map<
		int, std::map< 
			int, std::map<
				int, slimak::TimetableColor
			>
		>
	> groups_timetables;

	std::map<
		int, std::map< 
			int, std::map<
				int, slimak::TimetableColor
			>
		>
	> teachers_timetables;

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

bool slimak::TimetableGenerator::consistent (
	TimetableColor given_color,
	std::vector< TimetableConstraint * > given_constraints
) {

	for ( std::vector< TimetableConstraint * >::iterator constraint_i = given_constraints.begin();
		constraint_i != given_constraints.end(); ++constraint_i ) {

		if ( !(*constraint_i)->consistentWith( given_color ) )
			return false;

	}

	return true;

}
