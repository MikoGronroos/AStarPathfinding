#pragma once

#include <iostream>
#include <cmath>
#include <vector>
#include "Pathfinding.h"

class Example1 {
public:

    Map map = Map(25, 25);

    int Execute() {
        std::cout << "Determine Start and End nodes" << std::endl;
        Node* startNode = map.GetNode(5, 5);
        Node* endNode = map.GetNode(13, 24);

        map.GetNode(6, 5)->isBlocked = true;
        map.GetNode(5, 6)->isBlocked = true;
        map.GetNode(13, 23)->isBlocked = true;

        map.GetNode(12, 7)->isBlocked = true;
        map.GetNode(11, 7)->isBlocked = true;
        map.GetNode(10, 7)->isBlocked = true;
        map.GetNode(9, 7)->isBlocked = true;
        map.GetNode(8, 7)->isBlocked = true;
        map.GetNode(7, 7)->isBlocked = true;
        map.GetNode(6, 7)->isBlocked = true;
        map.GetNode(5, 7)->isBlocked = true;
        map.GetNode(4, 7)->isBlocked = true;
        map.GetNode(3, 7)->isBlocked = true;
        map.GetNode(2, 7)->isBlocked = true;
        map.GetNode(1, 7)->isBlocked = true;
        map.GetNode(0, 7)->isBlocked = true;

        std::cout << "End and start node determined" << std::endl;
        std::cout << "Calculating costs" << std::endl;
        std::vector<Node*> path = GetRoute(startNode, endNode);
        std::cout << "Route Gotten" << std::endl;
        for (int x = 0; x < map.width; x++)
        {
            for (int y = 0; y < map.height; y++)
            {
                bool isInPath = false;
                Node* node = map.GetNode(x, y);
                for (int i = 0; i < path.size(); i++) {
                    if (path[i]->x == x && path[i]->y == y) {
                        isInPath = true;
                        break;
                    }
                }
                if (startNode->x == x && startNode->y == y) {
                    std::cout << "s " << " |";
                }
                else if (endNode->x == x && endNode->y == y) {
                    std::cout << "e " << " |";
                }
                else if (isInPath) {
                    std::cout << "x " << " |";
                }
                else if (node->isBlocked) {
                    std::cout << "B " << " |";
                }
                else {
                    std::cout << "o " << " |";
                }
            }
            std::cout << std::endl;
        }

        return 0;
    }


};