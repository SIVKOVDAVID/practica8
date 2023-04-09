#include "widget.h"
#include "machine.h"
#include <string>
#include <QMessageBox>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

int i=0;
Machine cars[4];

Widget::Widget(QWidget *parent):QWidget(parent) {
    srand(time(NULL));
    for (int i = 0; i < 4; i++) {
        cars[i].X=10 + rand() % (80);
        cars[i].V=20 + rand() % (70);
        cars[i].P=30 + rand() % (100);
        cout << "[" << i << "]"<< " X= " << cars[i].X<< " V= " << cars[i].V<< " P= " << cars[i].P<< endl;
    }

    this->setFixedWidth(200);
    next = new QPushButton("Next");
    back = new QPushButton("Back");
    car = new QLabel("Car " + QString::fromStdString(to_string(i+1)) + ": X="
                          + QString::fromStdString(to_string(cars[i].X))
                          + " V=" + QString::fromStdString(to_string(cars[i].V))
                          + " P=" + QString::fromStdString(to_string(cars[i].P))
                          + " [" + QString::fromStdString(to_string(i)) + "]");

    lay = new QVBoxLayout(this);
    lay->addWidget(car);
    lay->addWidget(next);
    lay->addWidget(back);

    connect(next, &QPushButton::clicked, this, &Widget::nextCar);
    connect(back, &QPushButton::clicked, this, &Widget::backCar);
}

Widget::~Widget() {}

void Widget::nextCar() {
    if(i+1>3) return;
    i++;
    car->setText("Car " + QString::fromStdString(std::to_string(i+1)) + ": X="
                      + QString::fromStdString(std::to_string(cars[i].X))
                      + " V=" + QString::fromStdString(to_string(cars[i].V))
                      + " P=" + QString::fromStdString(to_string(cars[i].P))
                      + " [" + QString::fromStdString(to_string(i)) + "]");
}

void Widget::backCar() {
    if(i-1<0) return;
    i--;
    car->setText("Car " + QString::fromStdString(std::to_string(i+1)) + ": X="
                      + QString::fromStdString(std::to_string(cars[i].X))
                      + " V=" + QString::fromStdString(to_string(cars[i].V))
                      + " P=" + QString::fromStdString(to_string(cars[i].P))
                      + " [" + QString::fromStdString(to_string(i)) + "]");
}





