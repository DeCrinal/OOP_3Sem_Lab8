#ifndef DELEGATE4_H
#define DELEGATE4_H

#include <QItemDelegate>
#include <QWidget>
#include <QDateEdit>
#include<QDateTime>
#include<QLineEdit>
class Delegate4 : public QItemDelegate
{
    QWidget* createEditor(QWidget*parent, const QStyleOptionViewItem&,const QModelIndex&)const;
public:
    explicit Delegate4(QObject *parent = nullptr);
};

#endif // DELEGATE4_H
