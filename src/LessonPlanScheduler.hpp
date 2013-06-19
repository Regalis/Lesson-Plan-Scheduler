/*
 *
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
 *  -> Patryk Jaworski <regalis@regalis.com.pl>
 *
 */

/**
 * @file LessonPlanScheduler.hpp
 * @brief Main program class
 * @date 2013-05-21
 * @authors Patryk Jaworski <regalis@regalis.com.pl>
 * @copyright GNU General Public License v3.
 */

#ifndef __LESSON_PLAN_SCHEDULER_HPP__
#define __LESSON_PLAN_SCHEDULER_HPP__

class MainWindow;
class ClassroomsProps;

/** Main program class
 *
 * Signleton class, contain configuration, database instances.
 */
class LessonPlanScheduler {
	public:
		/** Get class instance */
		static LessonPlanScheduler *get();

		/** Execute program
		 * Function will initialize db connections, read/write configuration
		 * file and decide which widget to display (Wizard or MainWindow)
		 */
		void exec();
	protected:
		MainWindow *main_window;
		ClassroomsProps *classrooms_props;
		LessonPlanScheduler();
		LessonPlanScheduler(const LessonPlanScheduler&);
		LessonPlanScheduler operator=(const LessonPlanScheduler&);
};

#endif
