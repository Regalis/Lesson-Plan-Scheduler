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
//#include <QList>

#include "Teachers.hpp"

Teachers::Teachers(QWidget *parent) : QWidget(parent) {
	initUI();
}

void Teachers::initUI() {
	QVBoxLayout *layout = new QVBoxLayout();	
	QVBoxLayout *teachers_layout = new QVBoxLayout();
	QHBoxLayout *teachers_top_layout = new QHBoxLayout();
	QHBoxLayout *details_layout = new QHBoxLayout();
	QVBoxLayout *slots_layout = new QVBoxLayout();	
	QVBoxLayout *subjects_layout = new QVBoxLayout();	
	QHBoxLayout *subjects_top_layout = new QHBoxLayout();	

	QGroupBox *teachers_group = new QGroupBox(tr("Teachers"));
	QGroupBox *slots_group = new QGroupBox(tr("Slots"));
	QGroupBox *subjects_group = new QGroupBox(tr("Subjects"));

	teachers_model= new QStandardItemModel(0, 3);
	slots_model = new QStandardItemModel(7, 7);
	subjects_model = new QStandardItemModel(0, 1);

	teachers_table = new QTableView();
	slots_table = new QTableView();
	subjects_table = new QTableView();

	/* teachers table initialization */

	add_teacher = new QPushButton(QIcon::fromTheme("list-add"), tr("add"));
	remove_teacher = new QPushButton(QIcon::fromTheme("list-remove"), tr("remove"));

	connect(add_teacher, SIGNAL(clicked()), this, SLOT(addTeacher()));
	connect(remove_teacher, SIGNAL(clicked()), this, SLOT(removeTeacher()));

	teachers_top_layout->addWidget(add_teacher);
	teachers_top_layout->addWidget(remove_teacher);

	teachers_model->setHeaderData(0, Qt::Horizontal, tr("Name"));
	teachers_model->setHeaderData(1, Qt::Horizontal, tr("Surname"));
	teachers_model->setHeaderData(2, Qt::Horizontal, tr("Max amount of slots"));
	teachers_table->setModel(teachers_model);
	teachers_table->resizeColumnsToContents();	

	teachers_table->setSelectionBehavior(QAbstractItemView::SelectRows);
	teachers_table->setSelectionMode(QAbstractItemView::SingleSelection);

	QItemSelectionModel *selection_model = teachers_table->selectionModel();	
	connect(selection_model, SIGNAL(currentRowChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(teacherSelected(const QModelIndex &, const QModelIndex &)));

	teachers_layout->addLayout(teachers_top_layout);
	teachers_layout->addWidget(teachers_table);

	/* slots table initialization */

	slots_model->setHeaderData(0, Qt::Horizontal, tr("Monday"));
	slots_model->setHeaderData(1, Qt::Horizontal, tr("Tuesday"));
	slots_model->setHeaderData(2, Qt::Horizontal, tr("Wednesday"));
	slots_model->setHeaderData(3, Qt::Horizontal, tr("Thursday"));
	slots_model->setHeaderData(4, Qt::Horizontal, tr("Friday"));
	slots_model->setHeaderData(5, Qt::Horizontal, tr("Saturday"));
	slots_model->setHeaderData(6, Qt::Horizontal, tr("Sunday"));

	for(int i = 0; i < 7; ++i) {
		for(int j = 0; j < 7; ++j) {
			QStandardItem *item = new QStandardItem(true);
			item->setCheckable(true);
			item->setCheckState(Qt::Unchecked);
			slots_model->setItem(j, i, item);
		}
	}

	slots_table->setModel(slots_model);
	slots_table->resizeColumnsToContents();	


	slots_layout->addWidget(slots_table);

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

	subjects_table->setSelectionBehavior(QAbstractItemView::SelectRows);
	subjects_table->setSelectionMode(QAbstractItemView::SingleSelection);

	subjects_layout->addLayout(subjects_top_layout);
	subjects_layout->addWidget(subjects_table);

	details_layout->addWidget(slots_group);
	details_layout->addWidget(subjects_group);

	
	teachers_group->setLayout(teachers_layout);
	slots_group->setLayout(slots_layout);
	subjects_group->setLayout(subjects_layout);

	layout->addWidget(teachers_group);
	layout->addLayout(details_layout);

	setLayout(layout);
}

void Teachers::addTeacher() {
	teachers_model->insertRow(0);
}

void Teachers::removeTeacher() {
	QItemSelectionModel *selection_model = teachers_table->selectionModel();	
	if (selection_model->selectedRows().count() != 0) {
		teachers_model->removeRow(selection_model->selectedRows().at(0).row());
	}
}

void Teachers::addSubject() {
	subjects_model->insertRow(0);
}

void Teachers::removeSubject() {
	QItemSelectionModel *selection_model = subjects_table->selectionModel();	
	if (selection_model->selectedRows().count() != 0) {
		subjects_model->removeRow(selection_model->selectedRows().at(0).row());
	}
}

void Teachers::teacherSelected(const QModelIndex &current, const QModelIndex &previous) {
	
}
