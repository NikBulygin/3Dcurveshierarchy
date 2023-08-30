#include "curves_container.h"

Curves_container::Curves_container()
{

}

void Curves_container::addCurve(std::shared_ptr<Curve> curve) {
    curves.push_back(curve);
}
