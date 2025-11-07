#include "player.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>

Player::Player(const sf::Texture &texture) : sf::Sprite(texture) {

    playerPos = getPosition();
    wasPlayerPos = playerPos;

    initialFrameRect.position.x = 0;
    initialFrameRect.position.y = 0;
    initialFrameRect.size.x = FRAME_SIZE;
    initialFrameRect.size.y = FRAME_SIZE;
    setTextureRect(initialFrameRect);
}

void Player::renderFrames(std::vector<int> framesList) {
    if(magnitude != 0) {
        if(frameTimer >= frameDuration) {

            //frameTimer -= frameDuration;
            frameTimer = sf::seconds(0.f);

            currentIndex = (currentIndex + 1) % framesList.size();
            int currentFrame = framesList[currentIndex];
            frameRect.position.x = currentFrame * FRAME_SIZE;
            frameRect.position.y = 0;
            frameRect.size.y = FRAME_SIZE;
            frameRect.size.x = FRAME_SIZE;

            setTextureRect(frameRect);
        }
    } 


}

void Player::update(float dt) {

    frameTimer += sf::seconds(dt);

    wasPlayerPos = playerPos;
    playerPos = getPosition();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        move({(-walkingSpeed * dt), 0.f});
        renderFrames(walkLeftFrames);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        move({(walkingSpeed * dt), 0.f});
        renderFrames(walkRightFrames);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        move({0.f, (walkingSpeed * dt)});
        renderFrames(walkForwardsFrames);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        move({0.f, (-walkingSpeed * dt)});
        renderFrames(walkBackwardsFrames);
    }

    magnitude = sqrt(pow((wasPlayerPos.y - playerPos.y), 2.f) + pow((wasPlayerPos.x - playerPos.x), 2.f));
    velocity = magnitude / dt;
    
}