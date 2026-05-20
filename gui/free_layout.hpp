#pragma once
#include "layout.hpp"

class FreeLayout : public Layout
{
   public:
    void addWidget(Widget& widget)
    {
        widgets.Append(&widget);
    }
};