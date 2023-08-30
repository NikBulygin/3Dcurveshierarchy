#ifndef HELIX_H
#define HELIX_H

#include "../curve.h"


class CURVE_EXPORT Helix : public Curve
{
private:
    double radius;
    double step;

public:
    Helix(double radius, double step);

    double getRadius() const { return radius; }  // Getter for radius
    friend bool operator<(const Helix& left, const Helix& right);

    QVector3D getPoint(double t) const override;
    QVector3D getFirstDerivative(double t) const override;
    int get_type_of_curve() const override;
};

#endif // HELIX_H
