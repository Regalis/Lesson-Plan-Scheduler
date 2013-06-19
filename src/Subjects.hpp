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
 * @file Subjects.hpp
 * @brief Subjects edit form
 * @date 2013-06-18
 * @authors Patryk Jaworski <regalis@regalis.com.pl>
 * @copyright GNU General Public License v3.
 */

#ifndef __SUBJECTS_HPP__
#define __SUBJECTS_HPP__

#include <QWidget>
#include <QObject>

class QComboBox;
class QAbstractItemModel;
class QTableView;


/** Subjects widget */
class Subjects : public QWidget {
	Q_OBJECT;

	public:
		Subjects(QWidget *parent = 0);
	protected:
		QAbstractItemModel *subjects_model;
		QTableView *subjects_table;

		/** Initialize user interface
		 *
		 * Build tables, models and layouts
		 */
		void initUI();
	protected slots:
		void addSubject();
		void removeSubject();
};

#endif
