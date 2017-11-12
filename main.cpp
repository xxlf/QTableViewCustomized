#include "QTableViewCustomized.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTableViewCustomized w;
    w.show();
    
    return a.exec();
}
