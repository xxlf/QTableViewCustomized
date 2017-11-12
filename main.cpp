#include "QTableViewCustomized.h"
#include <QApplication>
#include <QtableView>
#include <QHeaderView>
#include <QAbstractItemView>
#include <QAbstractItemDelegate>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QTableViewCustomized w;
//    w.show();
    VIPModel * model = new VIPModel(5,5);
    QTableView * tableView = new QTableView;
    tableView->setAlternatingRowColors(true);
    tableView->setStyleSheet("QTableView{background-color: rgb(250, 250, 115);"  
                             "alternate-background-color: rgb(141, 163, 215);}");
    tableView->setWindowTitle("VIP List");
    tableView->resize(700, 400);
    tableView->setModel(model);
    QStringList headerList;
    headerList<< "No." << "ID" << "Name" << "Age" << "Sex" << "Show";
    model->setHorizontalHeaderLabels(headerList);
    tableView->verticalHeader()->setVisible(false);
    tableView->horizontalHeader()->setStretchLastSection(true);
    
    //
    ReadOnlyDelegate readOnlyDelegate;
    tableView->setItemDelegateForColumn(0, &readOnlyDelegate);
    IDDelegate userIDDelegate;
    tableView->setItemDelegateForColumn(1, &userIDDelegate);
    AgeDelegate spinBoxDelegate;
    tableView->setItemDelegateForColumn(3, &spinBoxDelegate);
    SexDelegate comboBoxDelegate;
    tableView->setItemDelegateForColumn(4, &comboBoxDelegate);
    IconDelegate  iconDelegate;
    tableView->setItemDelegateForColumn(5, &iconDelegate);
    
    for(int i=0; i<10; i++)
    {
        QModelIndex index = model->index(i, 0, QModelIndex());
        model->setData(index, i);
    }
    tableView->show();
    return a.exec();
}
