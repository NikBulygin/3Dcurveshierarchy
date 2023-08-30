#include "curves_container.h"


void sortSpecificType(std::vector<std::shared_ptr<Curve>>::iterator begin,
                      std::vector<std::shared_ptr<Curve>>::iterator end,
                      int type) {
    switch (static_cast<Curve::CurveType>(type)) {
    case Curve::CurveType::Circle:
        std::sort(begin, end, [](const std::shared_ptr<Curve>& a, const std::shared_ptr<Curve>& b) {
            return std::dynamic_pointer_cast<Circle>(a)->getRadius() <
                   std::dynamic_pointer_cast<Circle>(b)->getRadius();
        });
        break;
    case Curve::CurveType::Ellipse:
        std::sort(begin, end, [](const std::shared_ptr<Curve>& a, const std::shared_ptr<Curve>& b) {
            return std::dynamic_pointer_cast<Ellipse>(a)->getAreaFactor() <
                   std::dynamic_pointer_cast<Ellipse>(b)->getAreaFactor();
        });
        break;
    case Curve::CurveType::Helix:
        std::sort(begin, end, [](const std::shared_ptr<Curve>& a, const std::shared_ptr<Curve>& b) {
            return std::dynamic_pointer_cast<Helix>(a)->getRadius() <
                   std::dynamic_pointer_cast<Helix>(b)->getRadius();
        });
        break;
    default:
        break;
    }
}

void Curves_container::sortContainers() {
    // Sort based on Curve::CurveType enum
    std::sort(curves.begin(), curves.end(), [](const std::shared_ptr<Curve>& a, const std::shared_ptr<Curve>& b) {
        return a->get_type_of_curve() < b->get_type_of_curve();
    });

    // Now sort each subset
    std::vector<std::shared_ptr<Curve>>::iterator beginIter = curves.begin();
    int currentType = (*beginIter)->get_type_of_curve();

    for (std::vector<std::shared_ptr<Curve>>::iterator iter = curves.begin(); iter != curves.end(); ++iter) {
        if ((*iter)->get_type_of_curve() != currentType) {
            sortSpecificType(beginIter, iter, currentType);
            beginIter = iter;
            currentType = (*beginIter)->get_type_of_curve();
        }
    }

    // For the last subset
    sortSpecificType(beginIter, curves.end(), currentType);
}

