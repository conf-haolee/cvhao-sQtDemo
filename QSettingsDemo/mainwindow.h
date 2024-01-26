#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QSettings>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextCodec>
#include <QDebug>
#include <QMap>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void InitPara();
    void LoadPara();
    void Serialize(const QString& path);
    void Deserialize(const QString& path);

private slots:
    void on_save_Btn_clicked();

    void on_read_Btn_clicked();

private:
    Ui::MainWindow *ui;
    QString name_;
    int age_;
    QString self_evaluation_;

};
#endif // MAINWINDOW_H
