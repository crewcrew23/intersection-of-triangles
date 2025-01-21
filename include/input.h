#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <vector>
#include "point.h"

class Input {
public:
    Input() = default;
    ~Input() = default;

    void inputPoints(std::vector<Point>& points1, std::vector<Point>& points2) {
        for (int i = 0; i < 6; ++i) {
            Point p;
            std::cin >> p.x >> p.y;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                --i;
                continue;
            }

            points1.push_back(p);
        }

        for (int i = 0; i < 6; ++i) {
            Point p;
            std::cin >> p.x >> p.y;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                --i;
                continue;
            }

            points2.push_back(p);
        }
    }
};

#endif //INPUT_H