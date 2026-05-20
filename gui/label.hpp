#pragma once
#include "widget.hpp"
#include <SFML/Graphics.hpp>

class Label : public Widget
{
   private:
    sf::Text text;

   public:
    Label(const std::string& str, sf::Font& font)
        : text(font)
    {
        text.setString(str);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::Black);
    }

    void setPosition(float x, float y)
    {
        Widget::setPosition(x, y);
        text.setPosition({x, y});
    }

    void setText(const std::string& str)
    {
        text.setString(str);
    }

    void draw(sf::RenderWindow& window) override
    {
        if (!visible) return;
        window.draw(text);
    }

    void handleEvent(const sf::Event& event) override
    {
    }
};