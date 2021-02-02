#include "Star.h"

Star::Star(double posx, double posy, double posz, int index, bool BlckH)
{
	m_index = index;
	m_pos = sf::Vector3f(posx, posy, posz);
	m_old_pos = m_pos;
	m_acc = 0;
	m_dir = { 0, 0, 0 };
	m_mass = (random(8, 3000) / 10) * SOLAR_MASS; //La masse moyenne des étoiles 
	//est comprise entre 0.8x et 300x celle du soleil
	if (RAD * m_mass / SOLAR_MV < 2) 
		m_img = sf::CircleShape(2);
	else
		m_img = sf::CircleShape(RAD * m_mass / SOLAR_MV); //Calcul de la taille de 
	//l'etoile en fx de la masse volumique.
	if (BlckH)
	{
		m_mass *= 1 * pow(10, 9);
		m_img = sf::CircleShape(10);
		m_img.setFillColor(sf::Color(0, 0, 0)); //Noir
		m_img.setOutlineThickness(1.f);
		m_img.setOutlineColor(sf::Color(255, 155, 5)); //Orange
	}
	else
	{
		//m_img.setFillColor(sf::Color(0, 64, 128)); //Bleu Foncé
		m_img.setFillColor(sf::Color::White);
	}
	m_BlckH = BlckH;
	m_is_dead = false;
}

int Star::get_index() { return m_index; }

sf::CircleShape Star::get_img() { m_img.setPosition(sf::Vector2f(m_pos.x, m_pos.y));  return m_img; }

sf::Vector3f Star::get_pos() { return m_pos; }

long double Star::get_mass() { return m_mass; }

long double Star::get_acc() { return m_acc; }

bool Star::get_BlckH() { return m_BlckH; }

void Star::update_speed(std::vector<Star> vStar)
{
	/*
	Calcul de l'accélération de l'étoile selon les lois Newtoniennes.
	*/
	std::vector<sf::Vector3f> vec_tot;
	sf::Vector3f vec;
	double f(0), d(0), Σf(0);
	for (size_t i(0); i < vStar.size(); i++)
	{
		if (vStar[i].m_index != m_index && !vStar[i].m_is_dead) 
			//Si l'étoile est differente d'elle même et si elle n'est pas morte
		{
			vec = { vStar[i].m_pos.x - m_pos.x, vStar[i].m_pos.y - m_pos.y, vStar[i].m_pos.z - m_pos.z};
			d = sqrt(std::pow(vec.x, 2) + std::pow(vec.y, 2) + std::pow(vec.z, 2))*LY;
			if(d != 0)
				f = m_mass * vStar[i].m_mass * G / std::pow(d, 2);
			Σf += f;
			vec_tot.push_back(vec);
		}
	}
	double vx(0), vy(0), vz(0);
	for (size_t i(0); i < vec_tot.size(); i++)
	{
		vx += vec_tot[i].x;
		vy += vec_tot[i].y;
		vz += vec_tot[i].z;
	}
	if (vec_tot.size() != 0)
	{
		m_dir.x = vx / vec_tot.size();
		m_dir.y = vy / vec_tot.size();
		m_dir.z = vz / vec_tot.size();
	}

	if (m_mass == 0)
		m_acc = 0;
	else
		m_acc = Σf / m_mass;
}

void Star::move()
{
	if (Δt != 0)
	{
		auto temp(m_pos);
		m_pos.x = 2 * m_pos.x - m_old_pos.x + m_acc * Δt * Δt * m_dir.x; //Integration de Verlet
		m_pos.y = 2 * m_pos.y - m_old_pos.y + m_acc * Δt * Δt * m_dir.y;
		m_pos.z = 2 * m_pos.z - m_old_pos.z + m_acc * Δt * Δt * m_dir.z;
		m_old_pos = temp;
	}
}

bool Star::destroy(bool force)
{
	if (m_pos.x < 0 || m_pos.x > WIDTH || m_pos.y < 0 || m_pos.y > HEIGHT 
		|| m_pos.z < 0 || m_pos.z > AXE_Z || force)
	{
		m_mass = 0;
		m_pos = { WIDTH/2., HEIGHT/2., AXE_Z/2. };
		m_old_pos = m_pos;
		m_img = sf::CircleShape(0);
		m_is_dead = true;
		std::cout << m_index << "(" << m_BlckH << ") : Boom !" << std::endl;
		return true;
	}
	return false;
}