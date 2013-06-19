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
 * @file MainWindow.hpp
 * @brief Main user window
 * @date 2013-05-21
 * @authors Patryk Jaworski <regalis@regalis.com.pl>
 * @copyright GNU General Public License v3.
 */

#ifndef __MAIN_WINDOW_HPP__
#define __MAIN_WINDOW_HPP__

#include <QMainWindow>
#include <QObject>

class QStackedWidget;
class QAction;
class ClassroomsProps;
class Subjects;
class Teachers;
class Groups;

/** Main window class, contain all widgets
 *
 * Window with menu, toolbar and main widget. Main widget is
 * selected by user via. "View" menu.
 */
class MainWindow : public QMainWindow {
	Q_OBJECT;

	public:
		MainWindow();
	protected:
		QStackedWidget *stack;
		ClassroomsProps *classroomsprops;
		Subjects *subjects;
		Teachers *teachers;
		Groups *groups;

		/** Initialize user interface
		 *
		 * Build menu, toolbars and main widgets
		 */
		void initUI();
	protected slots:
		/** Update main widget
		 *
		 * Display selected main widget
		 *
		 * @param action menu action (must contain widget id)
		 */
		void selectView(QAction *action);
};

#endif
