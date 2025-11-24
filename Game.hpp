#ifndef GAME_HPP
#define GAME_HPP 
#include "lib.hpp"
#include "Menu.hpp"
#include "Player.hpp"


class Game {
    public:
        
        static string *version;
        sf::RenderWindow *window;
        sf::Clock *clock;
        sf::CircleShape *cursor;
        sf::Texture *txt_cursor;
        Menu *menu;
        sf::Font *font;
        sf::Text *version_text;
        sf::Text *title_game;
        int *state = 0;
        Player *player;
        sf::Event *event;
    public:
        Game();
        // Game(int width , int height , int vwidth , int vheight , int title_size);
        ~Game();
        void run();
        void processEvents();
        void update(float *deltaTime);
        void render();
        void MainMenu();
        void InGame();
    public:
        string getVersion();
    // private:
        
};

#endif