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
    Button btnStack{"STACK"};
    Button btnQueue{"QUEUE"};
    Button btnDeque{"DEQUE"};

    VerticalLayout workLayout{50.0f, 80.0f, 15.0f};

    HorizontalLayout stackButtons{50.0f, 80.0f, 10.0f};
    Button sPush{"Push"};
    Button sPop{"Pop"};
    Button sTop{"Top"};
    Button sSize{"Size"};
    Button sEmpty{"Empty"};
    Button sBack{"Back"};

    HorizontalLayout queueButtons{50.0f, 80.0f, 10.0f};
    Button qEnqueue{"Enqueue"};
    Button qDequeue{"Dequeue"};
    Button qFront{"Front"};
    Button qBack{"Back"};
    Button qSize{"Size"};
    Button qEmpty{"Empty"};
    Button qReturn{"Back"};

    HorizontalLayout dequeButtons{50.0f, 80.0f, 10.0f};
    Button dPushFront{"PushFront"};
    Button dPushBack{"PushBack"};
    Button dPopFront{"PopFront"};
    Button dPopBack{"PopBack"};
    Button dFront{"Front"};
    Button dBack{"Back"};
    Button dSize{"Size"};
    Button dEmpty{"Empty"};
    Button dReturn{"Return"};

    Edit inputField;
    Label resultLabel{""};

    HorizontalLayout elementsLayout{50.0f, 280.0f, 15.0f};

    ListStack<int> stack;
    ListQueue<int> queue;
    ListDeque<int> deque;

    bool inputMode = false;
    int activeStructure = 0;
    int dequeInputMode = 0;

   public:
    LikaWindow(size_t width, size_t height, const std::string& title)
    {
        window.create(
            sf::VideoMode({static_cast<unsigned int>(width), static_cast<unsigned int>(height)}),
            title);

        if (!font.openFromFile("arial.ttf")) throw std::runtime_error("Failed not open");

        Widget::getDefaultFont() = font;

        btnStack.setSize(300.0f, 70.0f);
        btnQueue.setSize(300.0f, 70.0f);
        btnDeque.setSize(300.0f, 70.0f);

        sPush.setSize(175.0f, 50.0f);
        sPop.setSize(175.0f, 50.0f);
        sTop.setSize(175.0f, 50.0f);
        sSize.setSize(175.0f, 50.0f);
        sEmpty.setSize(175.0f, 50.0f);
        sBack.setSize(175.0f, 50.0f);

        qEnqueue.setSize(150.0f, 50.0f);
        qDequeue.setSize(150.0f, 50.0f);
        qFront.setSize(150.0f, 50.0f);
        qBack.setSize(150.0f, 50.0f);
        qSize.setSize(150.0f, 50.0f);
        qEmpty.setSize(150.0f, 50.0f);
        qReturn.setSize(150.0f, 50.0f);

        dPushFront.setSize(115.0f, 50.0f);
        dPushBack.setSize(115.0f, 50.0f);
        dPopFront.setSize(115.0f, 50.0f);
        dPopBack.setSize(115.0f, 50.0f);
        dFront.setSize(115.0f, 50.0f);
        dBack.setSize(115.0f, 50.0f);
        dSize.setSize(115.0f, 50.0f);
        dEmpty.setSize(115.0f, 50.0f);
        dReturn.setSize(115.0f, 50.0f);

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

        btnStack.setOnClick(
            [&]()
            {
                chooseLayout.setVisible(false);
                workLayout.setVisible(true);
                stackButtons.setVisible(true);
                queueButtons.setVisible(false);
                dequeButtons.setVisible(false);
                titleLabel.setText("STACK");
                activeStructure = 1;
                clearElements();
            });

        btnQueue.setOnClick(
            [&]()
            {
                chooseLayout.setVisible(false);
                workLayout.setVisible(true);
                stackButtons.setVisible(false);
                queueButtons.setVisible(true);
                dequeButtons.setVisible(false);
                titleLabel.setText("QUEUE");
                activeStructure = 2;
                clearElements();
            });

        btnDeque.setOnClick(
            [&]()
            {
                chooseLayout.setVisible(false);
                workLayout.setVisible(true);
                stackButtons.setVisible(false);
                queueButtons.setVisible(false);
                dequeButtons.setVisible(true);
                titleLabel.setText("DEQUE");
                activeStructure = 3;
                clearElements();
            });

        sPush.setOnClick(
            [&]()
            {
                inputMode = true;
                inputField.clear();
                inputField.setVisible(true);
                inputField.setFocused(true);
                resultLabel.setVisible(false);
            });

        sPop.setOnClick(
            [&]()
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
            });

        sTop.setOnClick(
            [&]()
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
            });

        sSize.setOnClick(
            [&]()
            {
                inputField.setVisible(false);
                resultLabel.setText("Size: " + std::to_string(stack.GetSize()));
                resultLabel.setVisible(true);
            });

        sEmpty.setOnClick(
            [&]()
            {
                inputField.setVisible(false);
                resultLabel.setText(stack.IsEmpty() ? "Stack is EMPTY" : "Stack is NOT empty");
                resultLabel.setVisible(true);
            });

        sBack.setOnClick(
            [&]()
            {
                workLayout.setVisible(false);
                chooseLayout.setVisible(true);
                titleLabel.setText("CHOOSE STRUCTURE");
                inputField.setVisible(false);
                resultLabel.setVisible(false);
                inputMode = false;
                clearElements();
            });

        qEnqueue.setOnClick(
            [&]()
            {
                inputMode = true;
                inputField.clear();
                inputField.setVisible(true);
                inputField.setFocused(true);
                resultLabel.setVisible(false);
            });

        qDequeue.setOnClick(
            [&]()
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
            });

        qFront.setOnClick(
            [&]()
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
            });

        qBack.setOnClick(
            [&]()
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
            });

        qSize.setOnClick(
            [&]()
            {
                inputField.setVisible(false);
                resultLabel.setText("Size: " + std::to_string(queue.GetSize()));
                resultLabel.setVisible(true);
            });

        qEmpty.setOnClick(
            [&]()
            {
                inputField.setVisible(false);
                resultLabel.setText(queue.IsEmpty() ? "Queue is EMPTY" : "Queue is NOT empty");
                resultLabel.setVisible(true);
            });

        qReturn.setOnClick(
            [&]()
            {
                workLayout.setVisible(false);
                chooseLayout.setVisible(true);
                titleLabel.setText("CHOOSE STRUCTURE");
                inputField.setVisible(false);
                resultLabel.setVisible(false);
                inputMode = false;
                clearElements();
            });

        dPushFront.setOnClick(
            [&]()
            {
                inputMode = true;
                dequeInputMode = 1;
                inputField.clear();
                inputField.setVisible(true);
                inputField.setFocused(true);
                resultLabel.setVisible(false);
            });

        dPushBack.setOnClick(
            [&]()
            {
                inputMode = true;
                dequeInputMode = 2;
                inputField.clear();
                inputField.setVisible(true);
                inputField.setFocused(true);
                resultLabel.setVisible(false);
            });

        dPopFront.setOnClick(
            [&]()
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
            });

        dPopBack.setOnClick(
            [&]()
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
            });

        dFront.setOnClick(
            [&]()
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
            });

        dBack.setOnClick(
            [&]()
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
            });

        dSize.setOnClick(
            [&]()
            {
                inputField.setVisible(false);
                resultLabel.setText("Size: " + std::to_string(deque.GetSize()));
                resultLabel.setVisible(true);
            });

        dEmpty.setOnClick(
            [&]()
            {
                inputField.setVisible(false);
                resultLabel.setText(deque.IsEmpty() ? "Deque is EMPTY" : "Deque is NOT empty");
                resultLabel.setVisible(true);
            });

        dReturn.setOnClick(
            [&]()
            {
                workLayout.setVisible(false);
                chooseLayout.setVisible(true);
                titleLabel.setText("CHOOSE STRUCTURE");
                inputField.setVisible(false);
                resultLabel.setVisible(false);
                inputMode = false;
                clearElements();
            });

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
                if (event->is<sf::Event::Closed>()) window.close();

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

                    Button* elem = new Button(std::to_string(value));
                    elem->setSize(80.0f, 80.0f);
                    elem->setColor(sf::Color(173, 216, 230));

                    if (activeStructure == 1)
                    {
                        stack.Push(value);
                        resultLabel.setText("Pushed: " + std::to_string(value));
                        elementsLayout.append(*elem);
                    }
                    else if (activeStructure == 2)
                    {
                        queue.Enqueue(value);
                        resultLabel.setText("Enqueued: " + std::to_string(value));
                        elementsLayout.prepend(*elem);
                    }
                    else if (activeStructure == 3)
                    {
                        if (dequeInputMode == 1)
                        {
                            deque.PushFront(value);
                            resultLabel.setText("PushFront: " + std::to_string(value));
                            elementsLayout.prepend(*elem);
                        }
                        else
                        {
                            deque.PushBack(value);
                            resultLabel.setText("PushBack: " + std::to_string(value));
                            elementsLayout.append(*elem);
                        }
                        dequeInputMode = 0;
                    }

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