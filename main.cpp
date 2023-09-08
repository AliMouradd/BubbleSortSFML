#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>
using namespace sf;

int randomh = 0, part = 1, iter = 0, major = 0, cont = 0, lims = 799;


struct data {
    int height;
    int posx;

}line[800];


int main()
{
    RenderWindow window;
    window.create(VideoMode::getDesktopMode(), "Bubble sort");


    Texture fondot;
    fondot.loadFromFile("fondot.png");
    Sprite fondo(fondot);

    RectangleShape rectangle(Vector2f(19,178));
    rectangle.setFillColor(Color::Red);

    srand(time(0));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        
        
        if (part == 2) {
            if (line[iter].height < line[iter + 1].height) {
                major = line[iter].height;
                line[iter].height = line[iter + 1].height;
                line[iter + 1].height = major;
            }
        }


        if (part == 1) {
            for (int i = 0; i < 800; i++) {
                randomh = 1 + rand() % (1080);
                line[i].posx = i*2.4;
                line[i].height = randomh;

                if (i == 799) {
                    part = 2;
                }
            }
        }

        window.clear();
        for (int i = 0; i < 800; i++) {
            if (i == iter) {
                rectangle.setFillColor(Color::White);
            }
            rectangle.setPosition(line[i].posx, 1080);
            rectangle.setSize(Vector2f(2, line[i].height));
            rectangle.setRotation(180);
            window.draw(rectangle);
            
        }
        window.display();
        iter++;
        if (iter >= lims) {
            iter = 0;
            cont++;
            lims--;
        }

    }
	return 0;
}