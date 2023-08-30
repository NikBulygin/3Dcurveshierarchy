#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "../curve.h"


class CURVE_EXPORT Ellipse : public Curve
{
private:
    double a,b;
public:
    Ellipse(double radiusX, double radiusY);


    double getMajorRadius() const { return a; }
    double getMinorRadius() const { return b; }
    double getAreaFactor() const { return a * b; }


    QVector3D getPoint(double t) const override;
    QVector3D getFirstDerivative(double t) const override;
    int get_type_of_curve() const override;


    friend bool operator<(const Ellipse& left, const Ellipse& right);
};

#endif // ELLIPSE_H
