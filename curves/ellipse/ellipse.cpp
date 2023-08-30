#include "ellipse.h"

Ellipse::Ellipse(double radiusX, double radiusY) : a(radiusX), b(radiusY) {}

//For an ellipse lying in the XoY plane, its parametric representation is:
//x(t)=acos⁡(t)x(t)=acos(t)
//y(t)=bsin⁡(t)y(t)=bsin(t)

QVector3D Ellipse::getPoint(double t) const {
    double x = a * std::cos(t);
    double y = b * std::sin(t);
    return QVector3D(x, y, 0);  // Z-coordinate is always 0
}

//The first derivatives for the ellipse are:
//x′(t)=−asin⁡(t)x′(t)=−asin(t)
//y′(t)=bcos⁡(t)y′(t)=bcos(t)
QVector3D Ellipse::getFirstDerivative(double t) const{
    double dx = -a * std::sin(t);
    double dy = b * std::cos(t);
    return QVector3D(dx, dy, 0);  // Z-coordinate is always 0
}


int Ellipse::get_type_of_curve() const{
    return static_cast<int>(CurveType::Ellipse);
}


bool operator<(const Ellipse& left, const Ellipse& right) {
    return left.getAreaFactor() < right.getAreaFactor();
}
