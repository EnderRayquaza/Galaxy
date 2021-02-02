#pragma once
#include "config.h"
#include "Star.h"

int main()
{
    if (NB_STAR+NB_BH < 1)
        return 1;
	sf::RenderWindow win(sf::VideoMode(WIDTH, HEIGHT), "Galaxie");
    std::vector<Star> vecStar;

    for (size_t i(0); i < NB_STAR+NB_BH; i++)
    {
        if (i < NB_STAR)
            vecStar.push_back(Star(random(WIDTH / 16., 14 * WIDTH / 16.), random(HEIGHT / 16., 14 * HEIGHT / 16.), 
                random(AXE_Z / 16., 14 * AXE_Z / 16.), i));
        else
            vecStar.push_back(Star(random(WIDTH / 16., 14 * WIDTH / 16.), random(HEIGHT / 16., 14 * HEIGHT / 16.),
                random(AXE_Z / 16., 14 * AXE_Z / 16.), i, true));
    }

	while (win.isOpen())
	{
        sf::Event ev;
        while (win.pollEvent(ev))
        {
            if (ev.type == sf::Event::Closed)
                win.close();
        }

        win.clear(sf::Color::Black);

        for (size_t i(0); i < vecStar.size(); i++)
        {
            vecStar[i].update_speed(vecStar);
        }
        for (size_t i(0); i < vecStar.size(); i++)
        {
            vecStar[i].move();
            win.draw(vecStar[i].get_img());
        }
        //std::cout << "________________" << std::endl;
        win.display();
	}
    return 0;
}