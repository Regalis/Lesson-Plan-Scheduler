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

#include "TimetableConstraints.hpp"
#include <iostream>

slimak::TimetableConstraint00::TimetableConstraint00() {};

slimak::TimetableConstraint00::~TimetableConstraint00() {};

slimak::TimetableConstraint00::TimetableConstraint00 (
	std::vector< int > given_teachers, std::vector< int > given_classrooms
) : TimetableConstraint (
	given_teachers,
	std::vector< int > (0),
	given_classrooms,
	std::vector< std::vector< int > > (7, std::vector< int > (0) ),
	std::vector< int > (0)
) { };

bool slimak::TimetableConstraint00::consistentWith( slimak::TimetableColor given_color ) {

	// Related with this teacher
	if ( relatesToTeacher( given_color.teacher.id ) ) {
		// This is the required classroom
		if( relatesToClassroom( given_color.classroom.id ) ) {
			return true;
		} else {
			return false;
		}
	}

	// Not related.
	return true;

}

bool slimak::TimetableConstraint00::consistentWith( int day, int slot ) {
	return true;
}
