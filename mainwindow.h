#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QLabel>
#include "linkedlist.h"
#include <QTimer>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:


     Linkedlist list;
    node* current=NULL;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QImage set_image(node* n){
         QImage img(n->val);
        int width =img.width();
        int height=img.height();

      if(width>height){

          img = img.scaled(391, 311, Qt::KeepAspectRatio);
      } else if (width<height){

          img = img.scaled(200, 311, Qt::KeepAspectRatio);
      }else{

          img = img.scaled(311, 311, Qt::KeepAspectRatio);
      }
      return img;
    }
private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
      QTimer *timer;
};
#endif // MAINWINDOW_H
