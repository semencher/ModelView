#include <QPainter>
#include <QStyleOptionViewItem>
#include <QBrush>
#include <QDebug>

#include "griddelegate.h"

GridDelegate::GridDelegate(QObject * parent) : QStyledItemDelegate(parent) {}

void GridDelegate::paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const
{
	QPen pen;
	pen.setColor(QColor("#b3b3b3"));
	pen.setWidth(1);

	QBrush brush;

	if (index.row() % 2 == 0) {
		brush.setColor(QColor("#ffffdd"));
	} else {
		brush.setColor(QColor("#ffffbe"));
	}
	brush.setStyle(Qt::SolidPattern);

	painter->setBrush(brush);
	painter->setPen(pen);
	painter->drawRect(option.rect);

	pen.setColor(QColor("#000000"));
	painter->setPen(pen);
	painter->drawText(option.rect, index.data().toString());
}
