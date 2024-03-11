#ifndef CREDIT_CALCULATOR_H
#define CREDIT_CALCULATOR_H

#include <QWidget>

namespace Ui {
class credit_calculator;
}

class credit_calculator : public QWidget {
  Q_OBJECT

 public:
  explicit credit_calculator(QWidget *parent = nullptr);
  ~credit_calculator();

 signals:
  void firstWindow();

 private slots:
  void on_pushButton_calc_clicked();
  void annuity_payment(double credit, double percent, int mounth);
  void differentiated_payment(double credit, double percent, int mounth);

  void on_pushButton_calculate_credit_clicked();

 private:
  Ui::credit_calculator *ui;
};

#endif  // CREDIT_CALCULATOR_H
