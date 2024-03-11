#ifndef DEPOSIT_CALCULATOR_H
#define DEPOSIT_CALCULATOR_H

#include <QWidget>

namespace Ui {
class deposit_calculator;
}

class deposit_calculator : public QWidget {
  Q_OBJECT

 public:
  explicit deposit_calculator(QWidget *parent = nullptr);
  ~deposit_calculator();

 signals:
  void firstWindow();

 private slots:
  void on_pushButton_calc_clicked();
  void deposit_with_capital(double deposit_amount, double interest_rate,
                            double replenishment, int posting_period,
                            double withdrawal);
  int get_period();
  double tax();
  void on_pushButton_calc_2_clicked();

 private:
  Ui::deposit_calculator *ui;
};

#endif  // DEPOSIT_CALCULATOR_H
