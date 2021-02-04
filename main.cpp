#pragma once
#include "config.h"
#include "Star.h"
#include "Node.h"

int main()
{
    if (NB_STAR+NB_BH < 1)
        return 1;
	sf::RenderWindow win(sf::VideoMode(WIDTH, HEIGHT), "Galaxie");
    std::vector<Star> vecStar;
    std::vector<Node> vecNode;

    for (size_t i(0); i < NB_STAR+NB_BH; i++)
    {
        if (i < NB_STAR)
            vecStar.push_back(Star(random(WIDTH / 16., 14 * WIDTH / 16.), random(HEIGHT / 16., 14 * HEIGHT / 16.), 
                random(AXE_Z / 16., 14 * AXE_Z / 16.), i));
        else
            vecStar.push_back(Star(random(WIDTH / 16., 14 * WIDTH / 16.), random(HEIGHT / 16., 14 * HEIGHT / 16.),
                random(AXE_Z / 16., 14 * AXE_Z / 16.), i, true));
    }

    std::vector<Node> vNode;
    vecNode = createOctree(vecStar, vNode, Node(1, 0, 0, 0), 2);
    std::cout << "Nb noeuds : " << vecNode.size() << std::endl;
    bool axe(false);
    std::cout << "Axe :" << axe << std::endl;
	while (win.isOpen())
	{
        sf::Event ev;
        while (win.pollEvent(ev))
        {
            if (ev.type == sf::Event::Closed)
                win.close();
            else if (ev.type == sf::Event::KeyPressed)
            {
                if (axe)
                    axe = false;
                else
                    axe = true;
                std::cout << "Axe :" << axe << std::endl;
            }

        }

        win.clear(sf::Color::Black);
        for (size_t i(0); i < vecStar.size(); i++)
        {
            vecStar[i].update_speed(vecStar);
        }
        for (size_t i(0); i < vecNode.size(); i++)
        {
            if(axe)
                win.draw(vecNode[i].get_img_xy());
            else
                win.draw(vecNode[i].get_img_xz());
        }
        for (size_t i(0); i < vecStar.size(); i++)
        {
            //vecStar[i].move();
            if (axe)
                win.draw(vecStar[i].get_img_xy());
            else
                win.draw(vecStar[i].get_img_xz());
        }
        //std::cout << "________________" << std::endl;
        win.display();
	}
    return 0;
}