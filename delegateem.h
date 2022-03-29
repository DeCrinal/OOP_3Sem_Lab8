#ifndef DELEGATEEM_H
#define DELEGATEEM_H

#include <QItemDelegate>
#include<QLineEdit>

class DelegateEm : public QItemDelegate
{
    QWidget* createEditor(QWidget*parent, const QStyleOptionViewItem&,const QModelIndex&)const;
public:
    explicit DelegateEm(QObject *parent = nullptr);
};

#endif // DELEGATEEM_H
