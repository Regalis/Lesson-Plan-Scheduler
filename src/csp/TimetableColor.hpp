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

/**
 * @file 	csp/TimetableColor.hpp
 * @brief	Tridimensional color of a vertex in the Graph
 * @date	2013-06-13
 * @authors	Konrad Talik <konradtalik@gmail.com>
 * @copyright	GNU General Public License v3.
 */

#ifndef __TIMETABLE_COLOR_HPP__
#define __TIMETABLE_COLOR_HPP__

#include "CSPColor.hpp"

namespace slimak {

	/**
	 * @brief	Tridimensional color of a vertex in the Graph
	 * @author	Konrad Talik <konradtalik@gmail.com>
	 *
	 */
	class TimetableColor : public CSPColor {

		public:

			/* CONSTRUCTORS */

			/// Construct a TimetableColor with given number of attributes (dimensions)
			TimetableColor(size_t given_attributes_number);

			/// Construct a TimetableColor with given concrete attributes (or attribute)
			TimetableColor(std::vector< slimak::CSPAttribute > given_attributes);
			
			virtual std::vector< slimak::TimetableColor >
			generateDomain(std::vector< std::vector< slimak::CSPAttribute > > given_attributes);
		
		protected:

			std::vector< slimak::CSPAttribute > attributes;

	};

}

#endif
