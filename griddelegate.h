#pragma once

#include <QStyledItemDelegate>

class GridDelegate : public QStyledItemDelegate
{
public:
	explicit GridDelegate(QObject * parent = 0);

	void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

};	// class GridDelegate
