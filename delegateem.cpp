#include "delegateem.h"

DelegateEm::DelegateEm(QObject *parent) : QItemDelegate(parent)
{

}

QWidget* DelegateEm::createEditor(QWidget*parent, const QStyleOptionViewItem&,const QModelIndex&)const{
    QLineEdit*lineEdit = new QLineEdit(parent);
    QRegExp regExp("([0-9A-Za-z]*[@][a-z]{1,}.[a-z]{1,})");
    QValidator*validator = new QRegExpValidator(regExp,lineEdit);
    lineEdit->setValidator(validator);
    return lineEdit;
}
