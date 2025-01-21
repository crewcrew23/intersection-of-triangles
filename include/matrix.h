#ifndef MATRIX_H
#define MATRIX_H

#include "line.h"

class Matrix
{
public:
    Matrix() = default;
    ~Matrix() = default;

    double line_point_matrix_det(Line& segment_a, const Point& point);
    double det(double matrix[3][3]);
};

#endif //MATRIX_H