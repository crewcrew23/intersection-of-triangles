#include "../include/line.h"

Point Line::get_start_point() const
{
    return start_point_;
}

Point Line::get_end_point() const
{
    return end_point_;
}

double Line::length() const
{
    return std::hypot((start_point_.x - end_point_.x), (start_point_.y - end_point_.y)); // return sqr(x^2 + y^2)
}