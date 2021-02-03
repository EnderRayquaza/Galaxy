#include "Node.h"

Node::Node(int lvl, double posx, double posy, double posz)
{
	m_lvl = lvl;
	m_width = WIDTH / m_lvl;
	m_height = HEIGHT / m_lvl;
	m_axe_z = AXE_Z / m_lvl;
	m_posA = sf::Vector3f(posx, posy, posz);
	m_posB = sf::Vector3f(posx+m_width, posy+m_height, posz+m_axe_z);
	m_img = sf::RectangleShape(sf::Vector2f(m_width, m_height));
	m_img.setOutlineThickness(2);
	m_img.setOutlineColor(sf::Color::Yellow);
	m_star = Star(-1, -1, -1, -1);
}