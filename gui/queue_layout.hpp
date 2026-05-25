
#pragma once
#include "button.hpp"
#include "config.hpp"
#include "horizontal_layout.hpp"
#include "vertical_layout.hpp"

class QueueLayout : public VerticalLayout
{
   public:
    HorizontalLayout buttons{LayoutPositions::WORK_X, LayoutPositions::WORK_Y,
                             LayoutPositions::FUNC_GAP};
    Button qEnqueue{"Enqueue", ButtonSizes::QUEUE_W, ButtonSizes::QUEUE_H};
    Button qDequeue{"Dequeue", ButtonSizes::QUEUE_W, ButtonSizes::QUEUE_H};
    Button qFront{"Front", ButtonSizes::QUEUE_W, ButtonSizes::QUEUE_H};
    Button qBack{"Back", ButtonSizes::QUEUE_W, ButtonSizes::QUEUE_H};
    Button qSize{"Size", ButtonSizes::QUEUE_W, ButtonSizes::QUEUE_H};
    Button qEmpty{"Empty", ButtonSizes::QUEUE_W, ButtonSizes::QUEUE_H};
    Button qReturn{"Back", ButtonSizes::QUEUE_W, ButtonSizes::QUEUE_H};

    QueueLayout()
        : VerticalLayout(LayoutPositions::WORK_X, LayoutPositions::WORK_Y,
                         LayoutPositions::WORK_GAP)
    {
        buttons.append(qEnqueue);
        buttons.append(qDequeue);
        buttons.append(qFront);
        buttons.append(qBack);
        buttons.append(qSize);
        buttons.append(qEmpty);
        buttons.append(qReturn);
        this->append(buttons);
    }
};