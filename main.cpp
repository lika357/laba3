
#include <SFML/Graphics.hpp>
#include <sstream>
#include <string>

#include "queue.hpp"
#include "stack.hpp"
class Button
{
   private:
    sf::RectangleShape shape;
    sf::Text text;

   public:
    Button(float x, float y, float w, float h, const std::string& str, sf::Font& font) : text(font)
    {
        shape.setPosition({x, y});
        shape.setSize({w, h});
        shape.setFillColor(sf::Color::White);
        shape.setOutlineThickness(2);
        shape.setOutlineColor(sf::Color(101, 67, 33));
        text.setString(str);
        text.setCharacterSize(22);
        text.setFillColor(sf::Color::Black);
        sf::FloatRect b = text.getLocalBounds();
        text.setPosition({x + w / 2 - b.size.x / 2, y + h / 2 - b.size.y / 2 - 5});
    }

    void setText(const std::string& str)
    {
        text.setString(str);
        sf::FloatRect b = text.getLocalBounds();
        text.setPosition({shape.getPosition().x + shape.getSize().x / 2 - b.size.x / 2,
                          shape.getPosition().y + shape.getSize().y / 2 - b.size.y / 2 - 5});
    }

    bool clicked(sf::Vector2f m)
    {
        return shape.getGlobalBounds().contains(m);
    }

    void draw(sf::RenderWindow& w)
    {
        w.draw(shape);
        w.draw(text);
    }
};
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