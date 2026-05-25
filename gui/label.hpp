#pragma once
#include <SFML/Graphics.hpp>

#include "widget.hpp"
#include "config.hpp" 

class Label : public Widget
{
   private:
    sf::Text text;

   public:
    Label(const std::string& str) : text(Widget::getDefaultFont())
    {
        text.setString(str);
        text.setCharacterSize(FontSizes::RESULT); 
        text.setFillColor(Colors::RESULT);          
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