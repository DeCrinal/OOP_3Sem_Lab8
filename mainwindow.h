#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlTableModel>
#include<QDebug>
#include<QLineEdit>
#include<QTableWidget>
#include<QSqlRecord>
#include<QSqlField>
#include<QModelIndex>
#include<QThread>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_tableView_clicked(const QModelIndex&index);
    void on_lineEdit_editingFinished();
    void on_lineEdit_textEdited(const QString &arg1);

private:
    int rowSelected;
    Ui::MainWindow *ui;
    QSqlDatabase database;
    QSqlQuery*query;
    QSqlTableModel*db_model;
};
#endif // MAINWINDOW_H
