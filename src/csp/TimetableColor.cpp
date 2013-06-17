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

#include "TimetableColor.hpp"

slimak::TimetableColor::TimetableColor() {
	empty = true;
	blank = false;
}

slimak::TimetableColor::TimetableColor(bool if_blank) {
	if (if_blank) {
		blank = true;
		empty = false;
	} else {
		blank = false;
		empty = true;
	}
}

slimak::TimetableColor::TimetableColor(size_t given_attributes_number) :
CSPColor( given_attributes_number ) {
	empty = true;
	blank = false;
}

slimak::TimetableColor::TimetableColor(std::vector< slimak::CSPAttribute > given_attributes) :
CSPColor( given_attributes ) {
	empty = false;
	blank = false;
}

slimak::TimetableColor::TimetableColor (
	slimak::TimetableTeacher given_teacher,
	slimak::TimetableSubject given_subject,
	slimak::TimetableClassroom given_classroom
) {
	empty = false;
	blank = false;
	teacher = given_teacher;
	subject = given_subject;
	classroom = given_classroom;
}

void slimak::TimetableColor::setAttributes (
	slimak::TimetableTeacher given_teacher,
	slimak::TimetableSubject given_subject,
	slimak::TimetableClassroom given_classroom
) {
	empty = false;
	blank = false;
	teacher = given_teacher;
	subject = given_subject;
	classroom = given_classroom;
}

bool slimak::TimetableColor::isEmpty() {
	return empty;
}

bool slimak::TimetableColor::isBlank() {
	return blank;
}
