#ifndef QTABLEVIEWCUSTOMIZED_H
#define QTABLEVIEWCUSTOMIZED_H

#include <QWidget>

namespace Ui {
class QTableViewCustomized;
}

class QTableViewCustomized : public QWidget
{
    Q_OBJECT
    
public:
    explicit QTableViewCustomized(QWidget *parent = 0);
    ~QTableViewCustomized();
    
private:
    Ui::QTableViewCustomized *ui;
};

#endif // QTABLEVIEWCUSTOMIZED_H
