#include "Node.h"

Node::Node(double posx, double posy, double posz, double posx2, double posy2, double posz2)
{
	m_posA = sf::Vector3f(posx, posy, posz);
	m_posB = sf::Vector3f(posx2, posy2, posz2);
	m_img.setFillColor(sf::Color::Black);
	m_img.setOutlineThickness(2);
	m_img.setOutlineColor(sf::Color::Yellow);
}

Node::Node(Node& father, int i, int j, int k)
{
	m_posA = {
	i * father.get_pos()[1].x / 2.,
	j * father.get_pos()[1].y / 2.,
	k * father.get_pos()[1].z / 2.
	};
	m_posB = {
		father.get_pos()[1].x / 2. + i * father.get_pos()[1].x / 2.,
		father.get_pos()[1].y / 2. + j * father.get_pos()[1].y / 2.,
		father.get_pos()[1].z / 2. + k * father.get_pos()[1].z / 2.
	};
	m_father = { father };
	m_img.setFillColor(sf::Color::Black);
	m_img.setOutlineThickness(2);
	m_img.setOutlineColor(sf::Color::Yellow);
}

void Node::add_star(Star star) { m_star = star; }

void Node::add_child(std::array<Node, 8> childs) { m_childs = childs; }

std::array<sf::Vector3f, 2> Node::get_pos() { return std::array<sf::Vector3f, 2> {m_posA, m_posB}; }

sf::RectangleShape Node::get_img_xy() 
{
	m_img = sf::RectangleShape(sf::Vector2f(m_posB.x - m_posA.x, m_posB.y - m_posA.y));
	m_img.setPosition(sf::Vector2f(m_posA.x, m_posA.y));
	return m_img; 
}

sf::RectangleShape Node::get_img_xz() 
{ 
	m_img = sf::RectangleShape(sf::Vector2f(m_posB.x - m_posA.x, m_posB.z - m_posA.z));
	m_img.setPosition(sf::Vector2f(m_posA.x, m_posA.z));
	return m_img;
}

sf::RectangleShape Node::get_img_yz()
{
	m_img = sf::RectangleShape(sf::Vector2f(m_posB.y - m_posA.y, m_posB.z - m_posA.z));
	m_img.setPosition(sf::Vector2f(m_posA.y, m_posA.z));
	return m_img; 
}

std::array<Node, 8> Node::get_childs() { return m_childs; }