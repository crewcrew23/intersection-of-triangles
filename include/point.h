#ifndef POINT_H
#define POINT_H

#include <cmath>

struct Point {
    double x = NAN;
    double y = NAN;

    Point() = default;
    Point(double x, double y): x(x), y(y){};
};

#endif //POINT_H