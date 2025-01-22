#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "line.h"
#include <vector>
#include <math.h>

class Triangle
{
private:
    std::vector<Line> sides_;

public:
    Triangle() = default;
    Triangle(Line &s1, Line &s2, Line &s3);
    ~Triangle() = default;
    
    std::vector<Line> get_lines() const;
    double square();
};

#endif // TRIANGLE_H