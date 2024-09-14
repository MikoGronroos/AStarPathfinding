#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include "Pathfinding.h"


class Example2 {
public:
    int Execute() {
        Node startNode;
        startNode.x = 1;
        startNode.y = 1;
        startNode.id = "Start";
        Node endNode;
        endNode.id = "End";
        endNode.x = 19;
        endNode.y = 6;
        endNode.hCost = 0;
        endNode.fCost = 0;
        endNode.gCost = 0;

        Node node3;
        node3.x = 8;
        node3.y = 6;
        node3.gCost = calculate_distance(&startNode, &node3);
        node3.hCost = calculate_distance(&endNode, &node3);
        node3.fCost = node3.gCost + node3.hCost;
        node3.id = "Node3";
        node3.nextNodes.push_back(&endNode);

        Node node5;
        node5.x = -20;
        node5.y = 0;
        node5.gCost = calculate_distance(&startNode, &node5);
        node5.hCost = calculate_distance(&endNode, &node5);
        node5.fCost = node5.gCost + node5.hCost;
        node5.id = "Node5";
        node5.nextNodes.push_back(&endNode);

        Node node4;
        node4.x = 7;
        node4.y = -2;
        node4.gCost = calculate_distance(&startNode, &node4);
        node4.hCost = calculate_distance(&endNode, &node4);
        node4.fCost = node4.gCost + node4.hCost;
        node4.id = "Node4";
        node4.nextNodes.push_back(&node3);

        node3.nextNodes.push_back(&node4);

        Node node1;
        node1.x = 2;
        node1.y = 2;
        node1.gCost = calculate_distance(&startNode, &node1);
        node1.hCost = calculate_distance(&endNode, &node1);
        node1.fCost = node1.gCost + node1.hCost;
        node1.id = "Node1";
        node1.nextNodes.push_back(&node4);
        node1.nextNodes.push_back(&startNode);

        node3.nextNodes.push_back(&node4);
        node4.nextNodes.push_back(&node1);

        Node node2;
        node2.x = 3;
        node2.y = 5;
        node2.gCost = calculate_distance(&startNode, &node2);
        node2.hCost = calculate_distance(&endNode, &node2);
        node2.fCost = node2.gCost + node2.hCost;
        node2.id = "Node2";
        node2.nextNodes.push_back(&node5);
        node2.nextNodes.push_back(&startNode);

        node5.nextNodes.push_back(&node2);

        startNode.nextNodes.push_back(&node1);
        startNode.nextNodes.push_back(&node2);

        node1.previousNode = &startNode;
        node2.previousNode = &startNode;

        std::vector<Node*> path = GetRoute(&startNode, &endNode);

        for (int i = 0; i < path.size(); i++) {
            std::cout << path[i]->id << std::endl;
        }
        return 0;
    }
};
