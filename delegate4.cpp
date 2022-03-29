#include "delegate4.h"

QWidget *Delegate4::createEditor(QWidget *parent,
                     const QStyleOptionViewItem &, const QModelIndex &) const
{
    QDateEdit*dateEdit = new QDateEdit(parent);
    dateEdit->setMaximumDate(QDate::currentDate());
    return dateEdit;
}
Delegate4::Delegate4(QObject *parent) : QItemDelegate(parent)
{

}
