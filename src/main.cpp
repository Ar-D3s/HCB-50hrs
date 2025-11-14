#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "tileMap.hpp"

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
    sf::IntRect frameRect({0, 0}, {FRAME_SIZE, FRAME_SIZE});
    player.setTextureRect(frameRect);

    // Basic tilemap
    std::vector<int> tileMap = 
    {0,0,0,0,0,0,0,0,0,0,
     0,1,1,0,0,0,0,0,0,0,
     0,1,1,0,0,0,0,0,0,0,
     0,0,0,0,0,0,0,0,0,0,
     0,0,0,0,0,2,0,0,0,0,
     0,1,0,0,0,0,0,0,0,0,
     0,1,0,0,0,0,0,0,0,0,
     0,1,1,0,0,0,0,0,0,0,
     0,1,1,0,0,0,0,0,0,0,
     0,0,0,0,0,0,0,0,0,0,
     0,0,0,0,0,0,0,0,0,0};

    // Creates the map
    sf::Texture mapTexture("textures/tileArray.png");

    Tilemap map(10, 10);
    map.load(tileMap);

    // Renders window and sets view to size of window
    sf::RenderWindow window(sf::VideoMode({windowWidth, windowHeight}), "My game");
    //window.setFramerateLimit(60);
    sf::View view;
    view.setCenter({320.f, 320.f});
    view.setSize({static_cast<float>(windowWidth), static_cast<float>(windowHeight)});

    // Game loop
    while (window.isOpen()) {

        // Creates delta time to update all objects
        dt = gameClock.restart().asSeconds();  

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

        player.update(dt);

        // Draws everything to the screen & displays it
        window.draw(map, &mapTexture);
        window.draw(player);
        window.display();
    }

    return 0;
}