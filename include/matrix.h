#ifndef MATRIX_H
#define MATRIX_H

#include "line.h"

class Matrix
{
public:
    Matrix() = default;
    ~Matrix() = default;

    static double line_point_matrix_det(Line& segment_a, const Point& point);
    static double det(double matrix[3][3]);
};

#endif //MATRIX_H