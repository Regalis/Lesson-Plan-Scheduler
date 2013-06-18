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

#include "TimetableAttribute.hpp"

slimak::TimetableAttribute::TimetableAttribute() : CSPAttribute() {
	attribute_id = -1;
}
			
slimak::TimetableAttribute::TimetableAttribute(long given_id) {
	attribute_id = given_id;
}			

slimak::TimetableAttribute& slimak::TimetableAttribute::operator= (const slimak::TimetableAttribute &other) {
		this->attribute_id = other.attribute_id;
}

bool slimak::TimetableAttribute::operator== (const slimak::TimetableAttribute &other) {
	if (this->attribute_id == other.attribute_id) {
		return true;
	} else {
		return false;
	}
}

slimak::TimetableAttribute::operator long () const {
	return attribute_id;
}

std::ostream& operator<<(std::ostream& output, const slimak::TimetableAttribute source) {
	const long result = (long)source;
	output << result;
	return output;
}

