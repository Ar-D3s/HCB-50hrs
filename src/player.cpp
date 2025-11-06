#include "player.hpp"
#include <SFML/Graphics.hpp>

Player::Player(const std::string &texturePath) {

    setTexture(texturePath);

}

void Player::renderFrames(std::vector<int> framesList) {

    if (clock.getElapsedTime().asSeconds() > frameDuration) {

        currentIndex = (currentIndex + 1) % framesList.size();
        int currentFrame = framesList[currentIndex];
        frameRect.position.x = currentFrame * FRAME_SIZE;
        frameRect.position.y = 0;
        frameRect.size.y = FRAME_SIZE;
        frameRect.size.x = FRAME_SIZE;
        setTextureRect(frameRect);
        clock.restart();

    }
}

void Player::update() {

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        move({0.f, 3.f});
        renderFrames(walkForwardsFrames);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        move({0.f, -3.f});
        renderFrames(walkBackwardsFrames);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        move({-3.f, 0.f});
        renderFrames(walkLeftFrames);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        move({3.f, 0.f});
        renderFrames(walkRightFrames);
    }

    playerPos = getPosition();
    
}