#pragma once

#include <QMainWindow>

class QTreeView;
class QStandardItemModel;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

private:
	void enableModelExample();

private:
	QTreeView			*treeView_;
	QStandardItemModel	*model_;

};	// class MainWindow
