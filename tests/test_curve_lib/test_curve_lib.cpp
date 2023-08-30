#include "test_curve_lib.h"

void CurveTests::initTestCase() {
}

void CurveTests::cleanupTestCase() {
}

void CurveTests::init() {
}

void CurveTests::cleanup() {
}

//void CurveTests::testCurveMethods() {
//}

void CurveTests::testCircleConstructor() {
    Circle* cir = new Circle(5.0);
    if(!cir)
        QFAIL("can't create circle");
    delete cir;
}

void CurveTests::testCircleRadius() {
    Circle* cir = new Circle(5.0);
    QVERIFY(cir->getRadius() == 5.0);
    delete cir;
}

void CurveTests::testCirclePoint() {
    Circle* cir = new Circle(5.0);

    QVector3D expected(3.53553, 3.53553, 0);
    QVector3D actual = cir->getPoint(M_PI/4);

    const double epsilon = 0.00001;

    QVERIFY(qAbs(expected.x() - actual.x()) < epsilon);
    QVERIFY(qAbs(expected.y() - actual.y()) < epsilon);
    QVERIFY(qAbs(expected.z() - actual.z()) < epsilon);

    delete cir;
}

void CurveTests::testCircleFirstDerivative() {
    Circle* cir = new Circle(5.0);

    QVector3D expected(3.53553, 3.53553, 0);
    QVector3D actual = cir->getPoint(M_PI/4);

    const double epsilon = 0.00001;

    QVERIFY(qAbs(expected.x() - actual.x()) < epsilon);
    QVERIFY(qAbs(expected.y() - actual.y()) < epsilon);
    QVERIFY(qAbs(expected.z() - actual.z()) < epsilon);

    delete cir;

}

void CurveTests::testCircleType() {
    Circle* circle = new Circle(5.0);
    QVERIFY(circle->get_type_of_curve() == static_cast<int>(Curve::CurveType::Circle));
    delete circle;
}

void CurveTests::testEllipseConstructor() {
    Circle* cir = new Circle(5.0);
    if(!cir)
        QFAIL("can't create circle");
    delete cir;
}

void CurveTests::testEllipseRadii() {
    Ellipse* ell = new Ellipse(1.0, 2.0);
    QVERIFY(ell->getMajorRadius() == 1.0);
    QVERIFY(ell->getMinorRadius() == 2.0);
    delete ell;
}

void CurveTests::testEllipseAreaFactor() {
    Ellipse* ell = new Ellipse(1.0, 2.0);
    QVERIFY(ell->getAreaFactor() == 2.0);
    delete ell;
}

void CurveTests::testEllipsePoint() {
    Ellipse* ell = new Ellipse(1.0, 2.0);

    QVector3D expected(0.707107, 1.41421, 0);
    QVector3D actual = ell->getPoint(M_PI/4);

    const double epsilon = 0.00001;

    QVERIFY(qAbs(expected.x() - actual.x()) < epsilon);
    QVERIFY(qAbs(expected.y() - actual.y()) < epsilon);
    QVERIFY(qAbs(expected.z() - actual.z()) < epsilon);


    delete ell;
}

void CurveTests::testEllipseFirstDerivative() {
    Ellipse* ell = new Ellipse(1.0, 2.0);

    QVector3D expected(-0.707107, 1.41421, 0);
    QVector3D actual = ell->getFirstDerivative(M_PI/4);

    const double epsilon = 0.00001;

    QVERIFY(qAbs(expected.x() - actual.x()) < epsilon);
    QVERIFY(qAbs(expected.y() - actual.y()) < epsilon);
    QVERIFY(qAbs(expected.z() - actual.z()) < epsilon);


    delete ell;
}

void CurveTests::testEllipseType() {

    Ellipse* ell = new Ellipse(1.0, 2.0);
    QVERIFY(ell->get_type_of_curve() == static_cast<int>(Curve::CurveType::Ellipse));
}


void CurveTests::testHelixConstructor() {
    Helix* helix = new Helix(5.0, 2.0);
    if (!helix)
        QFAIL("can't create helix");
    delete helix;
}

void CurveTests::testHelixRadius() {
    Helix* helix = new Helix(5.0, 2.0);
    QVERIFY(helix->getRadius() == 5.0);
    delete helix;
}

void CurveTests::testHelixPoint() {
    Helix* helix = new Helix(5.0, 2.0);

    QVector3D expected(3.53553, 3.53553, 0.25);
    QVector3D actual = helix->getPoint(M_PI/4);

    const double epsilon = 0.00001;

    QVERIFY(qAbs(expected.x() - actual.x()) < epsilon);
    QVERIFY(qAbs(expected.y() - actual.y()) < epsilon);
    QVERIFY(qAbs(expected.z() - actual.z()) < epsilon);

    delete helix;
}

void CurveTests::testHelixFirstDerivative() {
    Helix* helix = new Helix(5.0, 2.0);

    QVector3D expected(-3.53553, 3.53553, 0.31831);

    QVector3D actual = helix->getFirstDerivative(M_PI/4);

    const double epsilon = 0.00001;

    QVERIFY(qAbs(expected.x() - actual.x()) < epsilon);
    QVERIFY(qAbs(expected.y() - actual.y()) < epsilon);
    QVERIFY(qAbs(expected.z() - actual.z()) < epsilon);

    delete helix;
}

void CurveTests::testHelixType() {
    Helix* helix = new Helix(5.0, 2.0);
    QVERIFY(helix->get_type_of_curve() == static_cast<int>(Curve::CurveType::Helix));
    delete helix;
}

void CurveTests::testCurvesContainerMethods() {
    Curves_container* curves = new Curves_container();
    if(!curves)
        QFAIL("can't create circle");
    delete curves;

}

void CurveTests::testAddCurve() {
    Curves_container* curves = new Curves_container();
    Circle* circle = new Circle(5.0);
    Ellipse* ell = new Ellipse(2.0, 1.0);
    Helix* hell = new Helix(2.0, 1.0);
    QVERIFY(curves->getCount() == 0);

    curves->addCurve(std::shared_ptr<Curve>(circle));
    QVERIFY(curves->getCount() == 1);

    curves->addCurve(std::shared_ptr<Curve>(ell));
    QVERIFY(curves->getCount() == 2);

    curves->addCurve(std::shared_ptr<Curve>(hell));
    QVERIFY(curves->getCount() == 3);

    curves->clearCurves();
    QVERIFY(curves->getCount() == 0);

    delete curves;

}

void CurveTests::testPopulateWithRandomCurves() {
    Curves_container* curves = new Curves_container();
    QVERIFY(curves->getCount() == 0);
    curves->populateWithRandomCurves(10);
    QVERIFY(curves->getCount() == 10);
    curves->populateWithRandomCurves(90);
    QVERIFY(curves->getCount() == 100);
    delete curves;
}


void CurveTests::testPrintCoordinatesAndDerivatives() {
    Curves_container* curves = new Curves_container();
    Circle* circle = new Circle(5.0);
    Ellipse* ell = new Ellipse(2.0, 1.0);
    Helix* hell = new Helix(2.0, 1.0);
    curves->addCurve(std::shared_ptr<Curve>(circle));
    curves->addCurve(std::shared_ptr<Curve>(ell));
    curves->addCurve(std::shared_ptr<Curve>(hell));

    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf(); // сохраняем старый buf
    std::cout.rdbuf(oss.rdbuf()); // перенаправляем в oss

    curves->printCoordinatesAndDerivatives(M_PI/4);

    std::cout.rdbuf(p_cout_streambuf); // восстанавливаем старый buf

    std::string actualOutput = oss.str();
    std::string expectedOutput =
        "Curve of type 6Circle - Point: [3.53553, 3.53553, 0] Derivative: [-3.53553, 3.53553, 0]\n"
        "Curve of type 7Ellipse - Point: [1.41421, 0.707107, 0] Derivative: [-1.41421, 0.707107, 0]\n"
        "Curve of type 5Helix - Point: [1.41421, 1.41421, 0.125] Derivative: [-1.41421, 1.41421, 0.159155]\n";

    QVERIFY(actualOutput == expectedOutput);

    delete curves;
}

void CurveTests::testPopulateSpecificCurveType() {
    Curves_container* curves = new Curves_container();
    Curves_container* only_circle = new Curves_container();

    curves->populateSpecificCurveType(only_circle, Curve::CurveType::Circle);

    for(int i = 0; i < only_circle->getCount(); i++)
    {
        QVERIFY(
            static_cast<int>(Curve::CurveType::Circle) ==
            only_circle->getCurveAt(i)->get_type_of_curve()
            );
    }

    delete curves;


}

void CurveTests::testSortContainers() {
    std::unique_ptr<Curves_container> expected = std::make_unique<Curves_container>();
    std::unique_ptr<Curves_container> curves_sorted = std::make_unique<Curves_container>();

    std::shared_ptr<Circle> circle1 = std::make_shared<Circle>(5.0);
    std::shared_ptr<Circle> circle2 = std::make_shared<Circle>(10.0);
    std::shared_ptr<Ellipse> ell1 = std::make_shared<Ellipse>(2.0, 1.0);
    std::shared_ptr<Ellipse> ell2 = std::make_shared<Ellipse>(20.0, 1.0);
    std::shared_ptr<Helix> hell1 = std::make_shared<Helix>(30.0, 1.0);
    std::shared_ptr<Helix> hell2 = std::make_shared<Helix>(40.0, 1.0);

    expected->addCurve(circle1);
    expected->addCurve(circle2);
    expected->addCurve(ell1);
    expected->addCurve(ell2);
    expected->addCurve(hell1);
    expected->addCurve(hell2);

    curves_sorted->addCurve(ell1);
    curves_sorted->addCurve(ell2);
    curves_sorted->addCurve(hell1);
    curves_sorted->addCurve(hell2);
    curves_sorted->addCurve(circle1);
    curves_sorted->addCurve(circle2);

    curves_sorted->sortContainers();

    QVERIFY(expected->getCount() == curves_sorted->getCount());

    for (int i = 0; i < expected->getCount(); ++i) {
        QVERIFY(expected->getCurveAt(i) == curves_sorted->getCurveAt(i));
    }
}


void CurveTests::testComputeTotalRadius() {
    Curves_container* curves = new Curves_container();

    // Переменная для хранения общего радиуса
    double totalRadius = 0.0;

    for(int i = 0; i < 10; ++i) {
        // Произвольный радиус. Можно заменить на любой другой метод генерации
        double radius = 1.0 + QRandomGenerator::global()->generateDouble() * 9.0;  // Random value between 1.0 and 10.0
        totalRadius += radius;

        curves->addCurve(std::make_shared<Circle>(radius));
    }

    // Сравниваем ожидаемый радиус и полученный радиус
    QCOMPARE(curves->computeTotalRadius(), totalRadius);

    delete curves;
}
