#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QImage>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "handwritingarea.h"
#include "bitmap.h"
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //const int writingAreaHeight = 160;
    //const int writtingAreaWidth = 160;
    area = new HandWritingArea;
    ui->graphicsView->setScene(area);
    ui->graphicsView->setMouseTracking(true);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_clearButton_clicked()
{
    area->clear();
}

void MainWindow::on_translateButton_clicked()
{
    QPixmap pixMap = ui->graphicsView->grab();
    pixMap = pixMap.scaled(16,16,Qt::KeepAspectRatio,Qt::FastTransformation);
    pixMap.save("/Users/apple/Documents/b.bmp","BMP");
    const char *path = new char;
    path = "/Users/apple/Documents/b.bmp";
    BitMap newBmp = BitMap(path);
    double *values = new double[256];
    values = newBmp.ProcessingBitmapIntoArrayForNeuralNet(0,1);
    delete values;
}

void MainWindow::on_translateButton_released()
{

}
