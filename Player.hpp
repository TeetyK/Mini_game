#include "lib.hpp"

class Player{
    public:
        string name;
    public:
        Player();
        ~Player();   
        void update(float dt);
        void draw(sf::RenderWindow& window);
    private:
        sf::Sprite sprite;
        sf::Texture texture;
        sf::Vector2f velocity;
        bool isOnGround;   
        const int frameWidth = 16;
        const int frameHeight = 32;
        vector<sf::IntRect>walkFrames; 
        int currentFrame =0;
        float frameDuration = 0.2f;
        float elapsedTime = 0.0f; 
};