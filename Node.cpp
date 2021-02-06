#include "Node.h"

Node::Node(double posx, double posy, double posz, double posx2, double posy2, double posz2)
{
	m_posA = sf::Vector3f(posx, posy, posz);
	m_posB = sf::Vector3f(posx2, posy2, posz2);
	m_img = sf::RectangleShape(sf::Vector2f(posx2-posx, posy2-posy));
	m_img.setFillColor(sf::Color::Black);
	m_img.setOutlineThickness(2);
	m_img.setOutlineColor(sf::Color::Yellow);
}

std::array<sf::Vector3f, 2> Node::get_pos() { return std::array<sf::Vector3f, 2> {m_posA, m_posB}; }

sf::RectangleShape Node::get_img_xy() { m_img.setPosition(sf::Vector2f(m_posA.x, m_posA.y)); return m_img; }

sf::RectangleShape Node::get_img_xz() { m_img.setPosition(sf::Vector2f(m_posA.x, m_posA.z)); return m_img; }

sf::RectangleShape Node::get_img_yz() { m_img.setPosition(sf::Vector2f(m_posA.y, m_posA.z)); return m_img; }
