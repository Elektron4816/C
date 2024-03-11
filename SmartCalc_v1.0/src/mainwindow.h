#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QAction>
#include <QMainWindow>
#include <QMessageBox>
#include <QVector>
#include <QWidget>

#include "credit_calculator.h"
#include "deposit_calculator.h"
#include "graph.h"

extern "C" {
#include "calc.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  void connect_button();
  void in_graph();

 private:
  Ui::MainWindow *ui;
  graph *graph_window;
  credit_calculator *creditCalc;
  deposit_calculator *depositCalc;

 private slots:
  void get_expression();
  void on_pushButton_dot_clicked();
  void on_pushButton_eq_clicked();
  void get_expression_fucn();
  void on_pushButton_clear_clicked();
  void on_pushButton_delete_clicked();
  void on_pushButton_graph_clicked();
  void on_pushButton_credit_clicked();
  void on_pushButton_deposit_clicked();
};

#endif  // MAINWINDOW_H
