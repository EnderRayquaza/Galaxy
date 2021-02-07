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
    Node Octree;

    for (size_t i(0); i < NB_STAR+NB_BH; i++)
    {
        if (i < NB_STAR)
            vecStar.push_back(Star(random(WIDTH / 16., 14 * WIDTH / 16.), random(HEIGHT / 16., 14 * HEIGHT / 16.), 
                random(AXE_Z / 16., 14 * AXE_Z / 16.), i));
        else
            vecStar.push_back(Star(random(WIDTH / 16., 14 * WIDTH / 16.), random(HEIGHT / 16., 14 * HEIGHT / 16.),
                random(AXE_Z / 16., 14 * AXE_Z / 16.), i, true));
    }

    Octree = createOctree(vecStar);
    vecNode = TestOctree(Octree);
    int axe(0);
    std::cout << "Axe : xy" << std::endl;
	while (win.isOpen())
	{
        sf::Event ev;
        while (win.pollEvent(ev))
        {
            if (ev.type == sf::Event::Closed)
                win.close();
            else if (ev.type == sf::Event::KeyPressed)
            {
                if (axe == 0)
                {
                    axe = 1;
                    std::cout << "Axe : xz" << std::endl;
                }
                else if (axe == 1)
                {
                    axe = 2;
                    std::cout << "Axe : yz" << std::endl;
                }
                else
                {
                    axe = 0;
                    std::cout << "Axe : xy" << std::endl;
                }
                
            }

        } 

        win.clear(sf::Color::Black);
        for (size_t i(0); i < vecStar.size(); i++)
        {
            vecStar[i].update_speed(vecStar);
        }
        for (size_t i(0); i < vecNode.size(); i++)
        {
            if(axe == 0)
                win.draw(vecNode[i].get_img_xy());
            else if(axe == 1)
                win.draw(vecNode[i].get_img_xz());
            else if(axe == 2)
                win.draw(vecNode[i].get_img_yz());
        }
        for (size_t i(0); i < vecStar.size(); i++)
        {
            //vecStar[i].move();
            if (axe == 0)
                win.draw(vecStar[i].get_img_xy());
            else if(axe == 1)
                win.draw(vecStar[i].get_img_xz());
            else
                win.draw(vecStar[i].get_img_yz());
        }
        //std::cout << "________________" << std::endl;
        win.display();
	}
    return 0;
}