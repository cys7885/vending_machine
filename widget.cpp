#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Widget)
{
  ui->setupUi(this);
}

Widget::~Widget()
{
  delete ui;
}

void Widget::changeStatus(){
  if(money >= 100)
    ui->getCoffe->setEnabled(true);
  else if(money < 100)
    ui->getCoffe->setEnabled(false);
  if(money >= 150)
    ui->getTea->setEnabled(true);
  else if(money < 150)
    ui->getTea->setEnabled(false);
  if(money >= 200)
    ui->getGongcha->setEnabled(true);
  else if(money < 200)
    ui->getGongcha->setEnabled(false);
}

void Widget::changeMoney(int n){
  money += n;
  ui->lcd->display(money);
  changeStatus();
}

QString Widget::returnStatus(){
  QString coins = {};
  int coin_10 = 0;
  int coin_50 = 0;
  int coin_100 = 0;
  int coin_500 = 0;
  int tmp_money = money;

  if (tmp_money >= 500) {
     coin_500 = tmp_money / 500;
     tmp_money = tmp_money % 500;
    }
  if(money >= 100){
      coin_100 = tmp_money / 100;
      tmp_money = tmp_money % 100;
   }
  if(money >= 50){
      coin_50 = tmp_money / 50;
      tmp_money = tmp_money % 50;
    }
  if(money >= 10){
      coin_10 = tmp_money / 10;
      tmp_money = tmp_money % 10;
  }
  coins.append("500won : ");
  coins.append(QString::number(coin_500));
  coins.append("\n");
  coins.append("100won : ");
  coins.append(QString::number(coin_100));
  coins.append("\n");
  coins.append("50won : ");
  coins.append(QString::number(coin_50));
  coins.append("\n");
  coins.append("10won : ");
  coins.append(QString::number(coin_10));
  coins.append("\n");
  return coins;
}

void Widget::on_pb10_clicked()
{
  changeMoney(10);
}

void Widget::on_pb50_clicked()
{
  changeMoney(50);
}

void Widget::on_pb100_clicked()
{
  changeMoney(100);
}

void Widget::on_pb500_clicked()
{
  changeMoney(500);
}

void Widget::on_getCoffe_clicked()
{
  changeMoney(-100);
}

void Widget::on_getTea_clicked()
{
  changeMoney(-150);
}

void Widget::on_getGongcha_clicked()
{
  changeMoney(-200);
}

void Widget::on_returnCoin_clicked()
{
  QMessageBox msg;
  QString coins = returnStatus();
  msg.information(nullptr, "returned coin", coins);
  changeMoney(-money);
}
