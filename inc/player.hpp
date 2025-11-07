#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player : public sf::Sprite {

    public:

        sf::Vector2f playerPos;
        sf::Vector2f speed;

        sf::Texture playerSheet;

        sf::Time frameDuration = sf::seconds(0.2f);
        int currentFrame;
        int currentIndex;
        const int FRAME_SIZE = 16;
        sf::Time frameTimer;
        sf::IntRect frameRect;

        std::vector<int> walkForwardsFrames = {0, 1, 0, 2};
        std::vector<int> walkBackwardsFrames = {3, 4, 3, 5};
        std::vector<int> walkLeftFrames = {6, 7, 6, 8,};
        std::vector<int> walkRightFrames = {9, 10, 9, 11};

        explicit Player(const std::string &texturePath);

        void renderFrames(std::vector<int> framesList);

        void update(float dt);

};

#endif