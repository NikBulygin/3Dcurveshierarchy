#ifndef CURVE_H
#define CURVE_H

#include <QPoint>
#include <QVector3D>

#if defined(CURVE_LIBRARY)
#  define CURVE_EXPORT Q_DECL_EXPORT
#else
#  define CURVE_EXPORT Q_DECL_IMPORT
#endif

class CURVE_EXPORT Curve {
public:
    enum class CurveType {
        Circle,
        Ellipse,
        Helix,
        LAST
    };


    virtual ~Curve() {}

    // Return a 3D point for parameter t
    virtual QVector3D getPoint(double t) const = 0;

    // Return the first derivative (3D vector) for parameter t
    virtual QVector3D getFirstDerivative(double t) const = 0;

    virtual int get_type_of_curve() const = 0;

};

#endif // CURVE_H
