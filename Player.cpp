#include "Player.hpp"
Player::Player(){
    //initalize
    texture.loadFromFile("items/characters.gif");
    sprite.setTexture(texture);
    sprite.setPosition(100,400);
    // sprite.setScale(1.05f,1.05f);
    int pn = 16;
    walkFrames = {
        sf::IntRect(14*frameWidth,0*frameHeight,frameWidth,frameHeight),
        sf::IntRect(12*frameWidth,0*frameHeight,frameWidth,frameHeight),
        sf::IntRect(11*frameWidth,0*frameHeight,frameWidth,frameHeight),
        sf::IntRect(10*frameWidth,0*frameHeight,frameWidth,frameHeight),
    };
    velocity ={0.f , 0.f};
    isOnGround = false;
}
Player::~Player(){
    // del mem
}
void Player::update(float dt){
    elapsedTime+=dt;

    velocity.y += 981*dt;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        sprite.move(-200*dt,0);
        if(elapsedTime >= frameDuration){
            currentFrame = (currentFrame +1) % walkFrames.size();
            sprite.setTextureRect(walkFrames[currentFrame]);
            elapsedTime = 0.f;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        sprite.move(200*dt,0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        velocity.y = -450;
        isOnGround = false;
    }
    sprite.move(0,velocity.y*dt);
    if(sprite.getPosition().y >=400){
        sprite.setPosition(sprite.getPosition().x , 400);
        isOnGround = true;
        velocity.y = 0;
    }
}
void Player::draw(sf::RenderWindow& window){
    window.draw(sprite);
}