#ifndef GRAPH_H
#define GRAPH_H

#include <QVector>
#include <QWidget>
//#include <deposit_calculator.h>
//#include <credit_calculator.h>

extern "C" {
#include "calc.h"
}

namespace Ui {
class graph;
}

class graph : public QWidget {
  Q_OBJECT

 public:
  explicit graph(QWidget *parent = nullptr);
  ~graph();

 signals:
  void firstWindow();

 private slots:

  void on_pushButton_calc_back_clicked();
  void connect_button();
  void on_pushButton_clear_clicked();
  void on_pushButton_delete_clicked();
  void get_expression_fucn();
  void on_pushButton_eq_clicked();
  void on_pushButton_dot_clicked();
  void get_expression();
  void build_graph();

  void on_pushButton_draw_clicked();

 private:
  Ui::graph *ui;

  double xBegin, xEnd, h, X;
  int N;

  QVector<double> x, y;
};

#endif  // GRAPH_H
