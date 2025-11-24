#ifndef MENU_HPP
#define MENU_HPP
#include "lib.hpp"

class Menu {
    public:
        Menu(float width , float height , sf::Font& font);
        ~Menu();
        Menu();
        void draw(sf::RenderWindow& window);
        void moveUp();
        void moveDown();
        int getSelectedIndex() const;
    private:
        vector<sf::Text> menuItems;
        int selectedIndex;
};
#endif