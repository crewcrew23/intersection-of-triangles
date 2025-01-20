#include <iostream>
#include <vector>

#include "../include/point.h"
#include "../include/line.h"
#include "../include/triangle.h"
#include "../include/input.h"


int main(){
	std::vector<Point> points;
	//(0 0), (0 1), (0 1), (1 0), (0 0), (1 0)
	Input input;
	input.inputPoints(points);

	Line line1_1(points[0], points[1]);
	Line line2_1(points[2], points[3]);
	Line line3_1(points[4], points[5]);

	Point p1(1,0); 
	Point p2(1,1);

	Point p3(1,1); 
	Point p4(0,0);

	Point p5(1,0); 
	Point p6(0,0);

	Line line1_2(p1,p2);
	Line line2_2(p3, p4);
	Line line3_2(p5, p6);
	
	Triangle triangle_1(line1_1, line2_1, line3_1);
	Triangle triangle_2(line1_2, line2_2, line3_2);

	std::cout << triangle_1.square() << std::endl;
	std::cout << triangle_2.square() << std::endl;

	return 0;
}
