#include <QCoreApplication>

#include <QtGlobal>
#include <QCoreApplication>
#include <QtCore>
#include <QVariant>
#include <QDebug>
#include <iostream>
using namespace std;

#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"

#include "calendar.h"
#include "chart.h"
#include "chartsheet.h"
#include "datavalidation.h"
#include "documentproperty.h"

#include "extractdata.h"
#include "hyperlinks.h"
#include "image.h"
#include "mergecells.h"

#include "richtext.h"
#include "rowcolumn.h"

#include "worksheetoperations.h"

using namespace QXlsx;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QXlsx::Document xlsx;
    xlsx.write("A1", "Hello Qt!"); // write "Hello Qt!" to cell(A,1). it's shared string.
    xlsx.saveAs("../Qexcel/Test3.xlsx"); // save the document as 'Test.xlsx'

//    calendar();
//    chart();
//    chartsheet();
//    datavalidation();

//    documentproperty();

//    extractdata();
//    hyperlink();
//    image();
//    mergecells();
//    rowcolumn();
    worksheetoperations();


    //return a.exec();
    return 0;
}
