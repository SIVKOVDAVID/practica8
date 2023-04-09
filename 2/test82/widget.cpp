#include "widget.h"
#include "troad.h"
#include <string>
#include <QMessageBox>
using namespace std;
TRoad road(7,77);

Widget::Widget(QWidget *parent):QWidget(parent) {
    this->setFixedWidth(300);
    Road1 = new QPushButton("Road1");
    Road2 = new QPushButton("Road2");

    Edit = new QLineEdit("Edit: ");

    NUM = new QVBoxLayout(this);
    NUM->addWidget(Edit);
    NUM->addWidget(Road1);
    NUM->addWidget(Road2);

    connect(Road1, &QPushButton::clicked, this, &Widget::newFunction);
    connect(Road2, &QPushButton::clicked, this, &Widget::editFunction);
}

Widget::~Widget() {}

void Widget::newFunction() {
    QString width = QString::fromStdString(to_string(road.Width));
    QString length = QString::fromStdString(to_string(road.Length));
    QMessageBox::warning(this, "Road1", "Before:\n- Width: " + width + "\n- Length: " + length);
    road.Width = 70;
    road.Length = 77;
    width = QString::fromStdString(to_string(road.Width));
    length = QString::fromStdString(to_string(road.Length));
    QMessageBox::warning(this, "Road1", "After:\n- Width: " + width + "\n- Length: " + length);
}

void Widget::editFunction() {
    QString edit=Edit->text();
    int wwidth = edit.split(" ")[0].toInt();
    int llength = edit.split(" ")[1].toInt();
    QString width = QString::fromStdString(to_string(road.Width));
    QString length = QString::fromStdString(to_string(road.Length));
    QMessageBox::warning(this, "Road2", "Before:\n- Width: " + width + "\n- Length: " + length);
    road.Width = wwidth;
    road.Length = llength;
    width = QString::fromStdString(to_string(road.Width));
    length = QString::fromStdString(to_string(road.Length));
    QMessageBox::warning(this, "Road2", "After:\n- Width: " + width + "\n- Length: " + length);
}

