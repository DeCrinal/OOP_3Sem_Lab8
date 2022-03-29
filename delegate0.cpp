#include "delegate0.h"

Delegate0::Delegate0()
{

}
QWidget* Delegate0::createEditor(QWidget*parent, const QStyleOptionViewItem&,const QModelIndex&)const{
    QLineEdit*lineEdit = new QLineEdit(parent);
    QRegExp regExp("([A-Я]{1}[a-яё\\s-]{1,30}[а-яё]{1}|[A-Z]{1}[a-z\\s-]{1,30}[a-z]{1})");
    QValidator*validator = new QRegExpValidator(regExp,lineEdit);
    lineEdit->setValidator(validator);
    return lineEdit;
}
