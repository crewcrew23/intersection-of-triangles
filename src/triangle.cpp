#include "../include/triangle.h"
#include "../include/matrix.h"
#include  <stdexcept>

Triangle::Triangle(Line &s1, Line &s2, Line &s3){
    const double epsilon = 1e-9;

    if (s1.length() > s2.length() + s3.length() ||
        s2.length() > s1.length() + s3.length() ||
        s3.length() > s2.length() + s1.length())
    {
        throw std::runtime_error("this triangle does not satisfy the triangle inequality");
    }
    
    if (s1.length() <= epsilon || s2.length() <= epsilon || s3.length() <= epsilon) {
        throw std::runtime_error("A side of the triangle has zero or negative length");
    }                       

    sides_.push_back(s1);
    sides_.push_back(s2);
    sides_.push_back(s3);
}

std::vector<Line> Triangle::get_lines() const{
    return sides_;
}

double Triangle::square() const
{
    double p = (sides_[0].length() + sides_[1].length() + sides_[2].length()) / 2;
    double s = std::sqrt(p * (p - sides_[0].length()) * (p - sides_[1].length()) *
                             (p - sides_[2].length()));
    return s;
}