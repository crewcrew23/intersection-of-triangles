#ifndef POINT_H
#define POINT_H

#include <cmath>

struct Point {
    double x = NAN;
    double y = NAN;

    Point() = default;
    Point(double x, double y): x(x), y(y){}

    // bool operator<(const Point& other) const {
    //     if (x != other.x) {
    //         return x < other.x;
    //     }
    //     return y < other.y;
    // }

    bool operator<(const Point& other) const {
    if (std::abs(x - other.x) > 1e-9) {
        return x < other.x;
    }
    return y < other.y;
    }


    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

#endif //POINT_H