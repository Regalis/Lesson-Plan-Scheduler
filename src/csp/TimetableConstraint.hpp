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
 * Contributors:
 *  -> Konrad Talik <konradtalik@gmail.com>
 *
 */

/**
 * @file 	csp/TimetableConstraint.hpp
 * @brief	Timetable constraints class
 * @date	2013-06-14
 * @authors	Konrad Talik <konradtalik@gmail.com>
 * @copyright	GNU General Public License v3.
 */

#ifndef __TIMETABLE_CONSTRAINT_HPP__
#define __TIMETABLE_CONSTRAINT_HPP__

#include "CSP.hpp"
#include "TimetableColor.hpp"
#include "TimetableStructures.hpp"

namespace slimak {

	class TimetableConstraint {
		
		public:
			
			std::vector< int > teachers;
			std::vector< int > subjects;
			std::vector< int > classrooms;
			std::vector< std::vector< int > > slots;
			std::vector< int > additional_args;

			TimetableConstraint();
			virtual ~TimetableConstraint();

			// Construct TimetableConstraint
			/**
			 * @param	given_slots
			 * 	Must have all 7 days of week (even if they are empty).
			 * 	Every non-empty day of week must contain numbers of slots,
			 * 	which are in relation of this constraint.
			 * 	(They don't need to be sorted)
			 */
			TimetableConstraint (
				std::vector< int > given_teachers,
				std::vector< int > given_subjects,
				std::vector< int > given_classrooms,
				std::vector< std::vector< int > > given_slots,
				std::vector< int > given_additional_args
			);

			virtual bool consistentWith( slimak::TimetableColor given_color );
			virtual bool consistentWith( int day, int slot );
			bool relatesToTeacher( int given_teacher_id );
			bool relatesToSubject( int given_subject_id );
			bool relatesToClassroom( int given_classroom_id );
			bool relatesToSlot( int day, int slot );
			bool hasAdditionalArg( int given_additional_arg );

	};

}

#endif
