
#include <SFML/Graphics.hpp>
#include <sstream>
#include <string>

#include "queue.hpp"
#include "stack.hpp"
int main()
{
    sf::RenderWindow window(sf::VideoMode({900, 650}), "LABA 3");
    sf::Font font;
    if (!font.openFromFile("arial.ttf"))
    {
        return 1;
    }
    sf::Text title(font);

    title.setString("CHOOSE STRUCTURE");

    title.setCharacterSize(30);

    title.setFillColor(sf::Color(101, 67, 33));

    title.setPosition({250, 40});

    while (window.isOpen())
    {
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
        window.clear(sf::Color(255, 228, 225));
        window.display();
    }
    return 0;
}