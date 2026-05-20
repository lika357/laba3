#pragma once
#include "widget.hpp"
#include "../include/list_sequence.hpp"
#include <SFML/Graphics.hpp>

class Layout : public Widget
{
   protected:
    ListSequence<Widget*> widgets;  

   public:
    Layout& append(Widget& widget)
    {
        widgets.Append(&widget);  
        return *this;            
    }

    void draw(sf::RenderWindow& window) override
    {
        if (!visible) return;
        for (size_t i = 0; i < widgets.GetLength(); i++)
        {
            widgets[i]->draw(window); 
        }
    }

    void handleEvent(const sf::Event& event) override
    {
        if (!visible || disabled) return;
        for (size_t i = 0; i < widgets.GetLength(); i++)
        {
            widgets[i]->handleEvent(event);  
        }
    }
};