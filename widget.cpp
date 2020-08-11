#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <string>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int coin)
{
    money += coin;
    if(money >= 200){
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbMilk->setEnabled(true);
    }else if(money >= 150){
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbMilk->setEnabled(false);
    }else if (money >= 100){
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(false);
        ui->pbMilk->setEnabled(false);
    }else{
        ui->pbCoffee->setEnabled(false);
        ui->pbTea->setEnabled(false);
        ui->pbMilk->setEnabled(false);
    }
    ui->lcdNumber->display(money);
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
    //money += 10;
    //ui->lcdNumber->display(money);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
    //money += 50;
    //ui->lcdNumber->display(money);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
    //money += 100;
    //ui->lcdNumber->display(money);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
    //money += 500;
    //ui->lcdNumber->display(money);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
    //money -= 100;
    //ui->lcdNumber->display(money);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
    //money -= 150;
    //ui->lcdNumber->display(money);
}

void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
    //money -= 200;
    //ui->lcdNumber->display(money);
}

void Widget::on_pbReset_clicked()
{
    QMessageBox m;
    using namespace std;
    string fiveHundred = to_string(money/500);
    money %= 500;
    string hundred = to_string(money/100);
    money %= 100;
    string fifty = to_string(money/50);
    money %= 50;
    string ten = to_string(money/10);

    string output = "500Coin : "+ fiveHundred + "\n" +
            "100Coin : " + hundred + "\n" +
            "50Coin : " + fifty + "\n" +
            "10Coin : " + ten;
    const char *op = output.c_str();

    m.information(nullptr, "notice", op);

    money = 0;
    ui->lcdNumber->display(money);
    changeMoney(money);
}
