﻿#include "func.h"

int random(int a, int b)
{
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> disr(a, b);
    int r(disr(eng));
    return r;
}

int fake_random(int a, int b)
{
    int r = a + rand()%b;
    return r;
}

double average(std::vector<double> vec)
{
    double Σ(0);
    for (int i(0); i < vec.size(); i++)
        Σ += vec[i];
    Σ /= vec.size();
    return Σ;
}

double averageWithoutIndex(std::vector<double> vec, int index)
{
    if (index > vec.size())
    {
        std::cout << "Index too big !" << std::endl;
        return 1;
    }
    if (vec.size() <= 1)
    {
        return 1;
    }
    double Σ(0);
    for (int i(0); i < vec.size(); i++)
        if(i != index)
            Σ += vec[i];
    Σ /= vec.size()-1;
    std::cout << "Σ : " << Σ << std::endl;
    return Σ;
}

int vecInt2int(std::vector<int> int_)
{
    int rtrn(0);
    std::string str;
    for (int i(0); i < int_.size(); i++)
        str += std::to_string(int_[i]);
    rtrn = stoi(str, 0, 2);
    return rtrn;
}

std::array<Node, 8> create8nodes(Node mainNode, int lvl)
{
    std::array<Node, 8> rtrn;
    for (int i(0); i < 2; i++)
        for (int j(0); j < 2; j++)
            for (int k(0); k < 2; k++)
            {
                rtrn[vecInt2int({ i, j, k })] = Node();
            }
    return rtrn;
}

void createOctree(std::vector<Star> vStar)
{
    Node Octree(0, 0, 0, WIDTH, HEIGHT, AXE_Z);
    for (int i(0); i < NB_STAR; i++)
    {
        insert(vStar[i], Octree, vStar);
    }
    deleteLeaves(Octree);
}

void insert(Star i, Node node, std::vector<Star> vStar)
{
    int nbStar(0);
    for (int i(0); i < NB_STAR; i++)
    {
    if (((node.get_pos()[0].x <= vStar[i].get_pos().x && vStar[i].get_pos().x < node.get_pos()[1].x) &&
         (node.get_pos()[0].y <= vStar[i].get_pos().y && vStar[i].get_pos().y < node.get_pos()[1].y) &&
         (node.get_pos()[0].z <= vStar[i].get_pos().z && vStar[i].get_pos().z < node.get_pos()[1].z)))
        nbStar++;
    }
    if (nbStar > 1)
    {
        int c(0);
        insert(i, c);
    }
    else if (true)
    {
        //ajouter 8 fils au noeud n dans l’octTree
        //mettre la particule déjà dans n dans le fils correspondant
        int c(0);
        insert(i, c);
    }
    else if (true)
    {
        //ranger la particule i dans le noeud n
    }
}