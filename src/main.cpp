#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.hpp"

int main() {

    // Initial Window Dimensions
    unsigned int windowHeight = 600;
    unsigned int windowWidth = 800;

    // Creates player and its texture
    sf::Texture playerSheet("textures/Player.png");
    sf::Sprite player(playerSheet);
    player.setScale({4.f, 4.f});

    // Player Animation Variables
    int frameHeight = 16;
    int frameWidth = 16;

    float frameDuration = 0.15f;
    sf::Clock clock;

    std::vector<int> walkForwards = {0, 1, 0, 2};
    std::vector<int> walkBackwards = {3, 4, 3, 5};
    int currentIndex = 0;
    sf::IntRect frameRect({0, 0}, {frameWidth, frameHeight});
    player.setTextureRect(frameRect);

    // Renders window and sets view to size of window
    sf::RenderWindow window(sf::VideoMode({windowWidth, windowHeight}), "My game");
    window.setFramerateLimit(60);
    sf::View view;
    view.setCenter({0.f, 0.f});
    view.setSize({static_cast<float>(windowWidth), static_cast<float>(windowHeight)});
 
    // Game loop
    while (window.isOpen()) {

        // Resets the view to the size of the window so stuff doesn't stretch when resizing
        while (const std::optional event = window.pollEvent()) {

            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            else if (const auto* resize = event->getIf<sf::Event::Resized>()) {
                windowWidth = resize->size.x;
                windowHeight = resize->size.y;

                view.setSize({static_cast<float>(windowWidth), static_cast<float>(windowHeight)});
                window.setView(view);
            }

        }

        window.clear({34, 73, 93});
        window.setView(view);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) player.move({0.f, -3.f});
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) player.move({3.f, 0.f});
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) player.move({-3.f, 0.f});
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
    
            player.move({0.f, 3.f});
            if (clock.getElapsedTime().asSeconds() > frameDuration) {

                currentIndex = (currentIndex + 1) % walkForwards.size();
                int currentFrame = walkForwards[currentIndex];
                frameRect.position.x = currentFrame * frameWidth;
                frameRect.position.y = 0;
                frameRect.size.y = frameHeight;
                frameRect.size.x = frameWidth;
                player.setTextureRect(frameRect);
                clock.restart();

        }

        }   

        window.draw(player);
        window.display();
    }

    return 0;
}
