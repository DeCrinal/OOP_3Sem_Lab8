#include "delegate5.h"
#include<QDebug>
Delegate5::Delegate5(QObject *parent) : QItemDelegate(parent)
{

}

QWidget* Delegate5::createEditor(QWidget*parent, const QStyleOptionViewItem&,const QModelIndex&)const{
    QLineEdit*lineEdit = new QLineEdit(parent);
    QRegExp regExp("([+]{1}\\d{1,3}[(]{1}\\d{1,3}[)]{1}\\d{7})");
    QValidator*validator = new QRegExpValidator(regExp,lineEdit);
    lineEdit->setValidator(validator);
    return lineEdit;
}
