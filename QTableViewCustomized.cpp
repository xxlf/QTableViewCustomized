#include "QTableViewCustomized.h"
#include "ui_QTableViewCustomized.h"

QTableViewCustomized::QTableViewCustomized(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QTableViewCustomized)
{
    ui->setupUi(this);
}

QTableViewCustomized::~QTableViewCustomized()
{
    delete ui;
}
