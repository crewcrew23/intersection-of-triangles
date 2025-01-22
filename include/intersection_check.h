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

    double check(Triangle &t1, Triangle &t2)
    {
        std::vector<Line> lines1 = t1.get_lines();
        std::vector<Line> lines2 = t2.get_lines();

        for (auto &line1 : lines1)
        {
            for (auto &line2 : lines2)
            {
                double det1 = Matrix::line_point_matrix_det(line1, line2.get_start_point());
                double det2 = Matrix::line_point_matrix_det(line1, line2.get_end_point());

                double det3 = Matrix::line_point_matrix_det(line2, line1.get_start_point());
                double det4 = Matrix::line_point_matrix_det(line2, line1.get_end_point());

                // Checking if points are on different sides of segments
                if ((det1 * det2 < 0) && (det3 * det4 < 0))
                {
                    return true; // The triangles intersect
                }
            }
        }

        return false; // The triangles not intersect
    }

    std::optional<Point> find_point_of_intersection(Line &line1, Line &line2) {
        Point A = line1.get_start_point();
        Point B = line1.get_end_point();
        Point C = line2.get_start_point();
        Point D = line2.get_end_point();

        double denominator = (B.x - A.x) * (D.y - C.y) - (B.y - A.y) * (D.x - C.x);

        if (std::abs(denominator) < 1e-9) {
            return std::nullopt;
        }

        double t = ((C.x - A.x) * (D.y - C.y) - (C.y - A.y) * (D.x - C.x)) / denominator;
        double u = ((B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x)) / denominator;

        if (t < -1 || t > 1 || u < -1 || u > 1) {
            return std::nullopt;
        }

        Point intersection{
            A.x + t * (B.x - A.x),
            A.y + t * (B.y - A.y)
        };

        if (is_point_on_segment(intersection, line1) && is_point_on_segment(intersection, line2)) {
            return intersection;
        }

        return std::nullopt;
    }


    std::vector<Point> find_all_intersections(Triangle &t1, Triangle &t2) {
        std::set<Point> unique_intersections;
        std::vector<Line> lines1 = t1.get_lines();
        std::vector<Line> lines2 = t2.get_lines();

        for (auto &line1 : lines1) {
            for (auto &line2 : lines2) {
                if (auto intersection = find_point_of_intersection(line1, line2)) {
                    unique_intersections.insert(*intersection);
                }
            }
        }

        for (const auto &vertex : {lines1[0].get_start_point(), lines1[1].get_start_point(), lines1[2].get_start_point()}) {
            if (is_point_in_triangle(vertex, t2) && unique_intersections.find(vertex) == unique_intersections.end()) {
                unique_intersections.insert(vertex);
            }
        }

        for (const auto &vertex : {lines2[0].get_start_point(), lines2[1].get_start_point(), lines2[2].get_start_point()}) {
            if (is_point_in_triangle(vertex, t1) && unique_intersections.find(vertex) == unique_intersections.end()) {
                unique_intersections.insert(vertex);
            }
        }

        return std::vector<Point>(unique_intersections.begin(), unique_intersections.end());
    }

    bool is_point_in_triangle(const Point &p, const Triangle &t) {
        std::vector<Line> edges = t.get_lines();
        Point a = edges[0].get_start_point();
        Point b = edges[1].get_start_point();
        Point c = edges[2].get_start_point();

        double v0x = c.x - a.x, v0y = c.y - a.y;
        double v1x = b.x - a.x, v1y = b.y - a.y;
        double v2x = p.x - a.x, v2y = p.y - a.y;

        double dot00 = v0x * v0x + v0y * v0y;
        double dot01 = v0x * v1x + v0y * v1y;
        double dot02 = v0x * v2x + v0y * v2y;
        double dot11 = v1x * v1x + v1y * v1y;
        double dot12 = v1x * v2x + v1y * v2y;

        double inv_denom = 1.0 / (dot00 * dot11 - dot01 * dot01);
        double u = (dot11 * dot02 - dot01 * dot12) * inv_denom;
        double v = (dot00 * dot12 - dot01 * dot02) * inv_denom;

        const double epsilon = 1e-9;
        return (u >= -epsilon) && (v >= -epsilon) && (u + v <= 1 + epsilon);
    }   


    bool is_point_on_segment(const Point& intersection, const Line& line) {
        double minX = std::min(line.get_start_point().x, line.get_end_point().x);
        double maxX = std::max(line.get_start_point().x, line.get_end_point().x);
        double minY = std::min(line.get_start_point().y, line.get_end_point().y);
        double maxY = std::max(line.get_start_point().y, line.get_end_point().y);

        double cross_product = (intersection.y - line.get_start_point().y) * (line.get_end_point().x - line.get_start_point().x) -
                       (intersection.x - line.get_start_point().x) * (line.get_end_point().y - line.get_start_point().y);

        if (std::abs(cross_product) > 1e-9) {
            return false;
}

        double dot_product = (intersection.x - line.get_start_point().x) * (line.get_end_point().x - line.get_start_point().x) +
                             (intersection.y - line.get_start_point().y) * (line.get_end_point().y - line.get_start_point().y);

        if (dot_product < 0) {
            return false;
        }

        double squared_length = std::pow(line.get_end_point().x - line.get_start_point().x, 2) +
                                std::pow(line.get_end_point().y - line.get_start_point().y, 2);

        return dot_product <= squared_length;
    }
};

#endif // INTERSECTION_CHECH_H