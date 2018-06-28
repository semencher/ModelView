#include <QPainter>
#include <QStyleOptionViewItem>
#include <QBrush>
#include <QDebug>
#include <QLineEdit>

#include "griddelegate.h"

GridDelegate::GridDelegate(QObject * parent) : QItemDelegate(parent) {}

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

QWidget *GridDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &, const QModelIndex &) const
{
	QLineEdit *editor = new QLineEdit(parent);
	return editor;
}

void GridDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
	QString value = index.model()->data(index, Qt::EditRole).toString();

	QLineEdit *editorLE = static_cast<QLineEdit*>(editor);
	editorLE->setText(value);
}

void GridDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
	QLineEdit *editorLE = static_cast<QLineEdit*>(editor);
	QString value = editorLE->text();
	model->setData(index, value, Qt::EditRole);
}

void GridDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &) const
{
	editor->setGeometry(option.rect);
}
