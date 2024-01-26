
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("QSettings Demo");
    name_ = "张三";
    age_ = 18;
    self_evaluation_ = "我命由我不由天！";
    InitPara();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::InitPara()
{
    ui->name_lineEdit->setText(name_);
    ui->age_spinBox->setValue(age_);
    ui->self_evaluation_textEdit->setText(self_evaluation_);
}
void MainWindow::LoadPara()
{
    name_ = ui->name_lineEdit->text();
    age_ = ui->age_spinBox->text().toInt();
    self_evaluation_ = ui->self_evaluation_textEdit->toPlainText();
}
void MainWindow::Serialize(const QString& path)
{
    QSettings settings(path, QSettings::IniFormat);
    settings.setIniCodec(QTextCodec::codecForName("UTF-8"));

    settings.beginGroup("MAIN");
    settings.setValue("name",name_);
    settings.endGroup();

    settings.beginGroup("OTHERS");
    settings.setValue("age", age_);
    settings.setValue("self_evaluation", self_evaluation_);
    settings.endGroup();

}
void MainWindow::Deserialize(const QString& path)
{
    QSettings settings(path, QSettings::IniFormat);
    settings.setIniCodec(QTextCodec::codecForName("UTF-8"));

    settings.beginGroup("MAIN");
    name_ = settings.value("name","").toString();
    settings.endGroup();
    settings.beginGroup("OTHERS");
    age_ = settings.value("age").toInt();
    self_evaluation_ = settings.value("self_evaluation").toString();

    qDebug() << "name:" << name_ <<"age_" << age_ << "self_evaluation_:" << self_evaluation_;
    settings.endGroup();

}
// 保存
void MainWindow::on_save_Btn_clicked()
{
    LoadPara();
    QString strPath = QFileDialog::getSaveFileName(this, "导出文件", QCoreApplication::applicationDirPath()
                                                                         + "/" + name_ +".ini", tr("Text files(*.ini)"));
    if(strPath != "")
    {

        Serialize(strPath);
    }
    else {
        QMessageBox::critical(this,"information", "saveError!");
    }
}

// 载入数据
void MainWindow::on_read_Btn_clicked()
{
    QString strPersonFile = QFileDialog::getOpenFileName(this,
                                                     "open",
                                                     "D:",
                                                     "name (*.ini *.txt)");
    if (!strPersonFile.isNull())
    {
        Deserialize(strPersonFile);
    } else {
        qDebug() << "载入数据出错" ;
    }
    InitPara();

}

