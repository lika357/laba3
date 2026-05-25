#pragma once
#include "button.hpp"
#include "config.hpp"
#include "horizontal_layout.hpp"
#include "vertical_layout.hpp"

class StackLayout : public VerticalLayout
{
   public:
    HorizontalLayout buttons{LayoutPositions::WORK_X, LayoutPositions::WORK_Y,
                             LayoutPositions::FUNC_GAP};
    Button sPush{"Push", ButtonSizes::STACK_W, ButtonSizes::STACK_H};
    Button sPop{"Pop", ButtonSizes::STACK_W, ButtonSizes::STACK_H};
    Button sTop{"Top", ButtonSizes::STACK_W, ButtonSizes::STACK_H};
    Button sSize{"Size", ButtonSizes::STACK_W, ButtonSizes::STACK_H};
    Button sEmpty{"Empty", ButtonSizes::STACK_W, ButtonSizes::STACK_H};
    Button sBack{"Back", ButtonSizes::STACK_W, ButtonSizes::STACK_H};

    StackLayout()
        : VerticalLayout(LayoutPositions::WORK_X, LayoutPositions::WORK_Y,
                         LayoutPositions::WORK_GAP)
    {
        buttons.append(sPush);
        buttons.append(sPop);
        buttons.append(sTop);
        buttons.append(sSize);
        buttons.append(sEmpty);
        buttons.append(sBack);
        this->append(buttons);
    }
};