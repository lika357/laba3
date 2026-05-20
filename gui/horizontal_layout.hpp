#pragma once
#include "layout.hpp"
#include "widget.hpp"

class HorizontalLayout : public Layout
{
   private:
    float startX;  
    float startY;  
    float gap;     

   public:
    HorizontalLayout(float x, float y, float spacing = 10)
        : startX(x), startY(y), gap(spacing) {}

   
    void addWidget(Widget& widget)
    {
        float currentX = startX;  

        if (widgets.GetLength() > 0)
        {
            Widget* last = widgets.GetLast();

            currentX = last->getPosition().x + last->getSize().x + gap;
        }

        widget.setPosition(currentX, startY);
        widgets.Append(&widget);
    }
};