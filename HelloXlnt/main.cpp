#include <QCoreApplication>
#include<xlnt/xlnt.hpp>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    xlnt::workbook wb;
    xlnt::worksheet ws = wb.active_sheet();
    ws.cell("A1:").value(5);  //往A1单元格内写值 5
    ws.cell("B2").value("string data");  //

    ws.cell("C3").formula("=RAND()");  //在C3单元格使用公式 生成一个随机数
    ws.cell("C5").formula("=NOW()");

    ws.merge_cells("C3:C4");  //合并C3 C4单元格
    ws.freeze_panes("B2");
    wb.save("D:/Qt_learning/QExcel/example1.xlsx");

    return 0;
//    return a.exec();
}
