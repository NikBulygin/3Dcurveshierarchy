#ifndef CURVER_CONTAINER_H
#define CURVER_CONTAINER_H


#include <vector>
#include <QVector3D>
#include <memory>  // for std::shared_ptr
#include <cmath>

#include "../curve.h"
#include "../circle/circle.h"
#include "../ellipse/ellipse.h"
#include "../helix/helix.h"


class CURVE_EXPORT Curves_container {
private:
    std::vector<std::shared_ptr<Curve>> curves;

public:
    Curves_container();

    void addCurve(std::shared_ptr<Curve> curve);

    // 1. Populate the main container with random curves
    void populateWithRandomCurves(size_t numberOfCurves);

    int getCount()
    {
        return curves.size();
    }

    // 2. Print coordinates and derivatives at t=PI/4 for all curves
    void printCoordinatesAndDerivatives(double t = M_PI / 4.0);

    // 3. Populate the second container with only circles from the main container
    void populateSpecificCurveType(Curves_container* targetContainer, Curve::CurveType type);

    // 4. Sort circles in ascending order of their radii
    void sortContainers();

    // 5. Compute total sum of radii of circles
    double computeTotalRadius();

    void clearCurves() {
        curves.clear();
    }



    std::shared_ptr<Curve> getCurveAt(int index) {
        if (index >= 0 && index < curves.size()) {
            return curves[index];
        }
        return nullptr;
    }

};

#endif // CURVER_CONTAINER_H
