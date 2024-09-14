#pragma once

#include <iostream>
#include <cmath>
#include <vector>
#include "Pathfinding.h"

class Example1 {
public:
    std::vector<Node*> map;
    int width = 10;
    int height = 10;
    Node* GetNode(int x, int y) {
        if (x > width || x < 0 || y > height || y < 0) {
            return NULL;
        }
        for (int i = 0; i < map.size(); i++) {
            if (map[i]->x == x && map[i]->y == y) {
                return map[i];
            }
        }
        return NULL;
    }

    void CreateMap() {
        int index = 0;

        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                Node* node = new Node();
                node->x = i;
                node->y = j;
                index++;
                map.push_back(node);
            }
        }
        for (int i = 0; i < map.size(); i++) {
            Node* node = map[i];
            int x = node->x;
            int y = node->y;
            Node* previous = GetNode(x + 1, y);
            if (previous != nullptr) {
                node->nextNodes.push_back(previous);
            }
            previous = nullptr;
            previous = GetNode(x, y + 1);
            if (previous != nullptr) {
                node->nextNodes.push_back(previous);
            }
            previous = nullptr;
            previous = GetNode(x - 1, y);
            if (previous != nullptr) {
                node->nextNodes.push_back(previous);
            }
            previous = nullptr;
            previous = GetNode(x, y - 1);
            if (previous != nullptr) {
                node->nextNodes.push_back(previous);
            }
        }
    }


    int Execute() {

        std::cout << "Creating map" << std::endl;
        CreateMap();

        std::cout << "Map created" << std::endl;

        std::cout << "Determine Start and End nodes" << std::endl;
        Node* startNode = GetNode(5, 5);
        Node* endNode = GetNode(9, 9);

        GetNode(6, 5)->isBlocked = true;
        GetNode(5, 6)->isBlocked = true;

        std::cout << "End and start node determined" << std::endl;
        std::cout << "Calculating costs" << std::endl;
        std::vector<Node*> path = GetRoute(startNode, endNode);
        std::cout << "Route Gotten" << std::endl;
        for (int x = 0; x < width; x++)
        {
            for (int y = 0; y < height; y++)
            {
                bool isInPath = false;
                Node* node = GetNode(x, y);
                for (int i = 0; i < path.size(); i++) {
                    if (path[i]->x == x && path[i]->y == y) {
                        isInPath = true;
                        break;
                    }
                }
                if (startNode->x == x && startNode->y == y) {
                    std::cout << "s |";
                }
                else if (endNode->x == x && endNode->y == y) {
                    std::cout << "e |";
                }
                else if (isInPath) {
                    std::cout << "x |";
                }
                else if (node->isBlocked) {
                    std::cout << "B |";
                }
                else {
                    std::cout << "o |";
                }
            }
            std::cout << std::endl;
        }

        return 0;
    }


};