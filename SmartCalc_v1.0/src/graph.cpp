#include "graph.h"

#include "ui_graph.h"
//#include "mainwindow.h"
#include "calc.h"

graph::graph(QWidget *parent) : QWidget(parent), ui(new Ui::graph) {
  ui->setupUi(this);
  graph::connect_button();
  //  QString str = ui->lineEdit->text();
  //  QByteArray ba = str.toLocal8Bit();
  //  char *string = ba.data();
  //  int check_devide_zero = 24;
  //  int xMin = ui->spinBox_xmin->text().toInt();
  //  int xMax = ui->spinBox_xmax->text().toInt();
  //  int yMin = ui->spinBox_ymin->text().toInt();
  //  int yMax = ui->spinBox_ymax->text().toInt();

  //  ui->widget->xAxis->setRange(xMin, xMax);
  //  ui->widget->yAxis->setRange(yMin, yMax);
  //  xBegin = -20;
  //  xEnd = 20;
  //  h = 0.1;

  //  for (X = xBegin; X <= xEnd; X += h) {
  //    x.push_back(X);
  //    y.push_back(main_func(string, X, &check_devide_zero));
  //  }
  //  ui->widget->addGraph();
  //  ui->widget->graph(0)->addData(x,y);
  //  ui->widget->replot();
}

graph::~graph() { delete ui; }

void graph::on_pushButton_calc_back_clicked() {
  this->close();
  emit firstWindow();
}

void graph::build_graph() {
  ui->widget->clearGraphs();
  int xMin = ui->spinBox_xmin->text().toInt();
  int xMax = ui->spinBox_xmax->text().toInt();
  int yMin = ui->spinBox_ymin->text().toInt();
  int yMax = ui->spinBox_ymax->text().toInt();

  ui->widget->xAxis->setRange(xMin, xMax);
  ui->widget->yAxis->setRange(yMin, yMax);

  ui->widget->addGraph();
}

void graph::connect_button() {
  connect(ui->pushButton_X, SIGNAL(clicked()), this, SLOT(get_expression()));
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

  //      connect(ui->pushButton_eq, SIGNAL(clicked()), this,
  //              SLOT(get_expression()));
}

void graph::get_expression() {
  QPushButton *button = (QPushButton *)sender();
  QString label;
  label = (ui->lineEdit->text() + button->text());
  ui->lineEdit->setText(label);
}

void graph::on_pushButton_dot_clicked() {
  //  if(!(ui->lineEdit->text().contains('.')))
  //    ui->lineEdit->setText(ui->lineEdit->text() + ".");
  QPushButton *button = (QPushButton *)sender();
  QString label;
  label = (ui->lineEdit->text() + button->text());
  ui->lineEdit->setText(label);
}

void graph::get_expression_fucn() {
  QPushButton *button = (QPushButton *)sender();
  QString label;
  label = (ui->lineEdit->text() + button->text() + '(');
  ui->lineEdit->setText(label);
}

void graph::on_pushButton_clear_clicked() {
  QString clear = {""};
  ui->lineEdit->setText(clear);
}

void graph::on_pushButton_delete_clicked() {
  QString label;
  label = ui->lineEdit->text();
  label.chop(1);
  ui->lineEdit->setText(label);
}

void graph::on_pushButton_eq_clicked() {
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

  ui->widget->clearGraphs();
  int xMin = ui->spinBox_xmin->text().toInt();
  int xMax = ui->spinBox_xmax->text().toInt();
  int yMin = ui->spinBox_ymin->text().toInt();
  int yMax = ui->spinBox_ymax->text().toInt();

  ui->widget->xAxis->setRange(xMin, xMax);
  ui->widget->yAxis->setRange(yMin, yMax);

  ui->widget->addGraph();
  xBegin = xMin;
  xEnd = xMax;
  h = 0.1;
  str = QString::number(lineEdit_number, 'g', 16);

  for (X = xBegin; X <= xEnd; X += h) {
    if (check_devide_zero != 0) {
      x.push_back(X);
      y.push_back(main_func(string, X, &check_devide_zero));
    } else {
      continue;
    }
  }

  ui->widget->addGraph();
  ui->widget->graph(0)->addData(x, y);
  ui->widget->replot();
  x.clear();
  y.clear();
  QString clear = {""};
  ui->lineEdit->setText(clear);
}

void graph::on_pushButton_draw_clicked() { build_graph(); }
