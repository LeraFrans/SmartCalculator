#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(operations()));

    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_mult,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_div,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_x,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_open_brace,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_close_brace,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_pow,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_log,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_ln,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_mod,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_sqrt,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_sin,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_cos,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_tan,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_asin,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_acos,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_atan,SIGNAL(clicked()),this,SLOT(operations()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_dot_clicked()
{
    if(!(ui->Result_show->text().contains('.')))
        ui->Result_show->setText(ui->Result_show->text() + '.');
}




void MainWindow::on_pushButton_C_clicked()
{
    QString new_lable = "|";
    ui->Result_show->setText(new_lable);
}


void MainWindow::on_pushButton_equal_clicked()
{
    double res;
        std::string str = ui->Result_show->text().toStdString();
        const char* strings = str.c_str();
        res = simple_calculation((char *)strings);

        QString result_of_calc;
        result_of_calc = QString::number(res, 'g', 15);
        ui->Result_show->setText('|' + result_of_calc);
}


void MainWindow::operations()
{
    QPushButton *button = (QPushButton *)sender();
    ui->Result_show->setText(ui->Result_show->text() + button->text());

    //ui->Result_show->setText(ui->Result_show->text() + '+');
}





void MainWindow::on_pushButton_Plot_graph_clicked()
{
    //Сгенерируем данные
    //Для этого создадим два массива точек:
    //один для сохранения x координат точек,
    //а второй для y соответственно
    //Начало интервала, где рисуем график по оси Ox
    double x_min = ui->spinBox_x_min->value();
    double x_max = ui->spinBox_x_max->value();

    //double b =  1; //Конец интервала, где рисуем график по оси Ox
    double h = (x_max - x_min)/200; //Шаг, с которым будем пробегать по оси Ox
    int N = 202; //Вычисляем количество точек, которые будем отрисовывать
    QVector<double> x(N), y(N); //Массивы координат точек

    //Вычисляем наши данные
    int i=0;
    //Пробегаем по всем точкам
    for (double X = x_min; X <= x_max; X += h) {
      x[i] = X;

      std::string str = ui->Result_show->text().toStdString();
      const char* strings = str.c_str();
      //res = simple_calculation((char *)strings);
      y[i] = calculate_y((char *)strings, X);
      i++;
    }
    ui->widget->clearGraphs();//Если нужно, но очищаем все графики

    //Добавляем один график в widget
    ui->widget->addGraph();

    //Говорим, что отрисовать нужно график по нашим двум массивам x и y
    ui->widget->graph(0)->setData(x, y);

    //Подписываем оси Ox и Oy
    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");

    //Установим область, которая будет показываться на графике
    ui->widget->xAxis->setRange(x_min, x_max);//Для оси Ox

    //Для показа границ по оси Oy сложнее, так как надо по правильному
    //вычислить минимальное и максимальное значение в векторах
    double minY = y[0], maxY = y[0];
    for (int i = 1; i < N; i++) {
      if (y[i] < minY) minY = y[i];
      if (y[i] > maxY) maxY = y[i];
    }
    ui->widget->yAxis->setRange(minY, maxY);//Для оси Oy

    //И перерисуем график на нашем widget
    ui->widget->replot();
}


void MainWindow::on_pushButton_Credit_clicked()
{
    double credit_sum = ui->credit_sum->value();
      double credit_percent = ui->credit_percent->value();
      double credit_time = ui->credit_time->value();

      double payment = 0;
      double payment_more = 0;
      double payment_sum = 0;

      double sd = credit_sum / credit_time;
      double sp = 0;
      double sp_sum = 0;

      double months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

      int index_credit = ui->type_credit->currentIndex();  // 0 - annuit

      int month_number = ui->month_number->value();

      if (index_credit == 0) {
        payment = credit_sum *
                  ((credit_percent / (100 * 12)) /
                   (1 - pow((1 + credit_percent / (100 * 12)), -credit_time)));
        payment_sum = payment * credit_time;
        payment_more = payment_sum - credit_sum;
      } else if (index_credit == 1) {
        for (int i = 0; i < credit_time; i++) {
          sp = (credit_sum - sp_sum) * (credit_percent / 100) * (months[i % 12]) /
               365;
          payment_sum = payment_sum + sp + sd;
          sp_sum = sp_sum + sd;
        }
        sp_sum = 0;
        for (int i = 0; i < month_number; i++) {
          sp = (credit_sum - sp_sum) * (credit_percent / 100) * (months[i % 12]) /
               365;
          sp_sum = sp_sum + sd;
        }
        payment = sd + sp;
        payment_more = payment_sum - credit_sum;
      }

      QString payment_out = QString::number(payment, 'g', 10);
      QString payment_sum_out = QString::number(payment_sum, 'g', 10);
      QString payment_more_out = QString::number(payment_more, 'g', 10);

      ui->credit_payment->setText(payment_out);
      ui->credit_more->setText(payment_more_out);
      ui->payment_sum->setText(payment_sum_out);
}

