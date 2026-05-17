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
    if (!font.openFromFile("arial.ttf")) return 1;

    sf::Text title(font);
    title.setCharacterSize(30);
    title.setFillColor(sf::Color(101, 67, 33));
    title.setPosition({250, 40});

    Button btnStack(250, 150, 400, 60, "STACK", font);
    Button btnQueue(250, 240, 400, 60, "QUEUE", font);

    enum Screen
    {
        TYPE_SCREEN,
        MENU_SCREEN,
        INPUT_SCREEN,
        RESULT_SCREEN
    };
    Screen screen = TYPE_SCREEN;
    int containerType = 0;

    Stack<int> stack;
    Queue<int> queue;

    while (window.isOpen())
    {
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) window.close();

            if (auto* m = event->getIf<sf::Event::MouseButtonPressed>())
            {
                sf::Vector2f p = window.mapPixelToCoords(m->position);

                if (screen == TYPE_SCREEN)
                {
                    if (btnStack.clicked(p))
                    {
                        containerType = 1;
                        screen = MENU_SCREEN;
                    }
                    if (btnQueue.clicked(p))
                    {
                        containerType = 2;
                        screen = MENU_SCREEN;
                    }
                }
            }
        }

        window.clear(sf::Color(255, 228, 225));
        window.draw(title);

        if (screen == TYPE_SCREEN)
        {
            btnStack.draw(window);
            btnQueue.draw(window);
        }

        window.display();
    }

    return 0;
}