#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QTime>
#include <QDebug>
#include <QInputDialog>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   ui->labelpic->setVisible(false);
ui->pushButton_6->setVisible(false);
ui->label->setVisible(false);
current=NULL;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QFileDialog dialog(this);
   dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg)"));
  dialog.setViewMode(QFileDialog::Detail);
  QString fileName = QFileDialog::getOpenFileName(this,
           tr("Open Images"), tr("Image Files (*.png *.jpg *.bmp)"));


current=list.add_node(fileName);

  QImage img=set_image(current);

  ui->labelpic->setFixedWidth(img.width());
  ui->labelpic->setFixedHeight(img.height());
  ui->labelpic->setPixmap(QPixmap::fromImage(img));
ui->labelpic->setVisible(true);

}

void MainWindow::on_pushButton_3_clicked()
{
    if(current!=NULL){
        current=current->next;
        QImage img=set_image(current);
        ui->labelpic->setFixedWidth(img.width());
        ui->labelpic->setFixedHeight(img.height());
        ui->labelpic->setPixmap(QPixmap::fromImage(img));
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    if(current!=NULL){
         current=current->prev;
        QImage img=set_image(current);
        ui->labelpic->setFixedWidth(img.width());
        ui->labelpic->setFixedHeight(img.height());
        ui->labelpic->setPixmap(QPixmap::fromImage(img));
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    if(current!=NULL){
      if(list.size==1){
          list.del(current);
          ui->labelpic->setVisible(false);
          current=NULL;
      }else{
          node* ptr=current->next;
          list.del(current);
          current=ptr;
          QImage img=set_image(current);
          ui->labelpic->setFixedWidth(img.width());
          ui->labelpic->setFixedHeight(img.height());
          ui->labelpic->setPixmap(QPixmap::fromImage(img));
      }
    }
}


void MainWindow::on_pushButton_5_clicked()
{

    if(current!=NULL&&list.size>1){
        QString text = QInputDialog::getText(0, "set counter",
                                                 "Number of seconds between every image ", QLineEdit::Normal,
                                                 "");
    QString txt="playing...";
    ui->label->setText(txt);
    ui->label->setVisible(true);
ui->pushButton_5->setVisible(false);
ui->pushButton_6->setVisible(true);
  timer= new QTimer(this);
  connect (timer,SIGNAL(timeout()),this,SLOT(on_pushButton_3_clicked()));
  timer->start((text.toInt()*1000));
}
}


void MainWindow::on_pushButton_6_clicked()
{

    timer->stop();
    ui->label->setVisible(false);
    ui->pushButton_6->setVisible(false);
    ui->pushButton_5->setVisible(true);
}

