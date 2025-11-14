#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

class Player : public sf::Sprite {

    public:

        // Current player position
        sf::Vector2f playerPos;
        
        // Attributes for walking speeds
        float walkingSpeed = 120.f;
        float length;
        sf::Vector2f direction{0.f, 0.f};

        // Attributes for animation
        int currentFrame;
        int currentIndex;
        const int FRAME_SIZE = 16;
        sf::Time frameTimer;
        sf::IntRect frameRect = sf::IntRect({0, 0}, {16, 16});
        sf::Time frameDuration = sf::seconds(0.2f);

        // Player collision box
        sf::FloatRect physicsBox = sf::FloatRect({16, 0}, {16, 16});

        // Lists of frame orders for animation
        std::vector<int> walkForwardsFrames = {0, 1, 0, 2};
        std::vector<int> walkBackwardsFrames = {3, 4, 3, 5};
        std::vector<int> walkLeftFrames = {6, 7, 6, 8};
        std::vector<int> walkRightFrames = {9, 10, 9, 11};

        // Constructor
        explicit Player(const sf::Texture &texture);

        // Methods
        void renderFrames(std::vector<int> framesList);

        void update(float dt);

};

#endif