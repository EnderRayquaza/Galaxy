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

std::array<Node, 8> create8nodes(Node mainNode, int lvl);

void createOctree(std::vector<Star> vStar);

void insert(Star star, int octree);

void deleteLeaves(int octree);