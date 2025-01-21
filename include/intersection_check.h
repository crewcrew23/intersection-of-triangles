#ifndef INTERSECTION_CHECH_H
#define INTERSECTION_CHECH_H

#include <iostream>
#include <vector>

#include "triangle.h"
#include "matrix.h"

class IntersectionCheck
{
public:
    IntersectionCheck() = default;
    ~IntersectionCheck() = default;

    double check(Triangle &t1, Triangle &t2)
    {
        std::vector<Line> lines1 = t1.get_lines();
        std::vector<Line> lines2 = t2.get_lines();

        for (auto &line1 : lines1)
        {
            for (auto &line2 : lines2)
            {
                double det1 = matrix.line_point_matrix_det(line1, line2.get_start_point());
                double det2 = matrix.line_point_matrix_det(line1, line2.get_end_point());

                double det3 = matrix.line_point_matrix_det(line2, line1.get_start_point());
                double det4 = matrix.line_point_matrix_det(line2, line1.get_end_point());

                // Checking if points are on different sides of segments
                if ((det1 * det2 < 0) && (det3 * det4 < 0))
                {
                    return true; // The triangles intersect
                }
            }
        }

        return false; // The triangles not intersect
    }

private:
    Matrix matrix;
};

#endif // INTERSECTION_CHECH_H