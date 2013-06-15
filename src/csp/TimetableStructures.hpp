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
 * @file 	csp/TimetableStructures.hpp
 * @brief	Timetable generating class
 * @date	2013-06-14
 * @authors	Konrad Talik <konradtalik@gmail.com>
 * @copyright	GNU General Public License v3.
 */

#ifndef __TIMETABLE_STRUCTURES_HPP__
#define __TIMETABLE_STRUCTURES_HPP__

#include <vector>

namespace slimak {

	struct TimetableClassroom {
		int id;
		int capacity;

	};

	struct TimetableSubject {
		int id;
		int fatigue_level;
		std::vector< int > classrooms;
		//std::vector< int > teachers;
	};
	
	struct TimetableTeacher {
		int id;
		int max_slots;
		std::vector< std::vector< int > > slots;
		std::vector< int > subjects;
	};

	struct TimetableGroup {
		int id;
		int teacher_id;
		std::vector< int > subjects;

	};
	
}

#endif
