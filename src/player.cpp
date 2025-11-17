#include "player.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>

// Constructor sets the initial player frame to be standing still
Player::Player(const sf::Texture& texture) 
    : sf::Sprite(texture) {

    setTextureRect(frameRect);
    setScale({scale, scale}); 

}

// This method takes in the frame list and renders the animation to the screen
void Player::renderFrames(std::vector<int> framesList) {
    if(length != 0) {
        if(frameTimer >= frameDuration) {

            frameTimer = sf::seconds(0.f);

            currentIndex = (currentIndex + 1) % framesList.size();
            currentFrame = framesList[currentIndex];
            frameRect.position.x = currentFrame * FRAME_SIZE;
            frameRect.position.y = 0;
            frameRect.size.y = FRAME_SIZE;
            frameRect.size.x = FRAME_SIZE;

            setTextureRect(frameRect);
        }
    } 
}

// This is called in main.cpp to update the player
void Player::update(float dt) {

    frameTimer += sf::seconds(dt);
    direction = {0.f, 0.f};

    playerPos = getPosition();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        direction.x -= 1.f;
        renderFrames(walkLeftFrames);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        direction.x += 1.f;
        renderFrames(walkRightFrames);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        direction.y += 1.f;
        renderFrames(walkForwardsFrames);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        direction.y -= 1.f;
        renderFrames(walkBackwardsFrames);
    }

    // Normalization
    length = sqrt(pow(direction.x, 2.f) + pow(direction.y, 2.f));
    if (length != 0) direction /= length;

    move(direction * dt * walkingSpeed);
    
}