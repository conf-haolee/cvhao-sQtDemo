#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("QSplitterDemo 分割窗口的Demo实现");
}

MainWindow::~MainWindow()
{
    delete ui;
}

