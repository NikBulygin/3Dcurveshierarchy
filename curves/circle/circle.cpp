#include "circle.h"

Circle::Circle(double r) : radius(r) {}

//Given a circle's parametric representation:
//x(t)=rcos⁡(t)x(t)=rcos(t)
//y(t)=rsin⁡(t)y(t)=rsin(t)
//where rr is the circle's radius and tt is the parameter varying from 00 to 2π2π.

QVector3D Circle::getPoint(double t) const{
    double x = radius * std::cos(t);
    double y = radius * std::sin(t);
    return QVector3D(x, y, 0);  // Z-coordinate is always 0
}

//The first derivatives (tangents) are:
//x′(t)=−rsin⁡(t)x′(t)=−rsin(t)
//y′(t)=rcos⁡(t)y′(t)=rcos(t)
QVector3D Circle::getFirstDerivative(double t) const {
    double dx = -radius * std::sin(t);
    double dy = radius * std::cos(t);
    return QVector3D(dx, dy, 0);  // Z-coordinate is always 0
}



int Circle::get_type_of_curve() const {
    return static_cast<int>(CurveType::Circle);
}


bool operator<(const Circle& left, const Circle& right) {
    return left.getRadius() < right.getRadius();
}
