#include <QApplication>

#include "visualizer/curvewidget.h"

#include "curves/curves_container/curves_container.h"
#include "tests/test_curve_lib/test_curve_lib.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CurveTests tests;
    int result = QTest::qExec(&tests, argc, argv);
    if (result != 0) {
        return result;
    }

    Helix helix(5, 20);
    CurveWidget widget(&helix);
    widget.resize(800, 600);
    widget.show();


    return a.exec();
}
