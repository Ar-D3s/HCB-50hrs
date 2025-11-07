#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.hpp"

int main() {

    // Clock used for animation speeds and durations
    sf::Clock gameClock;
    sf::Time deltaTime;
    float dt;

    // Initial Window Dimensions
    unsigned int windowHeight = 600;
    unsigned int windowWidth = 800;

    // Frame size for all tiles
    const int FRAME_SIZE = 16;

    // Creates player and its texture
    sf::Texture playerSheet("textures/Player.png");
    Player player(playerSheet);
    player.setScale({4.f, 4.f});                      

    int currentIndex = 0;
    sf::IntRect frameRect({0, 0}, {FRAME_SIZE, FRAME_SIZE});
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

        // Clears everything and sets the new view before drawing to the screen
        window.clear({34, 73, 93});
        window.setView(view);

        // Creates delta time to update all objects
        deltaTime = gameClock.restart(); 
        dt = deltaTime.asSeconds();    

        player.update(dt);

        // Draws everything to the screen & displays it
        window.draw(player);
        window.display();
    }

    return 0;
}
