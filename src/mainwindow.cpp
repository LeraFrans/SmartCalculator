#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
//    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
//    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
//    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
//    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
//    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
//    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
//    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
//    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
//    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));

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

//void MainWindow::digits_numbers()
//{
//    QPushButton *button = (QPushButton *)sender();

//    double all_numbers;
//    QString new_lable;
//    //all_numbers = (ui->Result_show->text() + button->text()).toDouble();
//    all_numbers = (button->text()).toDouble();
//    new_lable = QString::number(all_numbers, 'g', 15);


//    //ui->Result_show->setText(new_lable);
//    ui->Result_show->setText(ui->Result_show->text() + new_lable);
//}

void MainWindow::on_pushButton_dot_clicked()
{
    if(!(ui->Result_show->text().contains('.')))
        ui->Result_show->setText(ui->Result_show->text() + '.');
}




void MainWindow::on_pushButton_C_clicked()
{
    QString new_lable = "\0";
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
        ui->Result_show->setText(result_of_calc);
}


void MainWindow::operations()
{
    QPushButton *button = (QPushButton *)sender();
    ui->Result_show->setText(ui->Result_show->text() + button->text());

    //ui->Result_show->setText(ui->Result_show->text() + '+');
}




//void MainWindow::on_pushButton_minus_clicked()
//{
//    ui->Result_show->setText(ui->Result_show->text() + '-');
//}

//void MainWindow::on_pushButton_mult_clicked()
//{
//    ui->Result_show->setText(ui->Result_show->text() + '*');
//}


//void MainWindow::on_pushButton_div_clicked()
//{
//    ui->Result_show->setText(ui->Result_show->text() + '/');
//}


//void MainWindow::on_pushButton_x_clicked()
//{
//    ui->Result_show->setText(ui->Result_show->text() + 'x');
//}


//void MainWindow::on_pushButton_close_brace_clicked()
//{
//    ui->Result_show->setText(ui->Result_show->text() + ')');
//}


//void MainWindow::on_pushButton_open_brace_clicked()
//{
//    ui->Result_show->setText(ui->Result_show->text() + '(');
//}




//void MainWindow::on_pushButton_pow_clicked()
//{
//    ui->Result_show->setText(ui->Result_show->text() + '^');
//}


//void MainWindow::on_pushButton_log_clicked()
//{
//    ui->Result_show->setText(ui->Result_show->text() + "log");
//}


//void MainWindow::on_pushButton_tan_clicked()
//{
//    ui->Result_show->setText(ui->Result_show->text() + "tan");
//}


//void MainWindow::on_pushButton_cos_clicked()
//{
//    ui->Result_show->setText(ui->Result_show->text() + "cos");
//}




//void MainWindow::on_pushButton_sin_clicked()
//{
//    ui->Result_show->setText(ui->Result_show->text() + "sin");
//}


//void MainWindow::on_pushButton_mod_clicked()
//{
//    ui->Result_show->setText(ui->Result_show->text() + "mod");
//}


//void MainWindow::on_pushButton_sqrt_clicked()
//{
//    ui->Result_show->setText(ui->Result_show->text() + "sqrt");
//}


//void MainWindow::on_pushButton_ln_clicked()
//{
//    ui->Result_show->setText(ui->Result_show->text() + "ln");
//}


//void MainWindow::on_pushButton_atan_clicked()
//{
//    ui->Result_show->setText(ui->Result_show->text() + "atan");
//}


//void MainWindow::on_pushButton_acos_clicked()
//{
//    ui->Result_show->setText(ui->Result_show->text() + "acos");
//}


//void MainWindow::on_pushButton_asin_clicked()
//{
//    ui->Result_show->setText(ui->Result_show->text() + "asin");
//}



//void MainWindow::on_pushButton_back_clicked()
//{

//}

