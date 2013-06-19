#ifndef __GROUPS_HPP__
#define __GROUPS_HPP__

#include <QWidget>
#include <QObject>

class QStandardItemModel;
class QTableView;
class QPushButton;

class Groups : public QWidget {
	Q_OBJECT;
	
	public:
		Groups(QWidget *parent = 0);

	protected:
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
		void addGroup();
		void removeGroup();
		void addSubject();
		void removeSubject();
		void groupSelected(const QModelIndex &current, const QModelIndex &previous);
};

#endif
