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

	setMinimumHeight(700);
	setMinimumWidth(400);

	enableModelExample();
}

MainWindow::~MainWindow() {}

void MainWindow::enableModelExample()
{
	model_ = new QStandardItemModel(5, 3);

	for (int nTopRow = 0; nTopRow < 5; ++nTopRow) {
		QModelIndex index = model_->index(nTopRow, 0);
		model_->setData(index, "Item" + QString::number(nTopRow + 1));

		model_->insertRows(0, 4, index);
		model_->insertColumns(0, 3, index);
		for (int nRow = 0; nRow < 4; ++nRow) {
			for (int nCol = 0; nCol < 3; ++nCol) {
				QString strPos = QString("%1-%2").arg(nRow).arg(nCol);
				model_->setData(model_->index(nRow, nCol, index), strPos);
			}
		}
	}
	treeView_->setModel(model_);
	treeView_->setItemDelegate(new GridDelegate(treeView_));
}
