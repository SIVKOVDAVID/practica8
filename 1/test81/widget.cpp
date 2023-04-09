#include "widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent):QWidget(parent) {
    this->setFixedWidth(200);
    start = new QPushButton("Start");
    stop = new QPushButton("Stop");
    pause = new QPushButton("Pause");

    l = new QVBoxLayout(this);
    l->addWidget(start);
    l->addWidget(stop);
    l->addWidget(pause);

    connect(start, &QPushButton::clicked, this, &Widget::play);
    connect(stop, &QPushButton::clicked, this, &Widget::stoping);
    connect(pause, &QPushButton::clicked, this, &Widget::pausing);
}

Widget::~Widget() {}

void Widget::play() {
    QMessageBox::warning(this, "Information", "Test N7.1: OK.");
}
void Widget::stoping() {
    QMessageBox::warning(this, "Information", "Stop");
}
void Widget::pausing() {
    QMessageBox::warning(this, "Information", "Paus");
}


