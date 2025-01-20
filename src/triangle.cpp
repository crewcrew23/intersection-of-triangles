#include "../include/triangle.h"

Triangle::Triangle(Line &s1, Line &s2, Line &s3){
    sides_.push_back(s1);
    sides_.push_back(s2);
    sides_.push_back(s3);
}

std::vector<Line> Triangle::get_lines(){
    return sides_;
}

// S = √(p(p - a)(p - b)(p - c)), where p is the semi-perimeter, which we find as follows: p = (a + b + c)/2.
double Triangle::square()
    {
        double p = (sides_[0].length() + sides_[1].length() + sides_[2].length()) / 2;
        double s = std::sqrt(p * (p - sides_[0].length()) * (p - sides_[1].length()) *
                             (p - sides_[2].length()));
        return s;
    }