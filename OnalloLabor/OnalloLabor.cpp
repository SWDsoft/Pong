#include <iostream>
#include "sfml/Graphics.hpp"

#include "Render.h"
#include "Delta.h"
#include "World.h"
#include "Random.h"
#include "defs.h"

using namespace std;

int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(CONFIG::screen::w, CONFIG::screen::h), "SFML works!");

    window.setFramerateLimit(600);

    World w;
    Render r{ w,window };

   

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        Delta::getInstance()->restartClock();

        w.UpdateEntities();

        window.clear();

        r.RenderObjects();
       
        window.display();
    }

    return 0;

}

    


