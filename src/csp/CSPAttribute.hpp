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
 * @file 	csp/CSPAttribute.hpp
 * @brief	Abstract component of multidimensional CSPColor
 * @date	2013-06-12
 * @authors	Konrad Talik <konradtalik@gmail.com>
 * @copyright	GNU General Public License v3.
 */

#ifndef __CSP_ATTRIBUTE_HPP__
#define __CSP_ATTRIBUTE_HPP__

#include <ostream>

namespace slimak {

	/**
	 * @brief	Abstract component of multidimensional CSPColor
	 * @author	Konrad Talik <konradtalik@gmail.com>
	 *
	 * CSPAttribute object is a component of existing CSPColor object.
	 * For example: we want to color our graph of timeline, where every vertex
	 * is a single (day, hour) point. Let's say we want to color vertices with
	 * three-dimensional colors (school_subject, teacher, classroom).
	 * In this example school_subject, teacher and classroom are CSPAttributes.
	 *
	 */
	class CSPAttribute {

		public:

			/* DEFAULT CONSTRUCTOR */
			CSPAttribute();
			
			/** @name Properties methods */
			///@{
			/** *Property method* */

			/// True if this container is empty
			bool isEmpty(); 

			///@}

			/** @name Operators */
			///@{
			/** *Operator* */

			/// Assign content
			virtual CSPAttribute& operator= (const CSPAttribute &other);
			/// Comparision
			virtual bool operator== (const CSPAttribute &other);
		
			///@}

		protected:

			bool empty;
		
	};

}

std::ostream& operator<<(std::ostream& output, const slimak::CSPAttribute source);

#endif
