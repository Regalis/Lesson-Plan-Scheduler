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
 * @file 	csp/TimetableGenerator.hpp
 * @brief	Timetable generating class
 * @date	2013-06-14
 * @authors	Konrad Talik <konradtalik@gmail.com>
 * @copyright	GNU General Public License v3.
 */

#ifndef __TIMETABLE_GENERATOR_HPP__
#define __TIMETABLE_GENERATOR_HPP__

#include "CSP.hpp"
#include "TimetableColor.hpp"
#include "TimetableConstraints.hpp"

namespace slimak {

	class TimetableGenerator {
		
		public:
			
			TimetableGenerator (
				int given_number_of_days,
				int given_number_of_slots,
				std::map< int, TimetableGroup > given_groups,
				std::map< int, TimetableTeacher > given_teachers,
				std::map< int, TimetableSubject > given_subjects,
				std::map< int, TimetableClassroom > given_classrooms,
				std::vector< TimetableConstraint * > given_constraints
			);

			std::vector< TimetableColor > generateGlobalDomain (
				std::map< int, TimetableTeacher > given_teachers,
				std::map< int, TimetableSubject > given_subjects,
				std::map< int, TimetableClassroom > given_classrooms,
				std::vector< TimetableConstraint * > given_constraints
			);

			/// Generates new lesson plan for **given_group_id**.
			/* This method removes current version of plan of given_group_id
			 * and replaces it with newly generated plan.
			 */
			slimak::TimetablePlan generateForGroup ( 
				int given_group_id,
				std::map< int, TimetableTeacher > given_teachers,
				std::map< int, TimetableSubject > given_subjects,
				std::map< int, TimetableClassroom > given_classrooms,
				std::vector< TimetableConstraint * > given_constraints
			);

			bool consistent (
				slimak::TimetableColor given_color,
				std::vector< slimak::TimetableConstraint * > given_constraints
			);

			bool fitsTeacher (
				slimak::TimetableColor given_color,
				int given_day, int given_slot
			);

		protected:

			int number_of_days;
			int number_of_slots;
			std::vector< slimak::TimetableColor > global_domain;
			slimak::TimetablePlanDomains slots_domains;
			std::map< int, slimak::TimetablePlan > groups_timetables;
			std::map< int, slimak::TimetablePlan > teachers_timetables;

			void resetPlan( int given_group_id );
			slimak::TimetablePlanDomains generateSlotsDomains (
				std::vector< TimetableConstraint * > given_constraints
			);


	};
}

#endif
