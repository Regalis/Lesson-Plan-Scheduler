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

#include <QApplication>
#include <QMenu>
#include <QAction>
#include <QActionGroup>
#include <QMenuBar>
#include <QStackedWidget>

#include "MainWindow.hpp"
#include "ClassroomsProps.hpp"
#include "Subjects.hpp"
#include "Teachers.hpp"
#include "Groups.hpp"

MainWindow::MainWindow() : QMainWindow(0) {
	// TODO: initialize main window
	stack = new QStackedWidget(0);
	classroomsprops = new ClassroomsProps(0);
	subjects = new Subjects(0);
	teachers = new Teachers(0);
	groups = new Groups(0);
	initUI();
}

void MainWindow::initUI() {
	QAction *new_database = new QAction(tr("&New database"), this);
	QAction *quit = new QAction(tr("&Quit"), this);
	QMenu *file = menuBar()->addMenu(tr("&File"));
	file->addAction(new_database);
	file->addSeparator();
	file->addAction(quit);
	connect(quit, SIGNAL(triggered()), qApp, SLOT(quit()));

	QMenu *view = menuBar()->addMenu(tr("&View"));
	QActionGroup *view_group = new QActionGroup(0);
	connect(view_group, SIGNAL(triggered(QAction*)), this, SLOT(selectView(QAction*)));

	QAction *classrooms_action = view_group->addAction(tr("&Classrooms"));
	classrooms_action->setData(0);
	classrooms_action->setCheckable(true);
	classrooms_action->setChecked(true);
	QAction *subjects_action = view_group->addAction(tr("&Subjects"));
	subjects_action->setData(1);
	subjects_action->setCheckable(true);
	QAction *teachers_action = view_group->addAction(tr("&Teachers"));
	teachers_action->setCheckable(true);
	teachers_action->setData(2);
	QAction *groups_action = view_group->addAction(tr("&Groups"));
	groups_action->setCheckable(true);
	groups_action->setData(3);

	view->addAction(classrooms_action);
	view->addAction(subjects_action);
	view->addAction(teachers_action);
	view->addAction(groups_action);

	stack->addWidget(classroomsprops);
	stack->addWidget(subjects);
	stack->addWidget(teachers);
	stack->addWidget(groups);
	
	setCentralWidget(stack);
}

void MainWindow::selectView(QAction *action) {
	stack->setCurrentIndex(action->data().toInt());
}
