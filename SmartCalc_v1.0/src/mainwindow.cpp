#include "mainwindow.h"

#include <QMessageBox>

#include "./ui_mainwindow.h"
#include "calc.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  graph_window = new graph();
  depositCalc = new deposit_calculator();
  creditCalc = new credit_calculator();

  connect(graph_window, &graph::firstWindow, this, &MainWindow::show);
  connect(depositCalc, &deposit_calculator::firstWindow, this,
          &MainWindow::show);
  connect(creditCalc, &credit_calculator::firstWindow, this, &MainWindow::show);

  MainWindow::connect_button();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::connect_button() {
  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(get_expression()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(get_expression()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(get_expression()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(get_expression()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(get_expression()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(get_expression()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(get_expression()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(get_expression()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(get_expression()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(get_expression()));
  connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(get_expression()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(get_expression()));
  connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(get_expression()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this,
          SLOT(get_expression()));
  connect(ui->pushButton_left_bracket, SIGNAL(clicked()), this,
          SLOT(get_expression()));
  connect(ui->pushButton_right_bracket, SIGNAL(clicked()), this,
          SLOT(get_expression()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(get_expression()));

  connect(ui->pushButton_log, SIGNAL(clicked()), this,
          SLOT(get_expression_fucn()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this,
          SLOT(get_expression_fucn()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this,
          SLOT(get_expression_fucn()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this,
          SLOT(get_expression_fucn()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this,
          SLOT(get_expression_fucn()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this,
          SLOT(get_expression_fucn()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this,
          SLOT(get_expression_fucn()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this,
          SLOT(get_expression_fucn()));
  connect(ui->pushButton_degree, SIGNAL(clicked()), this,
          SLOT(get_expression()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this,
          SLOT(get_expression_fucn()));

  //    connect(ui->pushButton_eq, SIGNAL(clicked()), this,
  //            SLOT(on_pushButton_eq_clicked()));
}

void MainWindow::get_expression() {
  QPushButton *button = (QPushButton *)sender();
  QString label;
  label = (ui->lineEdit->text() + button->text());
  ui->lineEdit->setText(label);
}

void MainWindow::on_pushButton_dot_clicked() {
  QPushButton *button = (QPushButton *)sender();

  ui->lineEdit->cursorBackward(true);
  QChar point = ui->lineEdit->text()[ui->lineEdit->cursorPosition()];

  if (point > '/' && point < ':') {
    QString label;
    label = (ui->lineEdit->text() + button->text());
    ui->lineEdit->setText(label);
  } else {
    ui->lineEdit->cursorForward(true, 1);
  }
}

void MainWindow::on_pushButton_eq_clicked() {
  QPushButton *button = (QPushButton *)sender();
  QString label;
  label = (ui->lineEdit->text() + button->text());
  ui->lineEdit->setText(label);

  QString str = ui->lineEdit->text();
  double lineEdit_number = 24;

  QByteArray ba = str.toLocal8Bit();
  char *string = ba.data();
  int check_devide_zero = 24;
  lineEdit_number = main_func(string, 0, &check_devide_zero);

  if (check_devide_zero == 0) {
    ui->lineEdit->setText("");
    QMessageBox::critical(this, "test", "Divide by zero");
  } else if (check_devide_zero == 1) {
    ui->lineEdit->setText("");
    QMessageBox::information(this, "check", "Wrong argument");
  } else if (check_devide_zero == 2) {
    ui->lineEdit->setText("");
    QMessageBox::information(this, "check", "Invalid scope");
  } else {
    str = QString::number(lineEdit_number, 'g', 16);
    ui->lineEdit->setText(str);
  }
}

void MainWindow::get_expression_fucn() {
  QPushButton *button = (QPushButton *)sender();
  QString label;
  label = (ui->lineEdit->text() + button->text() + '(');
  ui->lineEdit->setText(label);
}

void MainWindow::on_pushButton_clear_clicked() {
  QString clear = {""};
  ui->lineEdit->setText(clear);
}

void MainWindow::on_pushButton_delete_clicked() {
  QString label;
  label = ui->lineEdit->text();
  label.chop(1);
  ui->lineEdit->setText(label);
}

void MainWindow::on_pushButton_graph_clicked() {
  graph_window->show();
  this->close();
}

void MainWindow::on_pushButton_credit_clicked() {
  creditCalc->show();
  this->close();
}

void MainWindow::on_pushButton_deposit_clicked() {
  depositCalc->show();
  this->close();
}
