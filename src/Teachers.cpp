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

#include "Teachers.hpp"

Teachers::Teachers(QWidget *parent = 0) {
	initUI();
}

void Teachers::initUI() {
	QHBoxLayout *layout = new QHBoxLayout();	
	QVBoxLayout *teachers_layout = new QVBoxLayout();
	QVBoxLayout *teachers_top_layout = new QVBoxLayout();
	QVBoxLayout *details_layout = new QVBoxLayout();
	QHBoxLayout *slots_layout = new QHBoxLayout();	
	QHBoxLayout *subjects_layout = new QHBoxLayout();	

	QGroupBox *teachers_group = new QGroupBox(tr("Teachers"));
	QGroupBox *slots_group = new QGroupBox(tr("Slots"));
	QGroupBox *subjects_group = new QGroupBox(tr("Subjects"));

	QStandardItemModel *teachers_model= new QStandardItemModel(0, 3);
	QStandardItemModel *slots_model = new QStandardItemModel(0, 7);
	QStandardItemModel *subjects_model = new QStandardItemModel(0, 1);

	QTableView *teachers_table = new QTableView();
	QTableView *slots_table = new QTableView();
	QTableView *subjects_table = new QTableView();

	/* teachers table initialization */

	QPushButton *add_teacher = new QPushButton(QIcon::fromTheme("list-add"), tr("add"));
	QPushButton *remove_teacher = new QPushButton(QIcon::fromTheme("list-remove"), tr("remove"));

	connect(add_teacher, SIGNAL(clicked()), this, SLOT(addTeacher()));
	connect(remove_teacher, SIGNAL(clicked()), this, SLOT(removeTeacher()));

	teachers_top_layout->addWidget(add_teacher);
	teachers_top_layout->addWidget(remove_teacher);

	teacher_model->setHeaderData(0, Qt::Horizontal, tr("Name"));
	teacher_model->setHeaderData(1, Qt::Horizontal, tr("Surname"));
	teacher_model->setHeaderData(2, Qt::Horizontal, tr("Max amount of slots"));
	teacher_table->setModel(teacher_model);
	teacher_table->resizeColumnsToContents();	

	teachers_layout->addLayout(teachers_top_layout);
	teachers_layout->addWidget(teachers_table);

	/* slots table initialization */

	/* subjects table initialization */
}
