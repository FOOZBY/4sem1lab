#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>

using namespace std;

int getnum()
{
    int value;
    while (!(cin >> value))
    { //Since value is a int, (cin >> value) will be true only if the user enters a valid value that can be put inside a int
       cout << "Please enter a valid value:" << endl;
       cin.clear();
       cin.ignore(32767, '\n');
    }
    cin.ignore(32767, '\n');
    return value;
}

void dots()
{
    cout << "¬ведите количество точек: ";
    int amount = getnum();
    int** coordinats = new int*[amount];
    for (int i = 0; i < amount; i++)
        coordinats[i] = new int[2];
    int x;
    int y;
    for (int i = 0; i < amount; i++)
    {
        cout << "¬ведите координаты " << i+1 << " точки\n";
        while (true)
        {
            cout << "x(0-600): ";
            x = getnum();
            if (x < 600 && x > -1)
                break;
            else
                cout << "координата за пределами окна, повторите ввод\n";
        }
        while (true)
        {
            cout << "y(0-400): ";
            y = getnum();
            if (y < 400 && y > -1)
                break;
            else
                cout << "координата за пределами окна, повторите ввод\n";
        }
        coordinats[i][1] = x;
        coordinats[i][2] = y;
        cout << "\n\n";
    }
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(600, 400), "Circles!");
    window.setFramerateLimit(2);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        for (int i = 0; i < amount; i++)
        {
            int r = rand() % 255 + 1;
            int g = rand() % 255 + 1;
            int b = rand() % 255 + 1;
            sf::CircleShape circle(1.f);
            circle.setFillColor(sf::Color(r, g, b));
            circle.setPosition(coordinats[i][1], coordinats[i][2]);
            window.draw(circle);
        }
        window.display();
    }
    for (int i = 0; i < amount; i++)
        delete[] coordinats[i];
    delete[] coordinats;
}