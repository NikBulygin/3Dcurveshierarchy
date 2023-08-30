#ifndef CIRCLE_H
#define CIRCLE_H

#include "../curve.h"



class CURVE_EXPORT Circle : public Curve
{
private:
    double radius;

public:
    Circle(double r);

    double getRadius() const { return radius; }  // Getter for radius

    friend bool operator<(const Circle& left, const Circle& right);


    QVector3D getPoint(double t) const override;
    QVector3D getFirstDerivative(double t) const override;
    int get_type_of_curve() const override;
};

#endif // CIRCLE_H
