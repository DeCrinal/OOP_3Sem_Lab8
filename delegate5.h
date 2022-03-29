#ifndef DELEGATE5_H
#define DELEGATE5_H

#include <QItemDelegate>
#include<QWidget>
#include<QLineEdit>
class Delegate5 : public QItemDelegate
{
    QWidget* createEditor(QWidget*parent, const QStyleOptionViewItem&,const QModelIndex&)const;

public:
    explicit Delegate5(QObject *parent = nullptr);
};

#endif // DELEGATE5_H
