#include <QTreeView>
#include <QHBoxLayout>
#include <QStandardItemModel>

#include "mainwindow.h"
#include "griddelegate.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
	setWindowTitle(tr("ModelViewExample"));
	setWindowFlags(Qt::Tool);

	treeView_ = new QTreeView(this);
	this->setCentralWidget(treeView_);

	setMinimumHeight(550);
	setMinimumWidth(400);

	enableModelExample();
}

MainWindow::~MainWindow() {}

void MainWindow::enableModelExample()
{
	model_ = new QStandardItemModel(2, 2);
	model_->setHorizontalHeaderLabels({"Property", "Value"});

	QModelIndex index = model_->index(0, 0);
	model_->setData(index, "General");
	model_->insertRows(0, 3, index);
	model_->insertColumns(0, 2, index);
	model_->setData(model_->index(0, 0, index), "Comment");
	model_->setData(model_->index(0, 1, index), "");
	model_->setData(model_->index(1, 0, index), "Name");
	model_->setData(model_->index(1, 1, index), "Title1");
	model_->setData(model_->index(2, 0, index), "Text");
	model_->setData(model_->index(2, 1, index), "Title1");

	index = model_->index(1, 0);
	model_->setData(index, "Size and location");
	model_->insertRows(0, 4, index);
	model_->insertColumns(0, 2, index);
	model_->setData(model_->index(0, 0, index), "Height");
	model_->setData(model_->index(0, 1, index), "2.025");
	model_->setData(model_->index(1, 0, index), "Width");
	model_->setData(model_->index(1, 1, index), "12.025");
	model_->setData(model_->index(2, 0, index), "X");
	model_->setData(model_->index(2, 1, index), "2.5");
	model_->setData(model_->index(3, 0, index), "Y");
	model_->setData(model_->index(3, 1, index), "2.5");

	treeView_->setModel(model_);
	treeView_->setItemDelegate(new GridDelegate(treeView_));
	treeView_->setColumnWidth(0, this->width() / 3);
	treeView_->setEditTriggers(QAbstractItemView::NoEditTriggers);
	treeView_->setSelectionMode(QAbstractItemView::NoSelection);
}
