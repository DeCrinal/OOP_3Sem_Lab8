#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "delegate0.h"
#include "delegate4.h"
#include "delegate5.h"
#include "delegateem.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./ContactDB.db");
    db.setUserName("userdefault");
    db.setHostName("userdefault");
    db.setPassword("password");
    if(!db.open()){
        qDebug()<<"Database couldn't be openned";
    }
    query = new QSqlQuery(db);
    query->exec("CREATE TABLE Contacts(Фамилия TEXT, Имя TEXT, Отчество TEXT, Адрес TEXT, Дата рождения TEXT, email TEXT, Номер TEXT);");
    db_model = new QSqlTableModel(this,db);
    db_model->setTable("Contacts");
    db_model->select();
    ui->tableView->setModel(db_model);
    ui->tableView->setItemDelegateForColumn(0,new Delegate0());
    ui->tableView->setItemDelegateForColumn(1,new Delegate0());
    ui->tableView->setItemDelegateForColumn(2,new Delegate0());
    ui->tableView->setItemDelegateForColumn(4,new Delegate4());
    ui->tableView->setItemDelegateForColumn(6,new Delegate5());
    ui->tableView->setItemDelegateForColumn(5,new DelegateEm());
    ui->tableView->resizeColumnsToContents();
    ui->lineEdit->setText("for searching");
    this->setWindowTitle("QSQL DataBase");
}
void MainWindow::on_pushButton_clicked(){
    db_model->insertRow(db_model->rowCount());
    return;
}
void MainWindow::on_pushButton_2_clicked(){
    db_model->removeRow(rowSelected);
    ui->tableView->update();
    db_model->select();
    return;
}
void MainWindow::on_tableView_clicked(const QModelIndex&index){
    rowSelected=index.row();
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_lineEdit_editingFinished()
{
    QString strToSearh = ui->lineEdit->text();
        for(int i = 0; i<db_model->rowCount();i++){
            QSqlRecord data = db_model->record(i);
                for(int j = 0; j<data.count();j++){
                    QSqlField tempField = data.field(j);
                        if(strToSearh==tempField.value()){
                            qDebug()<<"It's here";
                            QModelIndex index = ui->tableView->model()->index(i,j);
                            qDebug()<<index;
                            ui->tableView->selectionModel()->select(index,QItemSelectionModel::Select);
                        }
                }
        }
}


void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
   ui->tableView->clearSelection();
}

