#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.hpp"

int main() {

    // Initial Window Dimensions
    unsigned int windowHeight = 600.f;
    unsigned int windowWidth = 800.f;

    float playerTileSize = 16.f;
    int frameSpeed = 5;
    int frameCount = 0;
    int animationFrameCount = 1;

    // Renders window and sets view to size of window
    sf::RenderWindow window(sf::VideoMode({windowWidth, windowHeight}), "My game");
    window.setFramerateLimit(60);
    sf::View view;
    view.setCenter({0.f, 0.f});
    view.setSize({static_cast<float>(windowWidth), static_cast<float>(windowHeight)});

    // Creates player and its texture
    sf::Texture playerSheet("textures/Player.png");
    sf::Sprite player(playerSheet);
    player.setTextureRect(sf::IntRect({0, 0}, {16, 16}));
    player.setScale({4.f, 4.f});

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

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) player.move({0.f, -5.f});
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) player.move({0.f, 5.f});
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) player.move({-5.f, 0.f});
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) player.move({5.f, 0.f});

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) player.setTextureRect(sf::IntRect({16, 0}, {32, 16}));

        window.draw(player);
        window.display();
    }

    return 0;
}
