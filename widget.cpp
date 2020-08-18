#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <sstream>
#include <QPixmap>

using namespace std;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget) {
    ui->setupUi(this);
    QPixmap pix("/home/somin/magic-vending-machine/genie.jpg");
    ui->label_pic->setPixmap(pix.scaled(350, 250, Qt::KeepAspectRatio));
    ui->RandomButton->setEnabled(false);
}

Widget::~Widget() {
    delete ui;
}


void Widget::exchange(int a) {
    money += a;
    deactivate_buttons();
    ui->lcdNumber->display(money);
}

void Widget::deactivate_buttons() {
    if (money < 100) ui->pb_coffee->setEnabled(false);
    else ui->pb_coffee->setEnabled(true);
    if (money < 150) ui->pb_tea->setEnabled(false);
    else ui->pb_tea->setEnabled(true);
    if (money < 200) ui->RandomButton->setEnabled(false);
    else ui->RandomButton->setEnabled(true);
    if (money < 300) ui->pb_coke->setEnabled(false);
    else ui->pb_coke->setEnabled(true);

}

void Widget::on_pb10_clicked(){
    exchange(10);
}

void Widget::on_pb50_clicked(){
    exchange(50);
}

void Widget::on_pb100_clicked(){
    exchange(100);
}

void Widget::on_pb500_clicked(){
    exchange(500);
}

void Widget::on_pb_coffee_clicked(){
    exchange(-100);
}

void Widget::on_pb_tea_clicked(){
    exchange(-150);
}

void Widget::on_pb_coke_clicked(){
    exchange(-300);
}

void Widget::on_pb_return_clicked(){
    QMessageBox msg;
    ostringstream content;

    int measure[4] {500, 100, 50, 10};
    int count[4] {0, 0, 0, 0};

    for (int i = 0; i < 4; ++i) {
        count[i] = money / measure[i];
        money -= count[i] * measure[i];

        content << measure[i] << "₩  " << count[i] << "개" << endl ;
    }
    exchange(-money);
    msg.information(nullptr, "안 가져가면 다음사람이 가져감", content.str().c_str());
}

void Widget::on_pushButton_clicked()
{

}

void Widget::on_RandomButton_clicked()
{
    QMessageBox msgBox;
    exchange(-200);
    msgBox.setText("꽝");
    msgBox.exec();


}
