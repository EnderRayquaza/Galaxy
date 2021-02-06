#pragma once
#include "config.h"

#include "Star.h"

//class Star;

class Node
{
public :
	Node();
	Node(double posx, double posy, double posz, double posx2, double posy2, double posz2);

	std::array<sf::Vector3f, 2> get_pos();
	sf::RectangleShape get_img_xy();
	sf::RectangleShape get_img_xz();
	sf::RectangleShape get_img_yz();

private:
	sf::RectangleShape m_img;
	sf::Vector3f m_posA;
	sf::Vector3f m_posB;
	double m_width;
	double m_height;
	double m_axe_z;
};