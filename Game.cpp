
// #define GAME_CPP
#include "Game.hpp"

// string Game::version = "Game version 1.0";


Game::Game() /*: window(sf::VideoMode(800,600),"Mini_Game") , */
 /* Cursor */ /*cursor(10.f) ,  */
 /*Menu*/ /*menu(window.getSize().x , window.getSize().y ,font)*/
 {
    // initalize variable
    this->version = "Game version 1.0";
    this->window = new sf::RenderWindow(sf::VideoMode(800,600),"Mini_Game");
    this->cursor = new sf::CircleShape(10.f);
    this->menu = new Menu(this->window.getSize().x , window->getSize().y , this->font);
    cout << this->version << endl;

    this->font->loadFromFile("Nunito.ttf");
    this->window->setFramerateLimit(60);
    this->cursor->setFillColor(sf::Color(150, 50, 250));
    this->cursor->setOrigin(10.f,10.f);
    this->txt_cursor->loadFromFile("items/cursor.png");
    this->cursor->setTexture(ths->txt_cursor);
    this->window->setMouseCursorVisible(false);
    //Footer
    this->version_text->setFont(this->font);
    this->version_text->setString(this->version + " By TeetyK");
    this->version_text->setCharacterSize(15);
    this->version_text->setFillColor(sf::Color::Black);
    this->version_text->setPosition((ths->window->getSize().x ) - 300, (this->window->getSize().y) -105);
    // title
    this->title_game->setFont(this->font);
    this->title_game->setString("Fake Mario");
    this->title_game->setCharacterSize(40);
    this->title_game->setFillColor(sf::Color::Black);
    this->title_game->setPosition((this->window->getSize().x - 100) / 2, 30);

}
Game::~Game(){
    // Nonting
    del *window;
    del *version;
    del *clock;
    del *cursor;
    del *txt_cursor;
    del *menu;
    del *font;
    del *version_text;
    del *title_game;
    del *state = 0;
    del *player;
}
string Game::getVersion(){
    return this->version;
}
void Game::run(){
    while (this->window.isOpen())
    {
        float *dt = this->clock.restart().asSeconds();
        processEvents();
        update(this->dt);
        render();
    }
}
void Game::update(float *deltaTime){
    // Nonting
    this->player->update(this->deltaTime);
}
void Game::processEvents(){

    while (this->window->pollEvent(this->event))
        {
            if (ths->event->type == sf::Event::Closed){
                this->window->close();
            }
            if (this->event->type == sf::Event::LostFocus){
                cout << "Pasue" << endl;
            }
            if (this->event->type == sf::Event::GainedFocus){
                cout << "Resume" << endl;
            }
            if (this->event->type == sf::Event::MouseMoved){
                float *x = event.mouseMove.x;
                float *y = event.mouseMove.y;
                cursor.setPosition(this->x,this->y);
            }
            if (this->event->type == sf::Event::KeyPressed){
                if( this->event->key->code == sf::Keyboard::Up){
                    this->menu->moveUp();
                }else if( this->event->key->code == sf::Keyboard::Down){
                    this->menu->moveDown();
                }else if ( this->event->key->code ==sf::Keyboard::Enter){
                    int *selected = this->menu->getSelectedIndex();
                    if( this->selected == 0){
                        // Game start
                        Game::state=1;
                        cout << "Game started go" << endl;
                    }else if(this->selected == 1){
                        this->window->close();
                    }
                }
            }
        }
}
void Game::render(){
    this->window->clear(sf::Color::White);
    // draw
    if(Game::state ==0){
        MainMenu();
    }else if(Game::state ==1){ // In-Game
        InGame();
    }

    // display
    this->window->display();
}
void Game::MainMenu(){
    this->menu->draw(this->window);
    this->window->draw(this->cursor);
    this->window->draw(this->version_text);
    this->window->draw(this->title_game);    
}
void Game::InGame(){
    this->window->draw(this->cursor);
    this->player->draw(this->window);
}