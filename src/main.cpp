#include <iostream>
#include <vector>
#include <ios>

#include "../include/point.h"
#include "../include/line.h"
#include "../include/triangle.h"
#include "../include/input.h"
#include "../include/intersection_check.h"


int main(){
    
    Input input;
    IntersectionCheck intersection_check;

	std::vector<Point> points1;
    std::vector<Point> points2;

    input.inputPoints(points1, points2);

    Line line1_1(points1[0], points1[1]);
    Line line2_1(points1[2], points1[3]);
    Line line3_1(points1[4], points1[5]);

    Line line1_2(points2[0], points2[1]);
    Line line2_2(points2[2], points2[3]);
    Line line3_2(points2[4], points2[5]);

    Triangle* triangle_1{nullptr};
    Triangle* triangle_2{nullptr};

    try{
        triangle_1 = new Triangle(line1_1, line2_1, line3_1);
        triangle_2 = new Triangle(line1_2, line2_2, line3_2);
    }catch(std::runtime_error const& e){
        std::cerr << "\033[1;31mException: " << e.what() << "\033[0m\n";
    }

     std::vector<Point> intersection = intersection_check.find_all_intersections(*triangle_1, *triangle_2);

   std::cout << "Intersection: [\n";
    for (const auto &p : intersection)
    {
        std::cout << "\tPoint: (X: " << p.x << ", Y: " << p.y << ")\n";
    }
    std::cout << "]\n";

    delete triangle_1;
    delete triangle_2;
	return 0;

}
