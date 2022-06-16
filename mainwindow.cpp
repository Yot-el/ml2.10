#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent>
#include "point.h"
#include <QPoint>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    for(int i = 0; i<points.size(); i++){
        points[i]->draw(&painter);
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    Point *p = nullptr;
    bool p_move = false;

    QPoint checkpoint;
    checkpoint.setX(event->x());
    checkpoint.setY(event->y());

    for(int i = 0; i < points.size(); i++){
        if(points[i]->distance2(checkpoint) <= 5){
            lastPoint = event->pos();
            point_index = i;
            move_event = true;
            p_move = true;
        }
     }
    if(!p_move){
        p = new Point(event->x(), event->y());
        if(p)
            points.append(p);
    }
    repaint();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(move_event){
        Move_to(event->pos());
        repaint();
    }

}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if(move_event){
        Move_to(event->pos());
        move_event = false;
    }
}

void MainWindow::Move_to(const QPoint &endPoint)
{
    points[point_index]->setX(endPoint.x());
    points[point_index]->setY(endPoint.y());
    lastPoint = endPoint;
}
