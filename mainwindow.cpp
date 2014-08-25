#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <stdio.h>
#include <iostream>
#include <QTimer>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget->setSpeed(PerformanceWidget::FAST_UPDATE);
    ui->widget->setDisplayMode(CpuWidget::DRAW_GRAPH);

//        std::cout<<sysconf( _SC_PHYS_PAGES) * sysconf( _SC_PAGESIZE )<<std::endl;


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::printPerc()
{


    ui->widget->repaint();

}


