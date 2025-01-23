#ifndef LINE_H
#define LINE_H

#include "point.h"
#include <cmath>
#include <vector>

class Line
{
private:
    Point& start_point_;
    Point& end_point_; 
public:
    Line(Point& start_point, Point& end_point) :
     start_point_(start_point), end_point_(end_point) {};

    ~Line() = default;

    Point get_start_point() const;
    Point get_end_point() const;
    double length() const;
};

#endif //LINE_H