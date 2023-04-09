#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>

class Widget : public QWidget {
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QPushButton *Road1;
    QPushButton *Road2;
    QLineEdit *Edit;
    QVBoxLayout *NUM;
    void newFunction();
    void editFunction();
};

#endif

