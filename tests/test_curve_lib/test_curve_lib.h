#ifndef TEST_CURVE_LIB_H
#define TEST_CURVE_LIB_H

#ifndef CURVETESTS_H
#define CURVETESTS_H

#include <QtTest/QtTest>
#include <QObject>
#include <QDebug>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <iostream>


#include "../../curves/curve.h"
#include "../../curves/circle/circle.h"
#include "../../curves/ellipse/ellipse.h"
#include "../../curves/helix/helix.h"
#include "../../curves/curves_container/curves_container.h"


class CurveTests : public QObject
{
    Q_OBJECT

private slots:

    // Init and cleanup functions if needed
    void initTestCase(); // Will be called before the first test function is executed
    void cleanupTestCase(); // Will be called after the last test function was executed

    void init(); // Will be called before each test function is executed
    void cleanup(); // Will be called after every test function is executed

//    void testCurveMethods();

    // Tests for the Circle class
    void testCircleConstructor();
    void testCircleRadius();
    void testCirclePoint();
    void testCircleFirstDerivative();
    void testCircleType();

    // Tests for the Ellipse class
    void testEllipseConstructor();
    void testEllipseRadii();
    void testEllipseAreaFactor();
    void testEllipsePoint();
    void testEllipseFirstDerivative();
    void testEllipseType();

    // Tests for the Helix class
    void testHelixConstructor();
    void testHelixRadius();
    void testHelixPoint();
    void testHelixFirstDerivative();
    void testHelixType();

    // Tests for the Curves_container class
    void testCurvesContainerMethods();
    void testAddCurve();
    void testPopulateWithRandomCurves();
    void testPrintCoordinatesAndDerivatives();
    void testPopulateSpecificCurveType();
    void testSortContainers();
    void testComputeTotalRadius();

};

#endif // CURVETESTS_H

#endif // TEST_CURVE_LIB_H
