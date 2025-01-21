#include <iostream>
#include <vector>
#include <ios>

#include "../include/point.h"
#include "../include/line.h"
#include "../include/triangle.h"
#include "../include/input.h"
#include "../include/intersection_check.h"


int main(){

	std::vector<Point> points1;
    std::vector<Point> points2;

    Input input;
    input.inputPoints(points1, points2);

    Line line1_1(points1[0], points1[1]);
    Line line2_1(points1[2], points1[3]);
    Line line3_1(points1[4], points1[5]);

    Line line1_2(points2[0], points2[1]);
    Line line2_2(points2[2], points2[3]);
    Line line3_2(points2[4], points2[5]);

    Triangle triangle_1(line1_1, line2_1, line3_1);
    Triangle triangle_2(line1_2, line2_2, line3_2);

    IntersectionCheck intersection_check;
    std::cout << std::boolalpha << intersection_check.check(triangle_1, triangle_2) << std::endl;
	return 0;
}
