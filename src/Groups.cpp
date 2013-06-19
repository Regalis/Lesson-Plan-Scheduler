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
#include <QItemSelectionModel>
#include <QModelIndex>
#include <QHeaderView>
//#include <QList>

#include "Groups.hpp"

Groups::Groups(QWidget *parent) : QWidget(parent) {
	initUI();
}

void Groups::initUI() {
	QVBoxLayout *layout = new QVBoxLayout();	
	QVBoxLayout *groups_layout = new QVBoxLayout();
	QHBoxLayout *groups_top_layout = new QHBoxLayout();
	QVBoxLayout *subjects_layout = new QVBoxLayout();	
	QHBoxLayout *subjects_top_layout = new QHBoxLayout();	

	QGroupBox *groups_group = new QGroupBox(tr("Groups"));
	QGroupBox *subjects_group = new QGroupBox(tr("Subjects"));

	groups_model= new QStandardItemModel(0, 4);
	subjects_model = new QStandardItemModel(0, 1);

	groups_table = new QTableView();
	subjects_table = new QTableView();

	/* groups table initialization */

	add_group = new QPushButton(QIcon::fromTheme("list-add"), tr("add"));
	remove_group = new QPushButton(QIcon::fromTheme("list-remove"), tr("remove"));

	connect(add_group, SIGNAL(clicked()), this, SLOT(addGroup()));
	connect(remove_group, SIGNAL(clicked()), this, SLOT(removeGroup()));

	groups_top_layout->addWidget(add_group);
	groups_top_layout->addWidget(remove_group);

	groups_model->setHeaderData(0, Qt::Horizontal, tr("Group name"));
	groups_model->setHeaderData(1, Qt::Horizontal, tr("Turor name"));
	groups_model->setHeaderData(2, Qt::Horizontal, tr("Turor surname"));
	groups_model->setHeaderData(3, Qt::Horizontal, tr("Members number"));
	groups_table->setModel(groups_model);
	groups_table->resizeColumnsToContents();	
	groups_table->horizontalHeader()->setStretchLastSection(true);

	groups_table->setSelectionBehavior(QAbstractItemView::SelectRows);
	groups_table->setSelectionMode(QAbstractItemView::SingleSelection);

	QItemSelectionModel *selection_model = groups_table->selectionModel();	
	connect(selection_model, SIGNAL(currentRowChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(groupSelected(const QModelIndex &, const QModelIndex &)));

	groups_layout->addLayout(groups_top_layout);
	groups_layout->addWidget(groups_table);

	/* subjects table initialization */

	add_subject = new QPushButton(QIcon::fromTheme("list-add"), tr("add"));
	remove_subject = new QPushButton(QIcon::fromTheme("list-remove"), tr("remove"));

	connect(add_subject, SIGNAL(clicked()), this, SLOT(addSubject()));
	connect(remove_subject, SIGNAL(clicked()), this, SLOT(removeSubject()));

	subjects_top_layout->addWidget(add_subject);
	subjects_top_layout->addWidget(remove_subject);

	subjects_model->setHeaderData(0, Qt::Horizontal, tr("Subject name"));
	subjects_table->setModel(subjects_model);
	subjects_table->resizeColumnsToContents();	
	subjects_table->horizontalHeader()->setStretchLastSection(true);

	subjects_table->setSelectionBehavior(QAbstractItemView::SelectRows);
	subjects_table->setSelectionMode(QAbstractItemView::SingleSelection);

	subjects_layout->addLayout(subjects_top_layout);
	subjects_layout->addWidget(subjects_table);

	
	groups_group->setLayout(groups_layout);
	subjects_group->setLayout(subjects_layout);

	layout->addWidget(groups_group);
	layout->addWidget(subjects_group);

	setLayout(layout);
}

void Groups::addGroup() {
	groups_model->insertRow(0);
}

void Groups::removeGroup() {
	QItemSelectionModel *selection_model = groups_table->selectionModel();	
	if (selection_model->selectedRows().count() != 0) {
		groups_model->removeRow(selection_model->selectedRows().at(0).row());
	}
}

void Groups::addSubject() {
	subjects_model->insertRow(0);
}

void Groups::removeSubject() {
	QItemSelectionModel *selection_model = subjects_table->selectionModel();	
	if (selection_model->selectedRows().count() != 0) {
		subjects_model->removeRow(selection_model->selectedRows().at(0).row());
	}
}

void Groups::groupSelected(const QModelIndex &current, const QModelIndex &previous) {
	
}
