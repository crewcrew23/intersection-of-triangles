#ifndef INTERSECTION_CHECH_H
#define INTERSECTION_CHECH_H

#include <iostream>
#include <vector>
#include <optional>
#include <set>
#include <cmath>

#include "point.h"
#include "line.h"
#include "triangle.h"
#include "matrix.h"

class IntersectionCheck
{
public:
    IntersectionCheck() = default;
    ~IntersectionCheck() = default;

    double check(Triangle &t1, Triangle &t2);
    std::optional<Point> find_point_of_intersection(Line &line1, Line &line2);
    std::vector<Point> find_all_intersections(Triangle &t1, Triangle &t2);
    bool is_point_in_triangle(const Point &p, const Triangle &t);
    bool is_point_on_segment(const Point& intersection, const Line& line);
};

#endif // INTERSECTION_CHECH_H