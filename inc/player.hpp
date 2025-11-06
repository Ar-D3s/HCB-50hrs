#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player : public sf::Sprite {

    public:

        sf::Vector2f playerPos;
        sf::Vector2f speed;

        float frameDuration;
        int currentFrame;
        int currentIndex;

        std::vector<int> walkForwardsFrames = {0, 1, 0, 2};
        std::vector<int> walkBackwardsFrames = {3, 4, 3, 5};
        std::vector<int> walkLeftFrames = {6, 7, 6, 8,};
        std::vector<int> walkRightFrames = {9, 10, 9, 11};

        sf::Vector2f walkForwards();
        sf::Vector2f walkBackwards();
        sf::Vector2f walkLeft();
        sf::Vector2f walkRight();

        void frameRender(sf::Clock clock, const int frameSize, int currentFrame, int currentIndex);

        void update();

};


#endif