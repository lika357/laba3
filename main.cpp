#include "gui/lika_window.hpp"

sf::Font Widget::defaultFont;
int main()
{
    LikaWindow lw(1200, 900, "LABA 3");
    lw.run();
    return 0;
}