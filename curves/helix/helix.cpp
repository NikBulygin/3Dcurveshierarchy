#include "helix.h"

Helix::Helix(double radius, double step) : radius(radius), step(step) {}

//The helix's spatial parametric representation is:
//x(t)=rcos⁡(t)x(t)=rcos(t)
//y(t)=rsin⁡(t)y(t)=rsin(t)
//z(t)=s⋅tz(t)=s⋅t

QVector3D Helix::getPoint(double t) const {
    double x = radius * std::cos(t);
    double y = radius * std::sin(t);
    double z = step * t / (2 * M_PI);  // z increases by 's' for every full rotation (2 * PI)
    return QVector3D(x, y, z);
}


//The first derivatives for the helix are:
//x′(t)=−rsin⁡(t)x′(t)=−rsin(t)
//y′(t)=rcos⁡(t)y′(t)=rcos(t)
//z′(t)=sz′(t)=s
QVector3D Helix::getFirstDerivative(double t) const{
    double dx = -radius * std::sin(t);
    double dy = radius * std::cos(t);
    double dz = step / (2 * M_PI);  // Derivative of z(t) = s*t/(2*PI)
    return QVector3D(dx, dy, dz);
}


int Helix::get_type_of_curve() const{
    return static_cast<int>(Curve::CurveType::Helix);
}


bool operator<(const Helix& left, const Helix& right) {
    return left.getRadius() < right.getRadius();
}
