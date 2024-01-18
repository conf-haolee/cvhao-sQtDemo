#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

QT_CHARTS_USE_NAMESPACE


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("BarChartDemo 柱状图demo");
    QBarSet *set0 = new QBarSet("");  //QBarSet类表示条形图中的一组条。

    std::vector<int> defect_num = {1,2,3,4,5,6};
    auto max = std::max_element(std::begin(defect_num), std::end(defect_num));
    auto min = std::min_element(std::begin(defect_num),std::end(defect_num));
    int max_defect_num = *max;
    int min_defect_num = *min;

    for(int i = 0; i < defect_num.size(); i++){
        *set0 << defect_num[i];
    }

    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->setLabelsPosition(QAbstractBarSeries::LabelsInsideEnd);  // 设置数据系列标签的位置于数据柱内测上方
    series->setLabelsVisible(true);     // 设置显示数据系列标签


    QChart *chart = new QChart();   // 创建chart对象
    chart->addSeries(series);
    chart->setTitle("缺陷物料统计 DEMO");
    chart->setAnimationOptions(QChart::SeriesAnimations);   //设置序列或坐标轴的动画效果

    QStringList categories;
    categories << "尺寸" << "实心" << "扭曲" << "毛刺" << "断裂" <<"颜色";
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    QFont labelsFont;
    labelsFont.setPixelSize(12);
    labelsFont.setBold(true);
    axisX->setLabelsFont(labelsFont);   // 设置X轴字体
    axisX->setLabelsColor(Qt::white);   // 设置X轴颜色

    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    // 设置Y轴 取值范围
    axisY->setMin(0);
    axisY->setMax(max_defect_num);
    axisX->setGridLineVisible(false);   //隐藏背景网格Y轴框线
    axisY->setGridLineVisible(false);   //隐藏背景网格X轴框线
    axisY->setLabelsFont(labelsFont);
    axisY->setLabelsColor(Qt::white);

    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);   // 图例显示
    chart->legend()->setAlignment(Qt::AlignBottom);  // 图例向下居中
    chart->setContentsMargins(0, 0, 0, 0);  //设置外边界全部为0
    chart->setMargins(QMargins(0, 0, 0, 0));//设置内边界全部为0
    chart->setBackgroundRoundness(0);       //设置背景区域无圆角
    chart->setBackgroundBrush(QBrush(QColor(31,32,33)));  // 设置背景颜色

    QChartView *chartView = new QChartView(chart); // chart 添加到chartView 中
    chartView->setRenderHint(QPainter::Antialiasing);

    ui->horizontalLayout->addWidget(chartView);

}

MainWindow::~MainWindow()
{
    delete ui;
}

