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
  explicit Widget(QWidget *parent = nullptr);
  ~Widget();
  void changeMoney(int n);
  void changeStatus();
  QString returnStatus();
  int money{0};


private slots:
  void on_pb10_clicked();

  void on_pb50_clicked();

  void on_pb100_clicked();

  void on_pb500_clicked();

  void on_getCoffe_clicked();

  void on_getTea_clicked();

  void on_getGongcha_clicked();

  void on_returnCoin_clicked();

private:
  Ui::Widget *ui;
};

#endif // WIDGET_H
