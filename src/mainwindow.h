#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

extern "C" {
#include "SmartCalc_v1.0.h"
}

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
//    void digits_numbers();
    void on_pushButton_dot_clicked();
    //void operations();
    void operations();
    void on_pushButton_C_clicked();
    void on_pushButton_equal_clicked();
//    void on_pushButton_plus_clicked();
//    void on_pushButton_minus_clicked();
//    void on_pushButton_mult_clicked();
//    void on_pushButton_div_clicked();
//    void on_pushButton_x_clicked();
//    void on_pushButton_close_brace_clicked();
//    void on_pushButton_open_brace_clicked();
//    void on_pushButton_pow_clicked();
//    void on_pushButton_log_clicked();
//    void on_pushButton_tan_clicked();
//    void on_pushButton_cos_clicked();
//    void on_pushButton_sin_clicked();
//    void on_pushButton_mod_clicked();
//    void on_pushButton_sqrt_clicked();
//    void on_pushButton_ln_clicked();
//    void on_pushButton_atan_clicked();
//    void on_pushButton_acos_clicked();
//    void on_pushButton_asin_clicked();
//    void on_pushButton_back_clicked();
    void on_pushButton_Plot_graph_clicked();
    void on_pushButton_Credit_clicked();
};
#endif // MAINWINDOW_H
