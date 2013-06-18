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

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QComboBox>
#include <QAbstractItemModel>
#include <QTableView>
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QStandardItemModel>
#include <QGroupBox>
#include <QInputDialog>

#include "ClassroomsProps.hpp"

ClassroomsProps::ClassroomsProps(QWidget *parent) : QWidget(parent) {
	classrooms_id = 0;
	initUI();
}

void ClassroomsProps::initUI() {
	QHBoxLayout *layout = new QHBoxLayout();	
	QVBoxLayout *left_layout = new QVBoxLayout();
	QVBoxLayout *right_layout = new QVBoxLayout();
	QHBoxLayout *top_left_layout = new QHBoxLayout();
	QHBoxLayout *top_right_layout = new QHBoxLayout();

	QGroupBox *classrooms_group = new QGroupBox(tr("Classrooms"));
	QGroupBox *props_group = new QGroupBox(tr("Props"));

	/* left side initialization */
	classroom_select = new QComboBox();
	classroom_select->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	top_left_layout->addWidget(new QLabel(tr("Classroom select:")));
	top_left_layout->addWidget(classroom_select);
	QPushButton *new_classroom = new QPushButton(QIcon::fromTheme("list-add"), tr("add"));
	QPushButton *remove_classroom = new QPushButton(QIcon::fromTheme("list-remove"), tr("remove"));
	new_classroom->setStatusTip(tr("Add new classroom"));
	remove_classroom->setStatusTip(tr("Remove selected classroom"));

	connect(new_classroom, SIGNAL(clicked()), this, SLOT(addClassroom()));
	connect(remove_classroom, SIGNAL(clicked()), this, SLOT(removeClassroom()));

	top_left_layout->addWidget(new_classroom);
	top_left_layout->addWidget(remove_classroom);

	classroom_table = new QTableView();
	classroom_model = new QStandardItemModel(1, 2, 0);
	classroom_model->setHeaderData(0, Qt::Horizontal, tr("Name"));
	classroom_model->setHeaderData(1, Qt::Horizontal, tr("Amount"));
	classroom_table->setModel(classroom_model);
	classroom_table->resizeColumnsToContents();	

	left_layout->addLayout(top_left_layout);
	left_layout->addWidget(classroom_table);

	/* right side initialization */
	QPushButton *new_prop = new QPushButton(QIcon::fromTheme("list-add"), tr("add"));
	QPushButton *remove_prop = new QPushButton(QIcon::fromTheme("list-remove"), tr("remove"));
	new_prop->setStatusTip(tr("Add new prop"));
	remove_prop->setStatusTip(tr("Remove prop"));

	props_table = new QTableView();
	
	top_right_layout->addStretch();
	top_right_layout->addWidget(new_prop);
	top_right_layout->addWidget(remove_prop);
	top_right_layout->addStretch();

	right_layout->addLayout(top_right_layout);
	right_layout->addWidget(props_table);

	classrooms_group->setLayout(left_layout);
	props_group->setLayout(right_layout);
	layout->addWidget(classrooms_group);
	layout->addWidget(props_group);

	setLayout(layout);
}

void ClassroomsProps::addClassroom() {
	bool ok = false;
	while (1) {
		QString class_name = QInputDialog::getText(this, tr("New classroom"), tr("Enter classroom name:"), QLineEdit::Normal, "", &ok); 
		if (ok && !class_name.isEmpty()) {
			classroom_select->addItem(class_name, QVariant(classrooms_id++));
			break;
		}
	}
}

void ClassroomsProps::removeClassroom() {
	if (classroom_select->count() != 0) {
		classroom_select->removeItem(classroom_select->currentIndex());
	}
}
