#include "Menu.hpp"

Menu::Menu(float width , float height , sf::Font& font){
    this->selectedIndex = 0;
    sf::Text play;
    play.setFont(font);
    play.setString("Start Game");
    play.setCharacterSize(40);
    play.setFillColor(sf::Color::Red);
    play.setPosition(width / 2 -100 , height / 2 -50);
    menuItems.push_back(play);

    sf::Text exit;
    exit.setFont(font);
    exit.setString("Exit");
    exit.setCharacterSize(40);
    exit.setFillColor(sf::Color::Black);
    exit.setPosition(width / 2 -100 , height / 2 + 10);
    menuItems.push_back(exit);
}
void Menu::draw(sf::RenderWindow& window){
    for(auto& item: menuItems){
        window.draw(item);
    }
}
void Menu::moveUp(){
    if(selectedIndex > 0){
        menuItems[selectedIndex].setFillColor(sf::Color::Black);
        selectedIndex--;
        menuItems[selectedIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::moveDown(){
    if(selectedIndex < menuItems.size() - 1 ){
        menuItems[selectedIndex].setFillColor(sf::Color::Black);
        selectedIndex++;
        menuItems[selectedIndex].setFillColor(sf::Color::Red);
    }
}

int Menu::getSelectedIndex() const {
    return selectedIndex;
}
Menu::Menu(){
    // nothing
}
Menu::~Menu(){
    // delete mem
}