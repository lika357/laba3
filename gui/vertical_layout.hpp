#pragma once
#include "layout.hpp"

class VerticalLayout : public Layout
{
   private:
    float startX, startY, gap;

   public:
    VerticalLayout(float x, float y, float spacing = 10)
        : startX(x), startY(y), gap(spacing) {}

    void addWidget(Widget& widget)
    {
        float currentY = startY;

        if (widgets.GetLength() > 0)
        {
            Widget* last = widgets.GetLast();
            currentY = last->getPosition().y + last->getSize().y + gap;
        }

        widget.setPosition(startX, currentY);
        widgets.Append(&widget); 
    }
};