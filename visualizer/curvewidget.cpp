#include "curvewidget.h"
#include <Qt3DExtras/QPhongMaterial>
#include <QVBoxLayout>
#include <Qt3DRender/QGeometryRenderer>
#include <Qt3DCore/QAttribute>
#include <Qt3DCore/QBuffer>
#include <cmath>

CurveWidget::CurveWidget(Curve* curve, QWidget* parent)
    : QWidget(parent),
    view(new Qt3DExtras::Qt3DWindow()),
    curve(curve) {

    QWidget *container = QWidget::createWindowContainer(view);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(container);

    auto rootEntity = new Qt3DCore::QEntity;
    view->setRootEntity(rootEntity);

    auto camera = view->camera();
    camera->setPosition(QVector3D(0, 0, 40.0f));
    camera->setViewCenter(QVector3D(0, 0, 0));

    camController = new Qt3DExtras::QOrbitCameraController(rootEntity);
    camController->setLinearSpeed(50.0f);
    camController->setLookSpeed(180.0f);
    camController->setCamera(camera);

    auto material = new Qt3DExtras::QPhongMaterial(rootEntity);
    material->setDiffuse(QColor(QRgb(0xbeb32b)));

    const int resolution = 1000; // Количество сегментов
    const double step = (2 * M_PI) / resolution;

    Qt3DRender::QGeometryRenderer *geometryRenderer = new Qt3DRender::QGeometryRenderer;
    Qt3DCore::QGeometry *geometry = new Qt3DCore::QGeometry(geometryRenderer);

    // Список вершин для геометрии
    QByteArray vertexBufferData;
    vertexBufferData.resize(resolution * sizeof(QVector3D));
    QVector3D *vertices = reinterpret_cast<QVector3D *>(vertexBufferData.data());

    for(int i = 0; i < resolution; ++i) {
        double t = -M_PI + step * i;
        vertices[i] = curve->getPoint(t);
    }

    // Создание атрибута вершины и буфера
    Qt3DCore::QBuffer *vertexBuffer = new Qt3DCore::QBuffer(geometry);
    vertexBuffer->setData(vertexBufferData);

    Qt3DCore::QAttribute *positionAttribute = new Qt3DCore::QAttribute(geometry);
    positionAttribute->setAttributeType(Qt3DCore::QAttribute::VertexAttribute);
    positionAttribute->setBuffer(vertexBuffer);
    positionAttribute->setVertexBaseType(Qt3DCore::QAttribute::Float);
    positionAttribute->setVertexSize(3);
    positionAttribute->setByteOffset(0);
    positionAttribute->setByteStride(3 * sizeof(float));
    positionAttribute->setCount(resolution);
    positionAttribute->setName(Qt3DCore::QAttribute::defaultPositionAttributeName());

    geometry->addAttribute(positionAttribute);
    geometryRenderer->setGeometry(geometry);
    geometryRenderer->setPrimitiveType(Qt3DRender::QGeometryRenderer::LineStrip);

    auto entity = new Qt3DCore::QEntity(rootEntity);
    entity->addComponent(geometryRenderer);
    entity->addComponent(material);
}
