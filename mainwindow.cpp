#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAbstractItemModel>
#include <QtGlobal>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringList      lst;
    lst << "С++" << "Python" << "Java" << "C#" << "PHP" << "JavaScript";
    for (int i = 0; i < lst.size(); ++i)
    {
        QStandardItem* item = new QStandardItem(lst[i]);
        item->setIcon(QIcon(":/image/" + lst[i] + ".png"));
        model->appendRow(item);
    }
    ui->listView->setModel(model);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked() // Поднять вверх
{
    QStandardItem* itemTemp = new QStandardItem();    // Создаем новый указатель
    QModelIndex index = ui->listView->currentIndex(); // Узнаем индекс выделенного элемента
    itemTemp = model->itemFromIndex(index);           // Копируем выделенный элемент
    model->removeRow(index.row());                    // Удаляем выделенный элемент
    model->appendRow(itemTemp);                       // Добавляем выделеный элемент в конец списка

}
void MainWindow::on_pushButton_3_clicked() // Удаление
{
    QModelIndex index = ui->listView->currentIndex();
    model->removeRow(index.row());
}

