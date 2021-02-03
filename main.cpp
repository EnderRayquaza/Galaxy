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

    int lvl(1);
    vecNode.push_back(Node(lvl, 0, 0, 0));
    for(int n(0); n<vecNode.size(); n++)
    {
        std::cout << "Node (" << n <<") : "<< vecNode.size() << std::endl;
        int nb_star(0);
        for (int i(0); i < vecStar.size(); i++)
        {
            if ((vecNode[n].get_pos()[0].x < vecStar[i].get_pos().x < vecNode[n].get_pos()[1].x) &&
                (vecNode[n].get_pos()[0].y < vecStar[i].get_pos().y < vecNode[n].get_pos()[1].y) &&
                (vecNode[n].get_pos()[0].z < vecStar[i].get_pos().z < vecNode[n].get_pos()[1].z))
            {
                nb_star++;
            }
        }
        if (nb_star > 1)
        {
            std::cout << nb_star << std::endl;
            lvl *= 2;
            for(int i(0); i < 2; i++)
                for(int j(0); j < 2; j++)
                    for (int k(0); k < 2; k++)
                    {
                        vecNode.push_back(Node(lvl, i * WIDTH / lvl, j * HEIGHT / lvl, k * AXE_Z / lvl));
                        /*std::cout << " | x1 : " << vecNode[vecNode.size() - 1].get_pos()[0].x;
                        std::cout << " | y1 : " << vecNode[vecNode.size() - 1].get_pos()[0].y;
                        std::cout << " | z1 : " << vecNode[vecNode.size() - 1].get_pos()[0].z;
                        std::cout << std::endl;
                        std::cout << " | x2 : " << vecNode[vecNode.size() - 1].get_pos()[1].x;
                        std::cout << " | y2 : " << vecNode[vecNode.size() - 1].get_pos()[1].y;
                        std::cout << " | z2 : " << vecNode[vecNode.size() - 1].get_pos()[1].z;
                        std::cout << std::endl;
                        std::cout << std::endl;*/
                        
                    }
        }
        if (n > 2)
            break;
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
        for (size_t i(0); i < vecNode.size(); i++)
        {
            win.draw(vecNode[i].get_img());
        }
        for (size_t i(0); i < vecStar.size(); i++)
        {
            //vecStar[i].move();
            win.draw(vecStar[i].get_img());
        }
        //std::cout << "________________" << std::endl;
        win.display();
	}
    return 0;
}