#include "Node.h"

Node::Node()
{
	m_img = sf::RectangleShape();
	m_posA = { -1, -1, -1 };
	m_posB = m_posA;
	m_width = -1;
	m_height = -1;
	m_axe_z = -1;
	m_posMass = m_posA;
	m_mass= -1;
	m_lvl = -1;
	//Star m_star;
	m_is_leave = false;
}

Node::Node(int lvl, double posx, double posy, double posz)
{
	if (lvl != 0)
		m_lvl = lvl;
	else
		lvl = 1;
	m_width = WIDTH / m_lvl;
	m_height = HEIGHT / m_lvl;
	m_axe_z = AXE_Z / m_lvl;
	m_posA = sf::Vector3f(posx, posy, posz);
	m_posB = sf::Vector3f(posx+m_width, posy+m_height, posz+m_axe_z);
	m_img = sf::RectangleShape(sf::Vector2f(m_width, m_height));
	m_img.setFillColor(sf::Color::Black);
	m_img.setOutlineThickness(2);
	m_img.setOutlineColor(sf::Color::Yellow);
	//m_star = Star(-1, -1, -1, -1);
	m_posMass = { 0, 0, 0 };
	m_mass = 0;
	m_is_leave = false;
}

std::array<sf::Vector3f, 2> Node::get_pos() { return std::array<sf::Vector3f, 2> {m_posA, m_posB}; }

sf::RectangleShape Node::get_img() { m_img.setPosition(sf::Vector2f(m_posA.x, m_posA.y)); return m_img; }