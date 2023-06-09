#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class Widget : public QWidget {
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QPushButton *start;
    QPushButton *stop;
    QPushButton *pause;
    QVBoxLayout *l;
    void play();
    void stoping();
    void pausing();
};

#endif


