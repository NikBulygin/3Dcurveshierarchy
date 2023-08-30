#include <QRandomGenerator>

#include "curves_container.h"

void Curves_container::populateWithRandomCurves(size_t numberOfCurves) {
    for (size_t i = 0; i < numberOfCurves; ++i) {
        int curveType = QRandomGenerator::global()->bounded(
            static_cast<int>(Curve::CurveType::Circle),
            static_cast<int>(Curve::CurveType::LAST) - 1);

        switch (static_cast<Curve::CurveType>(curveType)) {
        case Curve::CurveType::Circle: {
            double radius = 1.0 + QRandomGenerator::global()->generateDouble() * 9.0;  // Random value between 1.0 and 10.0
            curves.push_back(std::make_shared<Circle>(radius));
            break;
        }
        case Curve::CurveType::Ellipse: {
            double radiusX = 1.0 + QRandomGenerator::global()->generateDouble() * 9.0;  // Random value between 1.0 and 10.0
            double radiusY = 1.0 + QRandomGenerator::global()->generateDouble() * 9.0;  // Random value between 1.0 and 10.0
            curves.push_back(std::make_shared<Ellipse>(radiusX, radiusY));
            break;
        }
        case Curve::CurveType::Helix: {
            double radius = 1.0 + QRandomGenerator::global()->generateDouble() * 9.0;  // Random value between 1.0 and 10.0
            double step = 1.0 + QRandomGenerator::global()->generateDouble() * 4.0;    // Random value between 1.0 and 5.0
            curves.push_back(std::make_shared<Helix>(radius, step));
            break;
        }
        default:
            break;
        }
    }
}
