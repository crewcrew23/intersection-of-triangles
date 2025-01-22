#include <iostream>
#include <vector>

#include "../include/point.h"
#include "../include/line.h"
#include "../include/triangle.h"
#include "../include/intersection_check.h"


void test_case_1(IntersectionCheck* intersection_check){
    Point p1(0, 0);
    Point p2(1, 0);
    Point p3(1, 0);
    Point p4(0, 1);
    Point p5(0, 0);
    Point p6(0, 1);

    Point p7(0.5, 0);
    Point p8(1, 0.5);
    Point p9(1, 0.5);
    Point p10(0, 1);
    Point p11(0.5, 0);
    Point p12(0, 1);

    Line line1 (p1, p2); 
    Line line2 (p3, p4); 
    Line line3 (p5, p6); 

    Line line4 (p7, p8); 
    Line line5 (p9, p10); 
    Line line6 (p11, p12); 

    //Треугольник 1: вершины (0,0), (0,1), (1,0)
    Triangle t1(line1, line2, line3);

    // Треугольник 2: вершины (0.5, 0), (1, 0.5), (0, 1)
    Triangle t2(line4, line5, line6);

    // Ожидаемые пересечения: (0, 1), (0.5, 0), (0.75, 0.25)
    std::vector<Point> intersections =  intersection_check->find_all_intersections(t1, t2);

    bool test_pass_condition = (intersections[0].x == 0 && intersections[0].y == 1) &&
                               (intersections[1].x == 0.5 && intersections[1].y == 0) &&
                               (intersections[2].x == 0.75 && intersections[2].y == 0.25);    

    if (test_pass_condition){
        std::cout << "\033[32mTest case 1 pass\033[0m\n";
    }else{
        std::cout << "\033[1;31mTest case 1 failed\033[0m\n" << std::endl;
        
        std::cout << "Value:\n" << std::endl;
        for (Point& p: intersections )
        {
            std::cout << "\t Point: (" << p.x << ", " << p.y << ")" << std::endl;
        }
    }
    
}

void test_case_2(IntersectionCheck* intersection_check){
    Point p1(0, 0);
    Point p2(0, 1);
    Point p3(0, 1);
    Point p4(1, 0);
    Point p5(0, 0);
    Point p6(1, 0);

    Point p7(1, 0);
    Point p8(1, 1);
    Point p9(1, 1);
    Point p10(0, 0);
    Point p11(1, 0);
    Point p12(0, 0);

    Line line1 (p1, p2); 
    Line line2 (p3, p4); 
    Line line3 (p5, p6); 

    Line line4 (p7, p8); 
    Line line5 (p9, p10); 
    Line line6 (p11, p12); 

     //Треугольник 1: вершины (0,0), (0,1), (1,0)
    Triangle t1(line1, line2, line3);

     //Треугольник 2: вершины (1,0), (1,1), (0,1)
    Triangle t2(line4, line5, line6);

    // Ожидаемые пересечения: (0, 0), (0.5, 0.5), (1, 0)
    std::vector<Point> intersections =  intersection_check->find_all_intersections(t1, t2);

    bool test_pass_condition = (intersections[0].x == 0 && intersections[0].y == 0) &&
                               (intersections[1].x == 0.5 && intersections[1].y == 0.5) &&
                               (intersections[2].x == 1 && intersections[2].y == 0);    

    if (test_pass_condition){
        std::cout << "\033[32mTest case 2 pass\033[0m\n";
    }else{
        std::cout << "\033[1;31mTest case 2 failed\033[0m\n" << std::endl;
        
        std::cout << "Value:\n" << std::endl;
        for (Point& p: intersections )
        {
            std::cout << "\t Point: (" << p.x << ", " << p.y << ")" << std::endl;
        }
    }
    
}

void test_case_3(IntersectionCheck* intersection_check) {
    Point p1(0, 0);
    Point p2(1, 0);
    Point p3(0, 1);

    Point p4(2, 2);
    Point p5(3, 2);
    Point p6(2, 3);

    Line line1(p1, p2);
    Line line2(p2, p3);
    Line line3(p3, p1);

    Line line4(p4, p5);
    Line line5(p5, p6);
    Line line6(p6, p4);

    Triangle t1(line1, line2, line3);
    Triangle t2(line4, line5, line6);

    std::vector<Point> intersections = intersection_check->find_all_intersections(t1, t2);

    bool test_pass_condition = intersections.empty();

    if (test_pass_condition) {
        std::cout << "\033[32mTest case 3 pass\033[0m\n";
    } else {
        std::cout << "\033[1;31mTest case 3 failed\033[0m\n" << std::endl;
        
        std::cout << "Value:\n" << std::endl;
        for (Point& p: intersections) {
            std::cout << "\t Point: (" << p.x << ", " << p.y << ")" << std::endl;
        }
    }
}

int main(){
    IntersectionCheck intersection_check;
    test_case_1(&intersection_check);
    test_case_2(&intersection_check);
    test_case_3(&intersection_check);
    return 0;
}
