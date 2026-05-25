
#pragma once
#include "button.hpp"
#include "config.hpp"
#include "horizontal_layout.hpp"
#include "vertical_layout.hpp"

class DequeLayout : public VerticalLayout
{
   public:
    HorizontalLayout buttons{LayoutPositions::WORK_X, LayoutPositions::WORK_Y,
                             LayoutPositions::FUNC_GAP};
    Button dPushFront{"PushFront", ButtonSizes::DEQUE_W, ButtonSizes::DEQUE_H};
    Button dPushBack{"PushBack", ButtonSizes::DEQUE_W, ButtonSizes::DEQUE_H};
    Button dPopFront{"PopFront", ButtonSizes::DEQUE_W, ButtonSizes::DEQUE_H};
    Button dPopBack{"PopBack", ButtonSizes::DEQUE_W, ButtonSizes::DEQUE_H};
    Button dFront{"Front", ButtonSizes::DEQUE_W, ButtonSizes::DEQUE_H};
    Button dBack{"Back", ButtonSizes::DEQUE_W, ButtonSizes::DEQUE_H};
    Button dSize{"Size", ButtonSizes::DEQUE_W, ButtonSizes::DEQUE_H};
    Button dEmpty{"Empty", ButtonSizes::DEQUE_W, ButtonSizes::DEQUE_H};
    Button dReturn{"Back", ButtonSizes::DEQUE_W, ButtonSizes::DEQUE_H};

    DequeLayout()
        : VerticalLayout(LayoutPositions::WORK_X, LayoutPositions::WORK_Y,
                         LayoutPositions::WORK_GAP)
    {
        buttons.append(dPushFront);
        buttons.append(dPushBack);
        buttons.append(dPopFront);
        buttons.append(dPopBack);
        buttons.append(dFront);
        buttons.append(dBack);
        buttons.append(dSize);
        buttons.append(dEmpty);
        buttons.append(dReturn);
        this->append(buttons);
    }
};