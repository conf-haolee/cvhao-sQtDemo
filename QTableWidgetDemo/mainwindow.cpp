
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("QTableWidget Demo");

//    QString qssTV = "QTableWidget::item:hover{background-color:rgb(92,188,227,200)}"
//                    "QTableWidget::item:selected{background-color:#1B89A1}"
//                    "QHeaderView::section,QTableCornerButton:section{ \
//        padding:3px; margin:0px; color:#DCDCDC;  border:1px solid #242424; \
//        border-left-width:0px; border-right-width:1px; border-top-width:0px; border-bottom-width:1px; \
//        background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #646464,stop:1 #525252); }"
//    "QTableWidget{background-color:white;border:none;}";


//    //ui->tableWidget->setShowGrid(true); //设置显示格子线
//    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); //整行选中的方式
//    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //禁止编辑
//    ui->tableWidget->horizontalHeader()->setStretchLastSection(true); //行头自适应表格
//    ui->tableWidget->horizontalHeader()->setFont(QFont("song", 12));

//    //点击表时不对表头行光亮（获取焦点）
//    ui->tableWidget->horizontalHeader()->setHighlightSections(false);
//    //设置表头字体加粗

//    QFont font =  ui->tableWidget->horizontalHeader()->font();
//    font.setBold(true);
//    ui->tableWidget->horizontalHeader()->setFont(font);
//    //ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:lightblue;}"); //skyblue设置表头背景色
//    //ui->tableWidget->setStyleSheet("selection-background-color:lightblue;"); //设置选中背景色

//    ui->tableWidget->setStyleSheet(qssTV);

//    ui->tableWidget->horizontalHeader()->setHighlightSections(false);         //点击表头时不对表头光亮
//    ui->tableWidget->setSelectionMode(QAbstractItemView::ContiguousSelection);//选中模式为多行选中
//    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

//    //所有单元格的字体  设置成一样
//    ui->tableWidget->setFont(QFont("song", 12));

//    ui->tableWidget->setRowCount(1); //设置行数
//    ui->tableWidget->setColumnCount(8); //设置列数
//    ui->tableWidget->setWindowTitle("TABLE演示");
//    QStringList header;

//    header<<"序号"<<"名称"<<"设备ID"<<"设备IP"<<"设备端口"<<"型号"<<"厂家"<<"备注";
//    ui->tableWidget->setHorizontalHeaderLabels(header);

//    //去掉默认行号 可以用horizontalHeader() ->setVisible(false)隐藏横向表头
//    QHeaderView *header1 =   ui->tableWidget->verticalHeader();
//    header1->setHidden(true);
//    //设置单元格大小
//    ui->tableWidget->horizontalHeader()->setDefaultSectionSize(50);  //设置默认宽度
//    ui->tableWidget->verticalHeader()->setDefaultSectionSize(30);   //设置一行默认高度
//    ui->tableWidget->setColumnWidth(1,110);


//    ui->tableWidget->setSortingEnabled(true);  //启动排序

//    for (int crowCount = 0; crowCount < 20; ++crowCount)
//    {
//        //插入数据
//        QTableWidgetItem *check=new QTableWidgetItem(QString::number(crowCount));
//        check->setCheckState(Qt::Unchecked);  //是否设置选中框
//        ui->tableWidget->insertRow(crowCount);
//        check->setText(QString::number(crowCount));  //显示序号
//        ui->tableWidget->setItem(crowCount,0,check); //插入复选框
//        for(int j=1; j<8; j++ )
//        {
//            ui->tableWidget->setItem(crowCount,j,new QTableWidgetItem(QString::number(j)));
//        }
//    }
    //创建表以及表头
//    ui->tableWidget->setColumnCount(6);
//    QStringList headers;
//    headers <<QStringLiteral("日期") << QStringLiteral("位置") << QStringLiteral("方向")
//            <<QStringLiteral("大小") << QStringLiteral("种类") << QStringLiteral("路径");
//                                                                           ui->tableWidget->setHorizontalHeaderLabels(headers);
//    ui->tableWidget->horizontalHeader()->resizeSection(0,190); //设置表头第一列的宽度为190
    //设置表头字体加粗
//    QFont font1;
//    font1.setFamily("微软雅黑");//字体
//    font1.setPixelSize(25);//文字像素大小
//    font.setPointSize(20);//文字大小
//    font.setUnderline(true);//下划线
//    font.setStrikeOut(true);//中划线
//    font.setOverline(true);//上划线
//    font.setItalic(true);//斜体
//    font.setBold(true);//粗体
//    font1.setStyle(QFont::StyleOblique);
//    font1.setCapitalization(QFont::Capitalize);//首字母大写

//    font.setStyle("")
    ui->tableWidget->horizontalHeader()->setFont(QFont("song", 12));
//    ui->tableWidget->horizontalHeader()->setFont(font1);
//    ui->tableWidget->verticalHeader()->setFont(font1);
    ui->tableWidget->setStyleSheet("selection-background-color:rgb(85, 170, 255)");  //设置选中背景色
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//设置整行选中

    ui->tableWidget->setItem(0,0,new QTableWidgetItem(QString::number(1)));
    ui->tableWidget->setItem(0, 1, new QTableWidgetItem("property1"));
    ui->tableWidget->setItem(0, 2, new QTableWidgetItem("property2"));
    ui->tableWidget->setItem(0, 3, new QTableWidgetItem("property3"));
    ui->tableWidget->setItem(0, 4, new QTableWidgetItem("property4"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

