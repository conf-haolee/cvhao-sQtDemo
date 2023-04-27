// extractdata.cpp
//创建一个.xlsx 文件写入单元格数据，然后将单元格的数据读出来
#include <QtGlobal>
#include <QtCore>
#include <QDebug>

#include "xlsxdocument.h"
#include "extractdata.h"

int extractdata()
{
    {
    //Create a new .xlsx file.
    QXlsx::Document xlsx;
    xlsx.write("A1", "Hello Qt!");
    xlsx.write("A2", 12345);
    xlsx.write("A3", "=44+33");
    xlsx.write("A4", true);
    xlsx.write("A5", "http://qt-project.org");
    xlsx.write("A6", QDate(2013, 12, 27));
    xlsx.write("A7", QTime(6, 30));
    xlsx.saveAs("../Qexcel/extractdata.xlsx");
    }

    //![0]
    QXlsx::Document xlsx("../Qexcel/extractdata.xlsx");
    //![0]

    //![1]
    qDebug() << "extractdata.xlsx - QXlsx::Document.read()";
    qDebug()<<xlsx.read("A1");
    qDebug()<<xlsx.read("A2");
    qDebug()<<xlsx.read("A3");
    qDebug()<<xlsx.read("A4");
    qDebug()<<xlsx.read("A5");
    qDebug()<<xlsx.read("A6");
    qDebug()<<xlsx.read("A7");
    //![1]

    //![2]
    qDebug() << "extractdata.xlsx - QXlsx::Cell.value()";
    for (int row=1; row<10; ++row) {
        if (QXlsx::Cell *cell = xlsx.cellAt(row, 1)) {
            qDebug() << cell->value();
        }
    }
    //![2]

    return 0;
}
