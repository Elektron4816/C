#include "deposit_calculator.h"

#include <stdlib.h>

#include <QDate>
#include <QTime>

#include "ui_deposit_calculator.h"

deposit_calculator::deposit_calculator(QWidget *parent)
    : QWidget(parent), ui(new Ui::deposit_calculator) {
  ui->setupUi(this);
  ui->lineEdit_deposit_amount->setValidator(
      new QDoubleValidator(0, 100, 3, this));
  ui->lineEdit_interest_rate->setValidator(
      new QDoubleValidator(0, 100, 3, this));
  ui->lineEdit_posting_period->setValidator(new QIntValidator(0, 100, this));
  ui->lineEdit_pull->setValidator(new QDoubleValidator(0, 100, 3, this));
  ui->lineEdit_repl->setValidator(new QDoubleValidator(0, 100, 3, this));
  ui->lineEdit_tax->setValidator(new QDoubleValidator(0, 100, 3, this));
}

deposit_calculator::~deposit_calculator() { delete ui; }

void deposit_calculator::on_pushButton_calc_clicked() {
  this->close();
  emit firstWindow();
}

double deposit_calculator::tax() {
  double input_tax = 0;
  QString str = ui->lineEdit_tax->text();
  input_tax = str.toDouble() / 100;
  return input_tax;
}

int deposit_calculator::get_period() {
  int res = 0;
  if (ui->comboBox_2->currentIndex() == 0) {
    res = 1;
  }
  if (ui->comboBox_2->currentIndex() == 1) {
    res = 6;
  }
  if (ui->comboBox_2->currentIndex() == 2) {
    res = 12;
  }

  if (ui->comboBox_2->currentIndex() == 3) {
    res = 3;
  }

  return res;
}

void deposit_calculator::deposit_with_capital(double deposit_amount,
                                              double interest_rate,
                                              double replenishment,
                                              int posting_period,
                                              double withdrawal) {
  QDate today = QDate::currentDate();
  QString nextmounth = 0;

  double interest_charges = 0;
  double interest_accrued = 0;
  double calc_tax = 0;
  double res_calc = 0;

  double input_tax = tax();
  int res = get_period();

  if (posting_period < res) {
    res = posting_period;
  }

  for (int i = res; i < posting_period + 1; i += res) {
    interest_accrued = deposit_amount * interest_rate;

    if (ui->checkBox->isChecked()) {
      deposit_amount += interest_accrued + replenishment -
                        withdrawal;  // условие для капитализации
    } else {
      deposit_amount += replenishment - withdrawal;
    }

    QString checkyear = today.toString("yy");

    today = today.addMonths(res);

    QString checkdate = today.toString("yy");
    QString checkmounth = today.toString("M");

    if ((checkyear < checkdate || checkmounth == "12") && calc_tax > 160000) {
      res_calc += (calc_tax - 160000) * input_tax;
      calc_tax = 0;
    }

    interest_charges += interest_accrued;
    calc_tax += interest_accrued;

    nextmounth += today.toString("MM.yyyy") + " - " +
                  QString::number(interest_accrued, 'f', 2) + " - " +
                  QString::number(replenishment - withdrawal, 'f', 2) + " - " +
                  QString::number(deposit_amount, 'f', 2) + "\n";
    ui->plainTextEdit->setPlainText(nextmounth);
  }

  if (calc_tax > 160000) {
    res_calc += (calc_tax - 160000) * input_tax;
  }

  QString result = QString::number(interest_charges, 'f', 2);
  ui->label_interest_charges->setText(result);

  result = QString::number(res_calc, 'f', 2);
  ui->label_tax_amount->setText(result);

  result = QString::number(deposit_amount, 'f', 2);
  ui->label_end_term->setText(result);
}

void deposit_calculator::on_pushButton_calc_2_clicked() {
  QString str = ui->lineEdit_deposit_amount->text();
  double deposit_amount = str.toDouble();

  str = ui->lineEdit_posting_period->text();
  int posting_period = 0;

  if (ui->comboBox_period->currentIndex() == 0) {
    posting_period = str.toInt() * 12;
  } else {
    posting_period = str.toInt();
  }
  int period = get_period();
  str = ui->lineEdit_interest_rate->text();

  if (posting_period < period) {
    period = posting_period;
  }

  double interest_rate = str.toDouble() / 100 * (30.4221 * period) / 365;

  str = ui->lineEdit_repl->text();
  double replenishment = str.toDouble();  // 0.0372 91.2663

  str = ui->lineEdit_pull->text();
  double withdrawal = str.toDouble();

  deposit_with_capital(deposit_amount, interest_rate, replenishment,
                       posting_period, withdrawal);
}
