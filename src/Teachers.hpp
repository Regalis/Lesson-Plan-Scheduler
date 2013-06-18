#ifndef __TEACHERS_HPP__
#define __TEACHERS_HPP__

#include <QWidget>

class QAbstractItemModel;
class QTableView;
class QPushbutton;

class Teachers : public QWidget {
	public:
		Teachers(QWidget *parent = 0);

	protected:
		void initUI();
		QPushbutton *add;
		QPushbutton *remove;
		QAbstractItemModel *teachers_model;
		QTableView *teachers_table;
		QAbstractItemModel *slots_model;
		QTableView *slots_table;
		QAbstractItemModel *subjects_model;
		QTableView *subjects_table;

	protected slots:
		void addTeacher();
		void removeTeacher();
};

#endif
