#ifndef DELEGATE0_H
#define DELEGATE0_H

#include <QItemDelegate>
#include<QWidget>
#include<QLineEdit>
class Delegate0 : public QItemDelegate
{
    QWidget* createEditor(QWidget*parent, const QStyleOptionViewItem&,const QModelIndex&)const;
public:
    Delegate0();
};

#endif // DELEGATE0_H
