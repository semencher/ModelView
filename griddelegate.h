#pragma once

#include <QItemDelegate>

class GridDelegate : public QItemDelegate
{
	Q_OBJECT

public:
	explicit GridDelegate(QObject * parent = 0);
	virtual ~GridDelegate() {}

	void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
	void setEditorData(QWidget *editor, const QModelIndex &index) const;
	void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
	void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;

};	// class GridDelegate
