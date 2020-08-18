#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void change_money(int);
    void deactivate_buttons();


private slots:
    void on_pb10_clicked();
    void on_pb50_clicked();
    void on_pb100_clicked();
    void on_pb500_clicked();
    void on_pb_coffee_clicked();
    void on_pb_tea_clicked();
    void on_pb_coke_clicked();

    void on_pb_return_clicked();

private:
    Ui::Widget *ui;
    int money {0};

};

#endif 
