#include "../include/matrix.h"


double Matrix::line_point_matrix_det(Line& segment_a, const Point& point){
    double matrix[3][3] = {
        {segment_a.get_start_point().x, segment_a.get_start_point().y, 1},
        {segment_a.get_end_point().x, segment_a.get_end_point().y, 1},
        {point.x, point.y, 1}
    };

    return det(matrix);
}

double Matrix::det(double matrix[3][3]) {
    return (matrix[0][0] * matrix[1][1] * matrix[2][2]) +
           (matrix[0][1] * matrix[1][2] * matrix[2][0]) +
           (matrix[0][2] * matrix[1][0] * matrix[2][1]) -
           (matrix[0][2] * matrix[1][1] * matrix[2][0]) -
           (matrix[0][0] * matrix[1][2] * matrix[2][1]) -
           (matrix[0][1] * matrix[1][0] * matrix[2][2]);
}