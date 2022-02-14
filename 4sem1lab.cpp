#include <SFML/Graphics.hpp>
#include <ctime>
#include <conio.h>
int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Circles!");
    window.setFramerateLimit(1);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        int amount = rand() % 20 + 3;
        for (int i = 0; i < amount; i++)
        {
            int x = rand() % 1600;
            int y = rand() % 900;
            int r = rand() % 256;
            int g = rand() % 256;
            int b = rand() % 256;
            sf::CircleShape circle(1.f);
            circle.setFillColor(sf::Color(r, g, b));
            circle.setPosition(x, y);
            window.draw(circle);
        }
        window.display();
    }
    return 0;
}