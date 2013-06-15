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

#include "TimetableConstraint.hpp"
#include <algorithm>

slimak::TimetableConstraint::TimetableConstraint() {};

slimak::TimetableConstraint::~TimetableConstraint() {};

slimak::TimetableConstraint::TimetableConstraint (
	std::vector< int > given_teachers,
	std::vector< int > given_subjects,
	std::vector< int > given_classrooms,
	std::vector< std::vector< int > > given_slots,
	std::vector< int > given_additional_args
	) {
		teachers = given_teachers;
		subjects = given_subjects;
		classrooms = given_classrooms;
		slots = given_slots;
		additional_args = given_additional_args;
}

bool slimak::TimetableConstraint::consistentWith( slimak::TimetableColor given_color ) {
	return true;
}

bool slimak::TimetableConstraint::consistentWith( int day, int slot ) {
	return true;
}


bool slimak::TimetableConstraint::relatesToTeacher( int given_teacher_id ) {
	if ( std::find( this->teachers.begin(), this->teachers.end(), given_teacher_id ) 
		!= this->teachers.end())
			return true;
	else
			return false;
}

bool slimak::TimetableConstraint::relatesToSubject( int given_subject_id ) {
	if ( std::find( this->subjects.begin(), this->subjects.end(), given_subject_id ) 
		!= this->subjects.end())
			return true;
	else
			return false;
}

bool slimak::TimetableConstraint::relatesToClassroom( int given_classroom_id ) {
	if ( std::find( this->classrooms.begin(), this->classrooms.end(), given_classroom_id ) 
		!= this->classrooms.end())
			return true;
	else
			return false;
}

bool slimak::TimetableConstraint::relatesToSlot( int day, int slot ) {
	if ( slots.size() > day ) {
		if ( std::find( this->slots[day].begin(), this->slots[day].end(), slot ) 
			!= this->slots[day].end())
				return true;
		else
				return false;
	} else {
		return false;
	}
}

bool slimak::TimetableConstraint::hasAdditionalArg( int given_additional_arg ) {
	if ( std::find( this->additional_args.begin(), this->additional_args.end(), given_additional_arg )
		!= this->additional_args.end())
			return true;
	else
			return false;
}
