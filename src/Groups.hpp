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
 *  -> Ariana Las <ariana.las@gmail.com>
 *
 */
 
/**
 * @file Groupss.hpp
 * @brief Groups widget
 * @date 2013-05-23
 * @authors Ariana Las <ariana.las@gmail.com>
 * @copyright GNU General Public License v3.
 */

#ifndef __GROUPS_HPP__
#define __GROUPS_HPP__

#include <QWidget>
#include <QObject>

class QStandardItemModel;
class QTableView;
class QPushButton;

/** Groups widget */
class Groups : public QWidget {
	Q_OBJECT;
	
	public:
		Groups(QWidget *parent = 0);

	protected:
		/** Initialize user interface
		 *
		 * Build group boxes, tables, layouts and models
		 */
		void initUI();
		QPushButton *add_group;
		QPushButton *remove_group;
		QPushButton *add_subject;
		QPushButton *remove_subject;
		QStandardItemModel *groups_model;
		QTableView *groups_table;
		QStandardItemModel *subjects_model;
		QTableView *subjects_table;

	protected slots:
		/** Add new group to table
		 *
		 * Display input dialog and add group
		 */
		void addGroup();

		/** Remove selected group from table */
		void removeGroup();

		/** Add new subject to table
		 *
		 * Display input dialog and add subject
		 */
		void addSubject();

		/** Remove selected subject from table */
		void removeSubject();

		/** Update subjects table while the group is selected */
		void groupSelected(const QModelIndex &current, const QModelIndex &previous);
};

#endif
