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

#include "CSPAttribute.hpp"

slimak::CSPAttribute::CSPAttribute() {
	empty = true;
}

bool slimak::CSPAttribute::isEmpty() { 
	return empty;
}

slimak::CSPAttribute& slimak::CSPAttribute::operator= (const slimak::CSPAttribute &other) {
	this->empty = false;
}

bool slimak::CSPAttribute::operator== (const slimak::CSPAttribute &other) {
	if (this->empty == other.empty) {
		return true;
	} else {
		return false;
	}
}

std::ostream& operator<<(std::ostream& output, const slimak::CSPAttribute source) {
	output << (int)0;
	return output;
}

