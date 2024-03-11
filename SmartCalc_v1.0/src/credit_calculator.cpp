#include "credit_calculator.h"

#include "ui_credit_calculator.h"

credit_calculator::credit_calculator(QWidget *parent)
    : QWidget(parent), ui(new Ui::credit_calculator) {
  ui->setupUi(this);
  ui->lineEdit_credit_term->setValidator(new QIntValidator(0, 100, this));
  ui->lineEdit_interest_rate->setValidator(
      new QDoubleValidator(0, 100, 3, this));
  ui->lineEdit_total_loan->setValidator(new QDoubleValidator(0, 100, 3, this));
}

credit_calculator::~credit_calculator() { delete ui; }

void credit_calculator::on_pushButton_calc_clicked() {
  this->close();
  emit firstWindow();
}

void credit_calculator::on_pushButton_calculate_credit_clicked() {
  QString str = ui->lineEdit_total_loan->text();
  double sum_credit = str.toDouble();

  str = ui->lineEdit_interest_rate->text();
  double interest_rate = str.toDouble() / 12 / 100;

  str = ui->lineEdit_credit_term->text();
  int mounth = 0;

  if (ui->comboBox_period->currentIndex() == 0) {
    mounth = str.toInt() * 12;
  } else {
    mounth = str.toInt();
  }
  if (ui->radioButton_annuity->isChecked()) {
    ui->label_mount_pay->resize(113, 21);
    annuity_payment(sum_credit, interest_rate, mounth);
  }
  if (ui->radioButton_differ->isChecked()) {
    // ui->lineEdit_mount_pay->add
    ui->label_mount_pay->resize(113, 41);
    differentiated_payment(sum_credit, interest_rate, mounth);
  }
}

void credit_calculator::annuity_payment(double credit, double percent,
                                        int mounth) {
  double total_paid = 0;
  double total_interest_payment = 0;
  double amount_of_payment = 0;
  double interest_payment = 0;
  double principal_payment = 0;
  amount_of_payment = credit * (percent * (pow((1.0 + percent), mounth)) /
                                (pow((1.0 + percent), mounth) - 1));
  for (int i = 1; i < mounth + 1; i++) {
    interest_payment = credit * percent;
    principal_payment = amount_of_payment - interest_payment;
    credit -= principal_payment;
    // printf(
    //     "mounth = %d | amount_of_payment = %.2f | principal_payment = %.2f |
    //     " "interest_payment "
    //     "= %.2f| "
    //     "balance_owed = %.2f\n",
    //     i, amount_of_payment, principal_payment, interest_payment, credit);
    total_paid += amount_of_payment;
    total_interest_payment += interest_payment;
  }
  QString result = QString::number(amount_of_payment, 'f', 2);
  ui->label_mount_pay->setText(result);
  result = QString::number(total_paid, 'f', 2);
  ui->label_loan_overpay->setText(result);
  result = QString::number(total_interest_payment, 'f', 2);
  ui->label_total_pay->setText(result);
}

void credit_calculator::differentiated_payment(double credit, double percent,
                                               int mounth) {
  double principal_payment = credit / mounth;
  double total_paid = 0;
  double total_interest_payment = 0;
  double amount_of_payment = 0;
  double interest_payment = 0;
  double first_payment = 0;
  for (int i = 1; i < mounth + 1; i++) {
    interest_payment = credit * percent;
    amount_of_payment = principal_payment + interest_payment;
    if (i == 1) {
      first_payment = amount_of_payment;
    }
    credit -= principal_payment;
    //        printf(
    //            "mounth = %d | amount_of_payment = %.2f | principal_payment =
    //            %.2f | " "interest_payment "
    //            "= %.2f| "
    //            "balance_owed = %.2f\n",
    //            i, amount_of_payment, principal_payment, interest_payment,
    //            credit);
    total_paid += amount_of_payment;
    total_interest_payment += interest_payment;
  }
  // printf("total_paid = %.2f\n", total_paid);
  QString result = QString::number(amount_of_payment, 'f', 2);
  QString result_first = QString::number(first_payment, 'f', 2);
  ui->label_mount_pay->setText(result_first + "...\n" + result);
  result = QString::number(total_paid, 'f', 2);
  ui->label_loan_overpay->setText(result);
  result = QString::number(total_interest_payment, 'f', 2);
  ui->label_total_pay->setText(result);
}
