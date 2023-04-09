#include "widget.h"
#include "tbook.h"
#include <string>
#include <QMessageBox>
#include <iostream>
#include <fstream>
using namespace std;
int i=0;
TBook books[10];

Widget::Widget(QWidget *parent):QWidget(parent) {
    ifstream fin;
    fin.open("C:/Sivkov David/Homework ggpi/8/4/test84/book.txt");
    if (fin.is_open()) {
        for (int i = 0; i < 10; i++) {
            string temp;
            getline(fin, books[i].Name);
            getline(fin, books[i].Author);
            getline(fin, temp);
            books[i].Count = stoi(temp);
        }
        fin.close();
    } else cout << "Can't find a file!" << endl;

    this->setFixedWidth(300);
    next = new QPushButton("Next");
    back = new QPushButton("Back");
    book = new QLabel("Book " + QString::fromStdString(to_string(i+1))
                          + ":\nName: " + QString::fromStdString(books[i].Name)
                          + "\nAuthor: " + QString::fromStdString(books[i].Author)
                          + "\nCount: " + QString::fromStdString(to_string(books[i].Count))
                          + "\n[" + QString::fromStdString(to_string(i)) + "]");

    lay = new QVBoxLayout(this);
    lay->addWidget(book);
    lay->addWidget(next);
    lay->addWidget(back);

    connect(next, &QPushButton::clicked, this, &Widget::nextBook);
    connect(back, &QPushButton::clicked, this, &Widget::backBook);
}

Widget::~Widget() {}

void Widget::nextBook() {
    if(i+1>9) return;
    i++;
    book->setText("Book " + QString::fromStdString(to_string(i+1))
                      + ":\nName: " + QString::fromStdString(books[i].Name)
                      + "\nAuthor: " + QString::fromStdString(books[i].Author)
                      + "\nCount: " + QString::fromStdString(to_string(books[i].Count))
                      + "\n[" + QString::fromStdString(to_string(i)) + "]");
}

void Widget::backBook() {
    if(i-1<0) return;
    i--;
    book->setText("Book " + QString::fromStdString(to_string(i+1))
                      + ":\nName: " + QString::fromStdString(books[i].Name)
                      + "\nAuthor: " + QString::fromStdString(books[i].Author)
                      + "\nCount: " + QString::fromStdString(to_string(books[i].Count))
                      + "\n[" + QString::fromStdString(to_string(i)) + "]");
}


