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
 * @file ClassroomsProps.hpp
 * @brief Classrooms and props widget
 * @date 2013-05-21
 * @authors Patryk Jaworski <regalis@regalis.com.pl>
 * @copyright GNU General Public License v3.
 */

#ifndef __CLASSROOMS_PROPS_HPP__
#define __CLASSROOMS_PROPS_HPP__

#include <QWidget>
#include <QObject>

class QComboBox;
class QAbstractItemModel;
class QTableView;

/** Classrooms and Props widget */
class ClassroomsProps : public QWidget {
	Q_OBJECT;

	public:
		ClassroomsProps(QWidget *parent = 0);
	protected:
		int classrooms_id;
		QComboBox *classroom_select;
		QAbstractItemModel *classroom_model;
		QTableView *classroom_table;
		QAbstractItemModel *props_model;
		QTableView *props_table;

		/** Initialize user interface
		 *
		 * Build group boxes, tables, layouts and models
		 */
		void initUI();
	protected slots:
		
		/** Add new clasroom to combo box
		 *
		 * Display input dialog and add classroom
		 */
		void addClassroom();

		/** Remove selected classroom from combo box */
		void removeClassroom();
};

#endif
