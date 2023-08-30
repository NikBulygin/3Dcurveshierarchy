#include <omp.h>
#include "curves_container.h"

double Curves_container::computeTotalRadius() {
    double totalRadius = 0.0;

    #pragma omp parallel for shared(curves) reduction(+:totalRadius)
    for (std::vector<std::shared_ptr<Curve>>::iterator it = curves.begin(); it != curves.end(); ++it) {
        int curveType = (*it)->get_type_of_curve();

        if (curveType == static_cast<int>(Curve::CurveType::Ellipse)) {
            Ellipse* ellipse = dynamic_cast<Ellipse*>(it->get());
            if (ellipse) {
                totalRadius += (ellipse->getMajorRadius() + ellipse->getMinorRadius()) / 2.0;
            }
        } else if (curveType == static_cast<int>(Curve::CurveType::Circle)) {
            Circle* circle = dynamic_cast<Circle*>(it->get());
            if (circle) {
                totalRadius += circle->getRadius();
            }
        } else if (curveType == static_cast<int>(Curve::CurveType::Helix)) {
            Helix* helix = dynamic_cast<Helix*>(it->get());
            if (helix) {
                totalRadius += helix->getRadius();
            }
        }
        // other curve types
    }

    return totalRadius;
}
