#pragma once
#include <SFML/Graphics.hpp>

#include "../include/deque.hpp"
#include "../include/list_sequence.hpp"
#include "../include/queue.hpp"
#include "../include/stack.hpp"
#include "button.hpp"
#include "edit.hpp"
#include "horizontal_layout.hpp"
#include "label.hpp"
#include "vertical_layout.hpp"

class LikaWindow
{
   private:
    sf::RenderWindow window;
    sf::Font font;
    Label titleLabel{"CHOOSE STRUCTURE"};

    VerticalLayout chooseLayout{450.0f, 250.0f, 25.0f};
    Button btnStack{"STACK", 300.0f, 70.0f};
    Button btnQueue{"QUEUE", 300.0f, 70.0f};
    Button btnDeque{"DEQUE", 300.0f, 70.0f};

    VerticalLayout workLayout{50.0f, 80.0f, 15.0f};

    HorizontalLayout stackButtons{50.0f, 80.0f, 10.0f};
    Button sPush{"Push", 175.0f, 50.0f};
    Button sPop{"Pop", 175.0f, 50.0f};
    Button sTop{"Top", 175.0f, 50.0f};
    Button sSize{"Size", 175.0f, 50.0f};
    Button sEmpty{"Empty", 175.0f, 50.0f};
    Button sBack{"Back", 175.0f, 50.0f};

    HorizontalLayout queueButtons{50.0f, 80.0f, 10.0f};
    Button qEnqueue{"Enqueue", 150.0f, 50.0f};
    Button qDequeue{"Dequeue", 150.0f, 50.0f};
    Button qFront{"Front", 150.0f, 50.0f};
    Button qBack{"Back", 150.0f, 50.0f};
    Button qSize{"Size", 150.0f, 50.0f};
    Button qEmpty{"Empty", 150.0f, 50.0f};
    Button qReturn{"Back", 150.0f, 50.0f};

    HorizontalLayout dequeButtons{50.0f, 80.0f, 10.0f};
    Button dPushFront{"PushFront", 115.0f, 50.0f};
    Button dPushBack{"PushBack", 115.0f, 50.0f};
    Button dPopFront{"PopFront", 115.0f, 50.0f};
    Button dPopBack{"PopBack", 115.0f, 50.0f};
    Button dFront{"Front", 115.0f, 50.0f};
    Button dBack{"Back", 115.0f, 50.0f};
    Button dSize{"Size", 115.0f, 50.0f};
    Button dEmpty{"Empty", 115.0f, 50.0f};
    Button dReturn{"Return", 115.0f, 50.0f};

    Edit inputField;
    Label resultLabel{""};

    HorizontalLayout elementsLayout{50.0f, 280.0f, 15.0f};

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
        stackButtons.setVisible(true);
        queueButtons.setVisible(false);
        dequeButtons.setVisible(false);
        titleLabel.setText("STACK");
        activeStructure = 1;
        clearElements();
    }

    void onQueueClick()
    {
        chooseLayout.setVisible(false);
        workLayout.setVisible(true);
        stackButtons.setVisible(false);
        queueButtons.setVisible(true);
        dequeButtons.setVisible(false);
        titleLabel.setText("QUEUE");
        activeStructure = 2;
        clearElements();
    }

    void onDequeClick()
    {
        chooseLayout.setVisible(false);
        workLayout.setVisible(true);
        stackButtons.setVisible(false);
        queueButtons.setVisible(false);
        dequeButtons.setVisible(true);
        titleLabel.setText("DEQUE");
        activeStructure = 3;
        clearElements();
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
        Button* elem = new Button(std::to_string(value), 80.0f, 80.0f);
        elem->setColor(sf::Color(173, 216, 230));
        elementsLayout.append(*elem);
    }

    void handleQueueInput(int value)
    {
        queue.Enqueue(value);
        resultLabel.setText("Enqueued: " + std::to_string(value));
        Button* elem = new Button(std::to_string(value), 80.0f, 80.0f);
        elem->setColor(sf::Color(173, 216, 230));
        elementsLayout.prepend(*elem);
    }

    void handleDequeInput(int value)
    {
        if (dequeInputMode == 1)
        {
            deque.PushFront(value);
            resultLabel.setText("PushFront: " + std::to_string(value));
            Button* elem = new Button(std::to_string(value), 80.0f, 80.0f);
            elem->setColor(sf::Color(173, 216, 230));
            elementsLayout.prepend(*elem);
        }
        else
        {
            deque.PushBack(value);
            resultLabel.setText("PushBack: " + std::to_string(value));
            Button* elem = new Button(std::to_string(value), 80.0f, 80.0f);
            elem->setColor(sf::Color(173, 216, 230));
            elementsLayout.append(*elem);
        }
        dequeInputMode = 0;
    }

   public:
    LikaWindow(size_t width, size_t height, const std::string& title)
    {
        window.create(
            sf::VideoMode({
                static_cast<unsigned int>(width),
                 static_cast<unsigned int>(height)
                }),
            title);

        if (!font.openFromFile("arial.ttf")){
             throw std::runtime_error("Failed not open");
        }

        Widget::getDefaultFont() = font;

        titleLabel.setPosition(450.0f, 20.0f);

        inputField.setPosition(50.0f, 150.0f);
        resultLabel.setPosition(50.0f, 150.0f);
        inputField.setVisible(false);
        resultLabel.setVisible(false);

        chooseLayout.append(btnStack);
        chooseLayout.append(btnQueue);
        chooseLayout.append(btnDeque);

        stackButtons.append(sPush);
        stackButtons.append(sPop);
        stackButtons.append(sTop);
        stackButtons.append(sSize);
        stackButtons.append(sEmpty);
        stackButtons.append(sBack);

        queueButtons.append(qEnqueue);
        queueButtons.append(qDequeue);
        queueButtons.append(qFront);
        queueButtons.append(qBack);
        queueButtons.append(qSize);
        queueButtons.append(qEmpty);
        queueButtons.append(qReturn);

        dequeButtons.append(dPushFront);
        dequeButtons.append(dPushBack);
        dequeButtons.append(dPopFront);
        dequeButtons.append(dPopBack);
        dequeButtons.append(dFront);
        dequeButtons.append(dBack);
        dequeButtons.append(dSize);
        dequeButtons.append(dEmpty);
        dequeButtons.append(dReturn);

        workLayout.append(stackButtons);
        workLayout.append(queueButtons);
        workLayout.append(dequeButtons);
        workLayout.append(elementsLayout);

        queueButtons.setVisible(false);
        dequeButtons.setVisible(false);

        btnStack.setOnClick(std::bind(&LikaWindow::onStackClick, this));
        btnQueue.setOnClick(std::bind(&LikaWindow::onQueueClick, this));
        btnDeque.setOnClick(std::bind(&LikaWindow::onDequeClick, this));

        sPush.setOnClick(std::bind(&LikaWindow::onStackPush, this));
        sPop.setOnClick(std::bind(&LikaWindow::onStackPop, this));
        sTop.setOnClick(std::bind(&LikaWindow::onStackTop, this));
        sSize.setOnClick(std::bind(&LikaWindow::onStackSize, this));
        sEmpty.setOnClick(std::bind(&LikaWindow::onStackEmpty, this));
        sBack.setOnClick(std::bind(&LikaWindow::onBackToMenu, this));

        qEnqueue.setOnClick(std::bind(&LikaWindow::onQueueEnqueue, this));
        qDequeue.setOnClick(std::bind(&LikaWindow::onQueueDequeue, this));
        qFront.setOnClick(std::bind(&LikaWindow::onQueueFront, this));
        qBack.setOnClick(std::bind(&LikaWindow::onQueueBack, this));
        qSize.setOnClick(std::bind(&LikaWindow::onQueueSize, this));
        qEmpty.setOnClick(std::bind(&LikaWindow::onQueueEmpty, this));
        qReturn.setOnClick(std::bind(&LikaWindow::onBackToMenu, this));

        dPushFront.setOnClick(std::bind(&LikaWindow::onDequePushFront, this));
        dPushBack.setOnClick(std::bind(&LikaWindow::onDequePushBack, this));
        dPopFront.setOnClick(std::bind(&LikaWindow::onDequePopFront, this));
        dPopBack.setOnClick(std::bind(&LikaWindow::onDequePopBack, this));
        dFront.setOnClick(std::bind(&LikaWindow::onDequeFront, this));
        dBack.setOnClick(std::bind(&LikaWindow::onDequeBack, this));
        dSize.setOnClick(std::bind(&LikaWindow::onDequeSize, this));
        dEmpty.setOnClick(std::bind(&LikaWindow::onDequeEmpty, this));
        dReturn.setOnClick(std::bind(&LikaWindow::onBackToMenu, this));

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
                if (event->is<sf::Event::Closed>()){
                     window.close();
                }

                if (inputField.isVisible())
                {
                    inputField.handleEvent(*event);
                }

                chooseLayout.handleEvent(*event);
                workLayout.handleEvent(*event);

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

            window.clear(sf::Color(255, 228, 225));

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