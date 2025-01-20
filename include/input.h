#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <vector>
#include "point.h"
#include "line.h"


class Input
{
public:
    Input() = default;
    ~Input() = default;

    void inputPoints(std::vector<Point>& points) {
	std::cout << std::endl;
    for (int i = 0; i < 6; ++i) {
        Point p;
        std::cout << "Введите координаты точки " << (i + 1) << " (формат: x y): ";
        std::cin >> p.x >> p.y;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректный ввод. Попробуйте еще раз.\n";
            --i;
            continue;
        }

        points.push_back(p);
    }
}};



#endif