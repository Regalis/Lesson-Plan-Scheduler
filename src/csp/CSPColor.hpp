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
 * @file 	csp/CSPColor.hpp
 * @brief	Multidimensional color of a vertex in the Graph
 * @date	2013-06-13
 * @authors	Konrad Talik <konradtalik@gmail.com>
 * @copyright	GNU General Public License v3.
 */

#ifndef __CSP_COLOR_HPP__
#define __CSP_COLOR_HPP__

#include <vector>
#include "CSPAttribute.hpp"

namespace slimak {

	/**
	 * @brief	Multidimensional color of a vertex in the Graph
	 * @author	Konrad Talik <konradtalik@gmail.com>
	 *
	 */
	class CSPColor {

		public:

			/* CONSTRUCTORS */

			/// Construct empty CSPColor
			CSPColor();

			/// Construct a CSPColor with given number of attributes (dimensions)
			CSPColor(size_t given_attributes_number);

			/// Construct a CSPColor with given concrete attributes (or attribute)
			CSPColor(std::vector< slimak::CSPAttribute > given_attributes);
			
			virtual std::vector< slimak::CSPColor >
			generateDomain(std::vector< std::vector< slimak::CSPAttribute > > given_attributes);
		
		protected:

			std::vector< slimak::CSPAttribute > attributes;

	};

}

#endif
