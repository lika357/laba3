#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

#include "../include/deque.hpp"
#include "../include/list_sequence.hpp"
#include "../include/queue.hpp"
#include "../include/stack.hpp"
#include "button.hpp"
#include "config.hpp"
#include "deque_layout.hpp"
#include "edit.hpp"
#include "horizontal_layout.hpp"
#include "label.hpp"
#include "queue_layout.hpp"
#include "stack_layout.hpp"
#include "vertical_layout.hpp"

class LikaWindow
{
   private:
    sf::RenderWindow window;
    sf::Font font;
    Label titleLabel{"CHOOSE STRUCTURE"};

    VerticalLayout chooseLayout{LayoutPositions::CHOOSE_X, LayoutPositions::CHOOSE_Y,
                                LayoutPositions::CHOOSE_GAP};
    Button btnStack{"STACK", ButtonSizes::CHOOSE_W, ButtonSizes::CHOOSE_H};
    Button btnQueue{"QUEUE", ButtonSizes::CHOOSE_W, ButtonSizes::CHOOSE_H};
    Button btnDeque{"DEQUE", ButtonSizes::CHOOSE_W, ButtonSizes::CHOOSE_H};

    VerticalLayout workLayout{LayoutPositions::WORK_X, LayoutPositions::WORK_Y,
                              LayoutPositions::WORK_GAP};

    std::unique_ptr<StackLayout> stackLayout;
    std::unique_ptr<QueueLayout> queueLayout;
    std::unique_ptr<DequeLayout> dequeLayout;

    Edit inputField;
    Label resultLabel{""};

    HorizontalLayout elementsLayout{LayoutPositions::WORK_X, LayoutPositions::ELEM_Y,
                                    LayoutPositions::ELEM_GAP};

    ListStack<int> stack;
    ListQueue<int> queue;
    ListDeque<int> deque;

    bool inputMode = false;
    int activeStructure = 0;
    int dequeInputMode = 0;

    void onStackClick()
    {
        chooseLayout.setVisible(false);
        workLayout.setVisible(true);
        titleLabel.setText("STACK");
        activeStructure = 1;
        clearElements();

        stackLayout = std::make_unique<StackLayout>();

        stackLayout->sPush.setOnClick(std::bind(&LikaWindow::onStackPush, this));
        stackLayout->sPop.setOnClick(std::bind(&LikaWindow::onStackPop, this));
        stackLayout->sTop.setOnClick(std::bind(&LikaWindow::onStackTop, this));
        stackLayout->sSize.setOnClick(std::bind(&LikaWindow::onStackSize, this));
        stackLayout->sEmpty.setOnClick(std::bind(&LikaWindow::onStackEmpty, this));
        stackLayout->sBack.setOnClick(std::bind(&LikaWindow::onBackToMenu, this));
        while (workLayout.getWidgetCount() > 0){
         workLayout.removeLast();
        }

        workLayout.append(*stackLayout);
         workLayout.append(elementsLayout); 
    }

    void onQueueClick()
    {
        chooseLayout.setVisible(false);
        workLayout.setVisible(true);
        titleLabel.setText("QUEUE");
        activeStructure = 2;
        clearElements();

        queueLayout = std::make_unique<QueueLayout>();

        queueLayout->qEnqueue.setOnClick(std::bind(&LikaWindow::onQueueEnqueue, this));
        queueLayout->qDequeue.setOnClick(std::bind(&LikaWindow::onQueueDequeue, this));
        queueLayout->qFront.setOnClick(std::bind(&LikaWindow::onQueueFront, this));
        queueLayout->qBack.setOnClick(std::bind(&LikaWindow::onQueueBack, this));
        queueLayout->qSize.setOnClick(std::bind(&LikaWindow::onQueueSize, this));
        queueLayout->qEmpty.setOnClick(std::bind(&LikaWindow::onQueueEmpty, this));
        queueLayout->qReturn.setOnClick(std::bind(&LikaWindow::onBackToMenu, this));
        while (workLayout.getWidgetCount() > 0){
         workLayout.removeLast();
        }

        workLayout.append(*queueLayout);
         workLayout.append(elementsLayout); 
    }

    void onDequeClick()
    {
        chooseLayout.setVisible(false);
        workLayout.setVisible(true);
        titleLabel.setText("DEQUE");
        activeStructure = 3;
        clearElements();

        dequeLayout = std::make_unique<DequeLayout>();

        dequeLayout->dPushFront.setOnClick(std::bind(&LikaWindow::onDequePushFront, this));
        dequeLayout->dPushBack.setOnClick(std::bind(&LikaWindow::onDequePushBack, this));
        dequeLayout->dPopFront.setOnClick(std::bind(&LikaWindow::onDequePopFront, this));
        dequeLayout->dPopBack.setOnClick(std::bind(&LikaWindow::onDequePopBack, this));
        dequeLayout->dFront.setOnClick(std::bind(&LikaWindow::onDequeFront, this));
        dequeLayout->dBack.setOnClick(std::bind(&LikaWindow::onDequeBack, this));
        dequeLayout->dSize.setOnClick(std::bind(&LikaWindow::onDequeSize, this));
        dequeLayout->dEmpty.setOnClick(std::bind(&LikaWindow::onDequeEmpty, this));
        dequeLayout->dReturn.setOnClick(std::bind(&LikaWindow::onBackToMenu, this));
        while (workLayout.getWidgetCount() > 0){
         workLayout.removeLast();
        }

        workLayout.append(*dequeLayout);
         workLayout.append(elementsLayout); 
    }

    void onStackPush()
    {
        inputMode = true;
        inputField.clear();
        inputField.setVisible(true);
        inputField.setFocused(true);
        resultLabel.setVisible(false);
    }

    void onStackPop()
    {
        inputField.setVisible(false);
        if (stack.IsEmpty())
        {
            resultLabel.setText("Stack is empty");
            resultLabel.setVisible(true);
        }
        else
        {
            int val = stack.Pop();
            resultLabel.setText("Popped: " + std::to_string(val));
            resultLabel.setVisible(true);
            elementsLayout.removeLast();
        }
    }

    void onStackTop()
    {
        inputField.setVisible(false);
        if (stack.IsEmpty())
        {
            resultLabel.setText("Stack is empty");
            resultLabel.setVisible(true);
        }
        else
        {
            int val = stack.Top();
            resultLabel.setText("Top: " + std::to_string(val));
            resultLabel.setVisible(true);
        }
    }

    void onStackSize()
    {
        inputField.setVisible(false);
        resultLabel.setText("Size: " + std::to_string(stack.GetSize()));
        resultLabel.setVisible(true);
    }

    void onStackEmpty()
    {
        inputField.setVisible(false);
        resultLabel.setText(stack.IsEmpty() ? "Stack is EMPTY" : "Stack is NOT empty");
        resultLabel.setVisible(true);
    }

    void onQueueEnqueue()
    {
        inputMode = true;
        inputField.clear();
        inputField.setVisible(true);
        inputField.setFocused(true);
        resultLabel.setVisible(false);
    }

    void onQueueDequeue()
    {
        inputField.setVisible(false);
        if (queue.IsEmpty())
        {
            resultLabel.setText("Queue is empty");
            resultLabel.setVisible(true);
        }
        else
        {
            int val = queue.Dequeue();
            resultLabel.setText("Dequeued: " + std::to_string(val));
            resultLabel.setVisible(true);
            elementsLayout.removeLast();
        }
    }

    void onQueueFront()
    {
        inputField.setVisible(false);
        if (queue.IsEmpty())
        {
            resultLabel.setText("Queue is empty");
            resultLabel.setVisible(true);
        }
        else
        {
            int val = queue.Front();
            resultLabel.setText("Front: " + std::to_string(val));
            resultLabel.setVisible(true);
        }
    }

    void onQueueBack()
    {
        inputField.setVisible(false);
        if (queue.IsEmpty())
        {
            resultLabel.setText("Queue is empty");
            resultLabel.setVisible(true);
        }
        else
        {
            int val = queue.Back();
            resultLabel.setText("Back: " + std::to_string(val));
            resultLabel.setVisible(true);
        }
    }

    void onQueueSize()
    {
        inputField.setVisible(false);
        resultLabel.setText("Size: " + std::to_string(queue.GetSize()));
        resultLabel.setVisible(true);
    }

    void onQueueEmpty()
    {
        inputField.setVisible(false);
        resultLabel.setText(queue.IsEmpty() ? "Queue is EMPTY" : "Queue is NOT empty");
        resultLabel.setVisible(true);
    }

    void onDequePushFront()
    {
        inputMode = true;
        dequeInputMode = 1;
        inputField.clear();
        inputField.setVisible(true);
        inputField.setFocused(true);
        resultLabel.setVisible(false);
    }

    void onDequePushBack()
    {
        inputMode = true;
        dequeInputMode = 2;
        inputField.clear();
        inputField.setVisible(true);
        inputField.setFocused(true);
        resultLabel.setVisible(false);
    }

    void onDequePopFront()
    {
        inputField.setVisible(false);
        if (deque.IsEmpty())
        {
            resultLabel.setText("Deque is empty");
            resultLabel.setVisible(true);
        }
        else
        {
            int val = deque.PopFront();
            resultLabel.setText("PopFront: " + std::to_string(val));
            resultLabel.setVisible(true);
            elementsLayout.removeFirst();
        }
    }

    void onDequePopBack()
    {
        inputField.setVisible(false);
        if (deque.IsEmpty())
        {
            resultLabel.setText("Deque is empty");
            resultLabel.setVisible(true);
        }
        else
        {
            int val = deque.PopBack();
            resultLabel.setText("PopBack: " + std::to_string(val));
            resultLabel.setVisible(true);
            elementsLayout.removeLast();
        }
    }

    void onDequeFront()
    {
        inputField.setVisible(false);
        if (deque.IsEmpty())
        {
            resultLabel.setText("Deque is empty");
            resultLabel.setVisible(true);
        }
        else
        {
            int val = deque.Front();
            resultLabel.setText("Front: " + std::to_string(val));
            resultLabel.setVisible(true);
        }
    }

    void onDequeBack()
    {
        inputField.setVisible(false);
        if (deque.IsEmpty())
        {
            resultLabel.setText("Deque is empty");
            resultLabel.setVisible(true);
        }
        else
        {
            int val = deque.Back();
            resultLabel.setText("Back: " + std::to_string(val));
            resultLabel.setVisible(true);
        }
    }

    void onDequeSize()
    {
        inputField.setVisible(false);
        resultLabel.setText("Size: " + std::to_string(deque.GetSize()));
        resultLabel.setVisible(true);
    }

    void onDequeEmpty()
    {
        inputField.setVisible(false);
        resultLabel.setText(deque.IsEmpty() ? "Deque is EMPTY" : "Deque is NOT empty");
        resultLabel.setVisible(true);
    }

    void onBackToMenu()
    {
        workLayout.setVisible(false);
        chooseLayout.setVisible(true);
        titleLabel.setText("CHOOSE STRUCTURE");
        inputField.setVisible(false);
        resultLabel.setVisible(false);
        inputMode = false;
        clearElements();
    }

    void handleStackInput(int value)
    {
        stack.Push(value);
        resultLabel.setText("Pushed: " + std::to_string(value));
        Button* elem =
            new Button(std::to_string(value), ButtonSizes::ELEMENT_W, ButtonSizes::ELEMENT_H);
        elem->setColor(Colors::ELEMENT);
        elementsLayout.append(*elem);
    }

    void handleQueueInput(int value)
    {
        queue.Enqueue(value);
        resultLabel.setText("Enqueued: " + std::to_string(value));
        Button* elem =
            new Button(std::to_string(value), ButtonSizes::ELEMENT_W, ButtonSizes::ELEMENT_H);
        elem->setColor(Colors::ELEMENT);
        elementsLayout.prepend(*elem);
    }

    void handleDequeInput(int value)
    {
        if (dequeInputMode == 1)
        {
            deque.PushFront(value);
            resultLabel.setText("PushFront: " + std::to_string(value));
            Button* elem =
                new Button(std::to_string(value), ButtonSizes::ELEMENT_W, ButtonSizes::ELEMENT_H);
            elem->setColor(Colors::ELEMENT);
            elementsLayout.prepend(*elem);
        }
        else
        {
            deque.PushBack(value);
            resultLabel.setText("PushBack: " + std::to_string(value));
            Button* elem =
                new Button(std::to_string(value), ButtonSizes::ELEMENT_W, ButtonSizes::ELEMENT_H);
            elem->setColor(Colors::ELEMENT);
            elementsLayout.append(*elem);
        }
        dequeInputMode = 0;
    }

   public:
    LikaWindow(size_t width, size_t height, const std::string& title)
    {
        window.create(
            sf::VideoMode({static_cast<unsigned int>(width), static_cast<unsigned int>(height)}),
            title);

        if (!font.openFromFile("arial.ttf"))
        {
            throw std::runtime_error("Failed not open");
        }

        Widget::getDefaultFont() = font;

        titleLabel.setPosition(ElementPositions::TITLE_X, ElementPositions::TITLE_Y);

        inputField.setPosition(ElementPositions::INPUT_X, ElementPositions::INPUT_Y);
        resultLabel.setPosition(ElementPositions::RESULT_X, ElementPositions::RESULT_Y);
        inputField.setVisible(false);
        resultLabel.setVisible(false);

        chooseLayout.append(btnStack);
        chooseLayout.append(btnQueue);
        chooseLayout.append(btnDeque);


        btnStack.setOnClick(std::bind(&LikaWindow::onStackClick, this));
        btnQueue.setOnClick(std::bind(&LikaWindow::onQueueClick, this));
        btnDeque.setOnClick(std::bind(&LikaWindow::onDequeClick, this));

        workLayout.setVisible(false);
    }

    void clearElements()
    {
        while (elementsLayout.getWidgetCount() > 0)
        {
            elementsLayout.removeLast();
        }
        stack = ListStack<int>();
        queue = ListQueue<int>();
        deque = ListDeque<int>();
    }

    void run()
    {
        while (window.isOpen())
        {
            while (auto event = window.pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                {
                    window.close();
                }
                bool handled = false;

                if (inputField.isVisible())
                {
                    handled = inputField.handleEvent(*event);
                }

                if (!handled)
                {
                    if (chooseLayout.handleEvent(*event)) handled = true;
                }

                if (!handled)
                {
                    if (workLayout.handleEvent(*event)) handled = true;
                }

                if (inputMode && !inputField.isFocused() && !inputField.getInput().empty())
                {
                    int value = std::stoi(inputField.getInput());
                    inputField.clear();
                    inputField.setVisible(false);
                    inputMode = false;

                    if (activeStructure == 1)
                        handleStackInput(value);
                    else if (activeStructure == 2)
                        handleQueueInput(value);
                    else if (activeStructure == 3)
                        handleDequeInput(value);

                    resultLabel.setVisible(true);
                }
            }
            window.clear(Colors::BACKGROUND);

            titleLabel.draw(window);
            chooseLayout.draw(window);
            workLayout.draw(window);

            if (inputField.isVisible())
            {
                inputField.draw(window);
            }
            if (resultLabel.isVisible())
            {
                resultLabel.draw(window);
            }

            window.display();
        }
    }
};