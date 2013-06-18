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

#include <QTableView>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStandardItemModel>
#include <QPushButton>
#include <QHeaderView>
#include <QAbstractItemView>
#include <QItemSelectionModel>

#include "Subjects.hpp"

Subjects::Subjects(QWidget *parent) : QWidget(parent) {
	initUI();
}

void Subjects::initUI() {
	QVBoxLayout *vbox = new QVBoxLayout(0);	
	QHBoxLayout *buttons_box = new QHBoxLayout(0);
	
	QPushButton *new_subject = new QPushButton(tr("&New subject"));
	QPushButton *remove_subject = new QPushButton(tr("&Remove"));

	connect(new_subject, SIGNAL(clicked()), this, SLOT(addSubject()));
	connect(remove_subject, SIGNAL(clicked()), this, SLOT(removeSubject()));

	buttons_box->addStretch();
	buttons_box->addWidget(new_subject);
	buttons_box->addWidget(remove_subject);
	buttons_box->addStretch();

	subjects_model = new QStandardItemModel(0, 3, 0);
	subjects_table = new QTableView();
	subjects_table->setSelectionBehavior(QAbstractItemView::SelectRows);
	subjects_table->setSelectionMode(QAbstractItemView::SingleSelection);
	subjects_table->horizontalHeader()->setStretchLastSection(true);

	subjects_model->setHeaderData(0, Qt::Horizontal, tr("Name"));
	subjects_model->setHeaderData(1, Qt::Horizontal, tr("Fatigue level"));
	subjects_model->setHeaderData(2, Qt::Horizontal, tr("Classrooms"));

	subjects_table->setModel(subjects_model);

	setLayout(vbox);
	vbox->addLayout(buttons_box);
	vbox->addWidget(subjects_table);

}

void Subjects::addSubject() {
	subjects_model->insertRow(0);
}

void Subjects::removeSubject() {
	QItemSelectionModel *selection_model = subjects_table->selectionModel();	
	if (selection_model->selectedRows().count() != 0) {
		subjects_model->removeRow(selection_model->selectedRows().at(0).row());
	}
}
