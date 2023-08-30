#include "curves_container.h"

#include <iostream>

void Curves_container::printCoordinatesAndDerivatives(double t) {
    for (std::shared_ptr<Curve> curve : curves) {
        QVector3D point = curve->getPoint(t);
        QVector3D derivative = curve->getFirstDerivative(t);

        std::cout << "Curve of type " << typeid(*curve).name()
                  << " - Point: [" << point.x() << ", " << point.y() << ", " << point.z() << "]"
                  << " Derivative: [" << derivative.x() << ", " << derivative.y() << ", " << derivative.z() << "]"
                  << std::endl;
    }
}
