#ifndef QTABLEVIEWCUSTOMIZED_H
#define QTABLEVIEWCUSTOMIZED_H

#include <QtGui>
#include <QWidget>
#include <QItemDelegate>
#include <QModelIndex>
#include <QLineEdit>
#include <QRegExp>
#include <QRegExpValidator>
#include <QAbstractItemModel>
#include <QSpinBox>
#include <QStandardItemModel>
#include <QStyleOptionViewItem>
#include <QComboBox>
#include <QApplication>
#include <QPixmap>

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

class ReadOnlyDelegate :public QItemDelegate
{
    Q_OBJECT
public:
    ReadOnlyDelegate(QObject *parent = 0):QItemDelegate(parent) {}
    QWidget * createEditor(QWidget* parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        return NULL;
    }
};

class IDDelegate :public QItemDelegate
{
    Q_OBJECT
public:
    IDDelegate(QObject * parent = 0):QItemDelegate(parent) {}
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        QLineEdit * editor = new QLineEdit(parent);
        QRegExp regExp("[0-9]{0,10}");
        editor->setValidator(new QRegExpValidator(regExp, parent));
        return editor;
    }
    void setEditorData(QWidget * editor, const QModelIndex &index)const
    {
        QString text = index.model()->data(index,Qt::EditRole).toString();
        QLineEdit * lineEdit = static_cast<QLineEdit*>(editor);
        lineEdit->setText(text);
    }
    void setModelData(QWidget * editor, QAbstractItemModel *model, const QModelIndex &index) const
    {
        QLineEdit * lineEdit = static_cast<QLineEdit*>(editor);
        QString text = lineEdit->text();
        model->setData(index, text, Qt::EditRole);
    }
    void updateEditorGeometry(QWidget * editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        editor->setGeometry(option.rect);
    }
};

class AgeDelegate :public QItemDelegate
{
    Q_OBJECT
public:
    AgeDelegate (QObject* parent=0): QItemDelegate(parent) {}
    QWidget * createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        QSpinBox *editor = new QSpinBox(parent);
        editor->setMinimum(1);
        editor->setMaximum(100);
        return editor;
    }
    void setEditorData(QWidget * editor, const QModelIndex &index) const
    {
        int value = index.model()->data(index, Qt::EditRole).toInt();
        QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
        spinBox->setValue(value);
    }
    void updateEditorGeometry(QWidget * editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        editor->setGeometry(option.rect);
    }
};

class  SexDelegate :  public  QItemDelegate  
{  
    Q_OBJECT  
public :  
    SexDelegate(QObject *parent = 0): QItemDelegate(parent) { }  
    QWidget *createEditor(QWidget *parent,  const QStyleOptionViewItem &option,  
         const  QModelIndex &index)  const  
    {  
        QComboBox * editor =  new  QComboBox(parent);  
        editor->addItem( "Female" );  
        editor->addItem( "Male" );  
         return  editor;  
    }  
     void  setEditorData(QWidget *editor,  const  QModelIndex &index)  const  
    {  
        QString text = index.model()->data(index, Qt::EditRole).toString();  
        QComboBox *comboBox =  static_cast <QComboBox*>(editor);  
         int  tindex = comboBox->findText(text);  
        comboBox->setCurrentIndex(tindex);  
    }  
     void  setModelData(QWidget *editor, QAbstractItemModel *model,  
         const  QModelIndex &index)  const  
    {  
        QComboBox *comboBox =  static_cast <QComboBox*>(editor);  
        QString text = comboBox->currentText();  
        model->setData(index, text, Qt::EditRole);  
    }  
     void  updateEditorGeometry(QWidget *editor,  
         const  QStyleOptionViewItem &option,  const  QModelIndex &index) const  
    {  
        editor->setGeometry(option.rect);  
    }  
};  

class  IconDelegate :  public  QItemDelegate  
{  
    Q_OBJECT  
public :  
    IconDelegate(QObject *parent = 0): QItemDelegate(parent) { }  
     void  paint(QPainter *painter,  const  QStyleOptionViewItem &option,  
         const  QModelIndex & index )  const  
    {  
         //show.bmp是在工程目录中的一张图片（其实就是QQ的图标啦，呵呵）  
        QPixmap pixmap = QPixmap( "/temp/lengshuiji.png" ).scaled(24, 24);  
        qApp->style()->drawItemPixmap(painter, option.rect,  Qt::AlignCenter, QPixmap(pixmap));  
    }  
};

class  VIPModel :  public  QStandardItemModel  
{  
    Q_OBJECT  
public :  
    VIPModel(QObject *parent=NULL) : QStandardItemModel(parent) { }  
    VIPModel( int  row,  int  column, QObject *parent=NULL)  
        : QStandardItemModel(row, column, parent) { }  
    QVariant data( const  QModelIndex &index,  int  role = Qt::DisplayRole) const  
    {  
         if ( Qt::TextAlignmentRole == role )  
             return  Qt::AlignCenter;  
         return  QStandardItemModel::data(index, role);  
    }  
  
};  

#endif // QTABLEVIEWCUSTOMIZED_H
