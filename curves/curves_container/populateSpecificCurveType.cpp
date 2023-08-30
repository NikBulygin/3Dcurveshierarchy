#include "curves_container.h"

void Curves_container::populateSpecificCurveType(Curves_container* targetContainer, Curve::CurveType type) {
    if (!targetContainer) return;  // Ensure the target container is not null

    targetContainer->clearCurves();  // Clear any curves previously stored in the target container

    for (std::shared_ptr<Curve> curve : curves) {
        if (curve->get_type_of_curve() == static_cast<int>(type)) {
            targetContainer->addCurve(curve);
        }
    }
}
