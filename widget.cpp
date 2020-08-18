#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <sstream>

using namespace std;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget) {
    ui->setupUi(this);
}

Widget::~Widget() {
    delete ui;
}

void Widget::change_money(int a) {
    money += a;
    deactivate_buttons();
    ui->lcdNumber->display(money);
}

void Widget::deactivate_buttons() {
    if (money < 100) ui->pb_coffee->setEnabled(false);
    else ui->pb_coffee->setEnabled(true);
    if (money < 150) ui->pb_tea->setEnabled(false);
    else ui->pb_tea->setEnabled(true);
    if (money < 300) ui->pb_coke->setEnabled(false);
    else ui->pb_coke->setEnabled(true);
}

void Widget::on_pb10_clicked(){
    change_money(10);
}

void Widget::on_pb50_clicked(){
    change_money(50);
}

void Widget::on_pb100_clicked(){
    change_money(100);
}

void Widget::on_pb500_clicked(){
    change_money(500);
}

void Widget::on_pb_coffee_clicked(){
    change_money(-100);
}

void Widget::on_pb_tea_clicked(){
    change_money(-150);
}

void Widget::on_pb_coke_clicked(){
    change_money(-300);
}

void Widget::on_pb_return_clicked(){
    QMessageBox msg;
    ostringstream content;

    int measure[4] {500, 100, 50, 10};
    int count[4] {0, 0, 0, 0};

    for (int i = 0; i < 4; ++i) {
        count[i] = money / measure[i];
        money -= count[i] * measure[i];
        content << measure[i] << "돈 " << count[i] << endl;
    }

    change_money(-money);
    msg.information(nullptr, "거슬러줌", content.str().c_str());
}
