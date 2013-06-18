#ifndef __TEACHERS_HPP__
#define __TEACHERS_HPP__

#include <QWidget>
#include <QObject>

class QStandardItemModel;
class QTableView;
class QPushButton;

class Teachers : public QWidget {
	Q_OBJECT;
	
	public:
		Teachers(QWidget *parent = 0);

	protected:
		void initUI();
		QPushButton *add_teacher;
		QPushButton *remove_teacher;
		QPushButton *add_subject;
		QPushButton *remove_subject;
		QStandardItemModel *teachers_model;
		QTableView *teachers_table;
		QStandardItemModel *slots_model;
		QTableView *slots_table;
		QStandardItemModel *subjects_model;
		QTableView *subjects_table;

	protected slots:
		void addTeacher();
		void removeTeacher();
		void addSubject();
		void removeSubject();
		void teacherSelected(const QModelIndex &current, const QModelIndex &previous);
};

#endif
