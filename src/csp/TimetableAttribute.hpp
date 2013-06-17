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
 * @file 	csp/TimetableAttribute.hpp
 * @brief	Component of tridimensional TimetableColor
 * @date	2013-06-13
 * @authors	Konrad Talik <konradtalik@gmail.com>
 * @copyright	GNU General Public License v3.
 */

#ifndef __TIMETABLE_ATTRIBUTE_HPP__
#define __TIMETABLE_ATTRIBUTE_HPP__

#include <string>
#include "CSPAttribute.hpp"

namespace slimak {

	/**
	 * @brief	Component of tridimensional TimetableColor
	 * @author	Konrad Talik <konradtalik@gmail.com>
	 *
	 */
	class TimetableAttribute : public CSPAttribute {

		public:

			/* CONSTRUCTORS */
			
			/// Construct an empty TimetableAttribute
			TimetableAttribute();
			
			/// Construct TimetableAttribute from given Id
			/**
			 * @param given_id
			 *	This parameter refers to **Id** of an attribute-related object in database.
			 */
			TimetableAttribute(long given_id);
			
			/** @name Operators */
			///@{
			/** *Operator* */

			/// Assign content
			virtual TimetableAttribute& operator= (const TimetableAttribute &other);
			/// Comparision
			virtual bool operator== (const TimetableAttribute &other);
			/// Long conversion
			operator long () const;
		
			///@}

		protected:

			long attribute_id;
		
	};

}

std::ostream& operator<<(std::ostream& output, const slimak::TimetableAttribute source);

#endif
