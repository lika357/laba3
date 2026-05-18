#include <SFML/Graphics.hpp>
#include <sstream>
#include <string>

#include "deque.hpp"
#include "queue.hpp"
#include "stack.hpp"

class Button
{
   private:
    sf::RectangleShape shape;
    sf::Text text;

   public:
    Button(float x, float y, float w, float h, const std::string& str, sf::Font& font) : text(font)
    {
        shape.setPosition({x, y});
        shape.setSize({w, h});
        shape.setFillColor(sf::Color::White);
        shape.setOutlineThickness(2);
        shape.setOutlineColor(sf::Color(101, 67, 33));
        text.setString(str);
        text.setCharacterSize(22);
        text.setFillColor(sf::Color::Black);
        sf::FloatRect b = text.getLocalBounds();
        text.setPosition({x + w / 2 - b.size.x / 2, y + h / 2 - b.size.y / 2 - 5});
    }

    void setText(const std::string& str)
    {
        text.setString(str);
        sf::FloatRect b = text.getLocalBounds();
        text.setPosition({shape.getPosition().x + shape.getSize().x / 2 - b.size.x / 2,
                          shape.getPosition().y + shape.getSize().y / 2 - b.size.y / 2 - 5});
    }

    bool clicked(sf::Vector2f m)
    {
        return shape.getGlobalBounds().contains(m);
    }

    void draw(sf::RenderWindow& w)
    {
        w.draw(shape);
        w.draw(text);
    }
};

std::string stackToString(Stack<int>& s)
{
    if (s.IsEmpty())
    {
        return "[]";
    }

    std::ostringstream ss;
    Stack<int> temp;

    while (!s.IsEmpty())
    {
        int val = s.Pop();
        temp.Push(val);
    }

    ss << "[";
    bool first = true;

    while (!temp.IsEmpty())
    {
        int val = temp.Pop();
        if (!first)
        {
            ss << ", ";
        }
        ss << val;
        first = false;
        s.Push(val);
    }

    ss << "]";
    return ss.str();
}

std::string queueToString(Queue<int>& q)
{
    if (q.IsEmpty())
    {
        return "[]";
    }

    std::ostringstream ss;
    Queue<int> temp;

    while (!q.IsEmpty())
    {
        int val = q.Dequeue();
        temp.Enqueue(val);
    }

    ss << "[";
    bool first = true;

    while (!temp.IsEmpty())
    {
        int val = temp.Dequeue();
        if (!first)
        {
            ss << ", ";
        }
        ss << val;
        first = false;
        q.Enqueue(val);
    }

    ss << "]";
    return ss.str();
}

int main()
{
    sf::RenderWindow window(sf::VideoMode({900, 650}),
                            "LABA 3");  // TODO:RenderWindow ПРОПИСАТЬ САМОЙ
    sf::Font font;

    if (!font.openFromFile("arial.ttf"))
    {
        return 1;
    }

    sf::Text title(font);
    title.setCharacterSize(30);
    title.setFillColor(sf::Color(101, 67, 33));
    title.setPosition({250, 40});

    Button btnStack(250, 120, 400, 55, "STACK", font);
    Button btnQueue(250, 185, 400, 55, "QUEUE", font);
    Button btnDeque(250, 250, 400, 55, "DEQUE", font);

    Button btnOp1(250, 100, 400, 50, "", font);
    Button btnOp2(250, 160, 400, 50, "", font);
    Button btnOp3(250, 220, 400, 50, "", font);
    Button btnOp4(250, 280, 400, 50, "", font);
    Button btnOp5(250, 340, 400, 50, "", font);
    Button btnOp6(250, 400, 400, 50, "", font);
    Button btnOp7(250, 460, 400, 50, "", font);
    Button btnBack(320, 530, 260, 50, "BACK", font);

    enum Screen
    {
        TYPE_SCREEN,
        MENU_SCREEN,
        INPUT_SCREEN,
        RESULT_SCREEN
    };

    Screen screen = TYPE_SCREEN;
    int containerType = 0;

    Stack<int> stack;
    Queue<int> queue;
    Deque<int> deque;

    std::string input;
    std::string result;
    int inputMode;

    sf::Text inputText(font);
    inputText.setCharacterSize(28);
    inputText.setFillColor(sf::Color::Black);
    inputText.setPosition({250, 280});

    sf::Text hint(font);
    hint.setCharacterSize(20);
    hint.setFillColor(sf::Color(120, 70, 70));
    hint.setPosition({200, 360});

    sf::Text output(font);
    output.setCharacterSize(24);
    output.setFillColor(sf::Color::Black);
    output.setPosition({60, 200});

    while (window.isOpen())
    {
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            if (screen == INPUT_SCREEN && event->is<sf::Event::TextEntered>())
            {
                auto* t = event->getIf<sf::Event::TextEntered>();

                if (t->unicode == '\b' && !input.empty())
                {
                    input.pop_back();
                }
                else if (t->unicode == '\r' && !input.empty())
                {
                    int val = std::stoi(input);
                    input.clear();

                    if (inputMode == 1)
                    {
                        stack.Push(val);
                        result = "Pushed: " + std::to_string(val);
                    }
                    else if (inputMode == 2)
                    {
                        queue.Enqueue(val);
                        result = "Enqueued: " + std::to_string(val);
                    }
                    else if (inputMode == 3)
                    {
                        deque.PushFront(val);
                        result = "PushFront: " + std::to_string(val);
                    }
                    else if (inputMode == 4)
                    {
                        deque.PushBack(val);
                        result = "PushBack: " + std::to_string(val);
                    }

                    screen = RESULT_SCREEN;
                }
                else if ((t->unicode >= '0' && t->unicode <= '9') || t->unicode == '-')
                {
                    input += static_cast<char>(t->unicode);
                }
            }

            if (auto* m = event->getIf<sf::Event::MouseButtonPressed>())
            {
                sf::Vector2f p = window.mapPixelToCoords(m->position);

                if (screen == TYPE_SCREEN)
                {
                    if (btnStack.clicked(p))
                    {
                        containerType = 1;
                        screen = MENU_SCREEN;
                    }
                    if (btnQueue.clicked(p))
                    {
                        containerType = 2;
                        screen = MENU_SCREEN;
                    }
                    if (btnDeque.clicked(p))
                    {
                        containerType = 3;
                        screen = MENU_SCREEN;
                    }
                }
                else if (screen == MENU_SCREEN)
                {
                    if (btnBack.clicked(p))
                    {
                        screen = TYPE_SCREEN;
                    }

                    if (containerType == 1)
                    {
                        if (btnOp1.clicked(p))
                        {
                            inputMode = 1;
                            input.clear();
                            screen = INPUT_SCREEN;
                        }
                        if (btnOp2.clicked(p))
                        {
                            try
                            {
                                result = "Pop: " + std::to_string(stack.Pop());
                            }
                            catch (const std::exception& e)
                            {
                                result = "Error: " + std::string(e.what());
                            }
                            screen = RESULT_SCREEN;
                        }
                        if (btnOp3.clicked(p))
                        {
                            try
                            {
                                result = "Peek: " + std::to_string(stack.Peek());
                            }
                            catch (const std::exception& e)
                            {
                                result = "Error: " + std::string(e.what());
                            }
                            screen = RESULT_SCREEN;
                        }
                        if (btnOp4.clicked(p))
                        {
                            result = "Size: " + std::to_string(stack.GetSize());
                            screen = RESULT_SCREEN;
                        }
                        if (btnOp5.clicked(p))
                        {
                            if (stack.IsEmpty())
                            {
                                result = "Stack is EMPTY";
                            }
                            else
                            {
                                result = "Stack is NOT empty";
                            }
                            screen = RESULT_SCREEN;
                        }
                        if (btnOp6.clicked(p))
                        {
                            result = "Stack: " + stackToString(stack);
                            screen = RESULT_SCREEN;
                        }
                    }
                    else if (containerType == 2)
                    {
                        if (btnOp1.clicked(p))
                        {
                            inputMode = 2;
                            input.clear();
                            screen = INPUT_SCREEN;
                        }
                        if (btnOp2.clicked(p))
                        {
                            try
                            {
                                result = "Dequeue: " + std::to_string(queue.Dequeue());
                            }
                            catch (const std::exception& e)
                            {
                                result = "Error: " + std::string(e.what());
                            }
                            screen = RESULT_SCREEN;
                        }
                        if (btnOp3.clicked(p))
                        {
                            try
                            {
                                result = "Front: " + std::to_string(queue.Front());
                            }
                            catch (const std::exception& e)
                            {
                                result = "Error: " + std::string(e.what());
                            }
                            screen = RESULT_SCREEN;
                        }
                        if (btnOp4.clicked(p))
                        {
                            try
                            {
                                result = "Back: " + std::to_string(queue.Back());
                            }
                            catch (const std::exception& e)
                            {
                                result = "Error: " + std::string(e.what());
                            }
                            screen = RESULT_SCREEN;
                        }
                        if (btnOp5.clicked(p))
                        {
                            if (queue.IsEmpty())
                            {
                                result = "Queue is EMPTY";
                            }
                            else
                            {
                                result = "Queue is NOT empty";
                            }
                            screen = RESULT_SCREEN;
                        }
                        if (btnOp6.clicked(p))
                        {
                            result = "Queue: " + queueToString(queue);
                            screen = RESULT_SCREEN;
                        }
                        if (btnOp7.clicked(p))
                        {
                            result = "Size: " + std::to_string(queue.GetSize());
                            screen = RESULT_SCREEN;
                        }
                    }
                    else if (containerType == 3)
                    {
                        if (btnOp1.clicked(p))
                        {
                            inputMode = 3;
                            input.clear();
                            screen = INPUT_SCREEN;
                        }
                        if (btnOp2.clicked(p))
                        {
                            inputMode = 4;
                            input.clear();
                            screen = INPUT_SCREEN;
                        }
                        if (btnOp3.clicked(p))
                        {
                            try
                            {
                                result = "PopFront: " + std::to_string(deque.PopFront());
                            }
                            catch (const std::exception& e)
                            {
                                result = "Error: " + std::string(e.what());
                            }
                            screen = RESULT_SCREEN;
                        }
                        if (btnOp4.clicked(p))
                        {
                            try
                            {
                                result = "PopBack: " + std::to_string(deque.PopBack());
                            }
                            catch (const std::exception& e)
                            {
                                result = "Error: " + std::string(e.what());
                            }
                            screen = RESULT_SCREEN;
                        }
                        if (btnOp5.clicked(p))
                        {
                            try
                            {
                                result = "Front: " + std::to_string(deque.Front());
                            }
                            catch (const std::exception& e)
                            {
                                result = "Error: " + std::string(e.what());
                            }
                            screen = RESULT_SCREEN;
                        }
                        if (btnOp6.clicked(p))
                        {
                            try
                            {
                                result = "Back: " + std::to_string(deque.Back());
                            }
                            catch (const std::exception& e)
                            {
                                result = "Error: " + std::string(e.what());
                            }
                            screen = RESULT_SCREEN;
                        }
                        if (btnOp7.clicked(p))
                        {
                            result = "Size: " + std::to_string(deque.GetSize());
                            screen = RESULT_SCREEN;
                        }
                    }
                }
                else if (screen == RESULT_SCREEN)
                {
                    if (btnBack.clicked(p))
                    {
                        screen = MENU_SCREEN;
                    }
                }
            }
        }

        if (screen == TYPE_SCREEN)
        {
            title.setString("CHOOSE STRUCTURE");
        }
        else if (screen == MENU_SCREEN)
        {
            if (containerType == 1)
            {
                title.setString("STACK");
            }
            else if (containerType == 2)
            {
                title.setString("QUEUE");
            }
            else if (containerType == 3)
            {
                title.setString("DEQUE");
            }
        }
        else if (screen == INPUT_SCREEN)
        {
            title.setString("INPUT");
        }
        else if (screen == RESULT_SCREEN)
        {
            title.setString("RESULT");
        }

        if (screen == MENU_SCREEN)
        {
            if (containerType == 1)
            {
                btnOp1.setText("Push");
                btnOp2.setText("Pop");
                btnOp3.setText("Peek");
                btnOp4.setText("GetSize");
                btnOp5.setText("IsEmpty");
                btnOp6.setText("Print");
                btnOp7.setText("");
            }
            else if (containerType == 2)
            {
                btnOp1.setText("Enqueue");
                btnOp2.setText("Dequeue");
                btnOp3.setText("Front");
                btnOp4.setText("Back");
                btnOp5.setText("IsEmpty");
                btnOp6.setText("Print");
                btnOp7.setText("GetSize");
            }
            else if (containerType == 3)
            {
                btnOp1.setText("PushFront");
                btnOp2.setText("PushBack");
                btnOp3.setText("PopFront");
                btnOp4.setText("PopBack");
                btnOp5.setText("Front");
                btnOp6.setText("Back");
                btnOp7.setText("GetSize");
            }
        }

        window.clear(sf::Color(255, 228, 225));
        window.draw(title);

        if (screen == TYPE_SCREEN)
        {
            btnStack.draw(window);
            btnQueue.draw(window);
            btnDeque.draw(window);
        }
        else if (screen == MENU_SCREEN)
        {
            btnOp1.draw(window);
            btnOp2.draw(window);
            btnOp3.draw(window);
            btnOp4.draw(window);
            btnOp5.draw(window);
            btnOp6.draw(window);
            btnOp7.draw(window);
            btnBack.draw(window);
        }
        else if (screen == INPUT_SCREEN)
        {
            if (containerType == 1)
            {
                hint.setString("Enter value to push:");
            }
            else if (containerType == 2)
            {
                hint.setString("Enter value to enqueue:");
            }
            else if (containerType == 3)
            {
                hint.setString("Enter value:");
            }
            inputText.setString("> " + input + "_");
            window.draw(inputText);
            window.draw(hint);
        }
        else if (screen == RESULT_SCREEN)
        {
            output.setString(result);
            window.draw(output);
            btnBack.draw(window);
        }

        window.display();
    }

    return 0;
}