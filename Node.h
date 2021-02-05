#pragma once
#include "config.h"

#include "Star.h"

//class Star;

class Node
{
public :
	Node();
	Node(int lvl, double posx, double posy, double posz);

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
	sf::Vector3f m_posMass;
	double m_mass;
	int m_lvl;
	//Star m_star;
	bool m_is_leave;
};