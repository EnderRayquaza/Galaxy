#pragma once

#include "config.h"

class Block;

class Star
{
public:
	Star(double posx, double posy, double posz, int index, bool BlckH = false);

	void update_speed(std::vector<Star> vStar);
	void move();
	bool destroy(bool force = false);

	int get_index();
	sf::CircleShape get_img();
	sf::Vector3f get_pos();
	long double get_mass();
	long double get_acc();
	bool get_BlckH();

protected:
	int m_index;
	sf::Vector3f m_pos; //Position
	sf::Vector3f m_old_pos; //Position à l'étape précédente
	sf::Vector3f m_dir; //Direction
	sf::CircleShape m_img;
	long double m_mass;
	long double m_acc; //Accélération
	bool m_BlckH; //Si est un Trou Noir
	bool m_is_dead; //Si est sortie en dehors de l'écran
};

