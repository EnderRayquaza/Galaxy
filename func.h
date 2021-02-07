#pragma once
#include "config.h"
#include "Star.h"
#include "Node.h"

class Star;
class Node;

int random(int a, int b);

int fake_random(int a, int b);

double average(std::vector<double> vec);

double averageWithoutIndex(std::vector<double> vec, int index);

int vecInt2int(std::vector<int> int_);

std::array<Node, 8> create8nodes(Node mainNode);

Node createOctree(std::vector<Star> vStar);

void insert(Star i, Node node, std::vector<Star> vStar);

Node findChild(Node node, Star star);

void deleteLeaves(Node octree);

std::vector<sf::RectangleShape> displayOctree(Node Octree, int axe);

std::vector<Node> TestOctree(Node);