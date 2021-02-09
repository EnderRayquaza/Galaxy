#pragma once
#include "config.h"
#include "Star.h"

class Star;

class Node
{
public :
	Node();
	Node(double posx, double posy, double posz, double posx2, double posy2, double posz2);
	Node(Node &father, int i, int j, int k);

	void add_star(Star star);
	void add_child(std::array<Node, 8> childs);

	std::array<sf::Vector3f, 2> get_pos();
	sf::RectangleShape get_img_xy();
	sf::RectangleShape get_img_xz();
	sf::RectangleShape get_img_yz();
	std::array<Node, 8> get_childs();

private:
	sf::RectangleShape m_img;
	sf::Vector3f m_posA;
	sf::Vector3f m_posB;
	double m_width;
	double m_height;
	double m_axe_z;
	Star *m_star;
	std::vector<Node> m_father;
	std::array<Node, 8> *m_childs;
};