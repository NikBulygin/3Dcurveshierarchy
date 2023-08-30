#ifndef CURVEWIDGET_H
#define CURVEWIDGET_H

#include <QWidget>
#include <Qt3DExtras/Qt3DWindow>
#include <Qt3DRender/QCamera>
#include <Qt3DExtras/QOrbitCameraController>
#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DExtras/QCylinderMesh>
#include <QVBoxLayout>
#include <Qt3DExtras/QPhongMaterial>
#include <QVBoxLayout>
#include <Qt3DRender/QGeometryRenderer>
#include <cmath>

#include "../curves/curve.h"

class CurveWidget : public QWidget {
    Q_OBJECT

public:
    CurveWidget(Curve* curve, QWidget* parent = nullptr);

private:
    Qt3DExtras::Qt3DWindow* view;
    Qt3DExtras::QOrbitCameraController* camController;
    Curve* curve;
};

#endif // CURVEWIDGET_H
