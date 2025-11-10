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
    sf::Texture playerSheet;
    if (!playerSheet.loadFromFile("C:/Users/Archie/Desktop/HCB-50hrs/HCB-50hrs/textures/player.png")) {
        std::cerr << "Failed to load player texture!" << std::endl;
        return -1;
    }

    Player player(playerSheet);
    player.setScale({4.f, 4.f});                      
    sf::IntRect frameRect({0, 0}, {FRAME_SIZE, FRAME_SIZE});
    player.setTextureRect(frameRect);

    // Basic tilemap
    std::vector<int> tileMap = 
    {0,0,0,0,0,0,0,0,0,0,
     0,1,1,0,0,0,0,2,2,2,
     0,1,1,0,0,0,2,2,2,2,
     0,0,0,0,0,0,2,2,2,2,
     0,0,0,0,0,0,0,2,2,0,
     0,1,0,0,0,0,2,2,2,0,
     0,1,0,0,0,0,2,2,2,0,
     0,1,1,0,0,0,0,0,2,0,
     0,1,1,0,0,0,0,0,0,0,
     0,0,0,0,0,0,0,0,0,0,
     0,0,0,0,0,0,0,0,0,0};

    // Creates the map
    sf::Texture mapTexture;
    if (!mapTexture.loadFromFile("C:/Users/Archie/Desktop/HCB-50hrs/HCB-50hrs/textures/tileArray.png")) {
        std::cerr << "Failed to load map texture!" << std::endl;
        return -1; // Stop the program if it can't load
    }

    Tilemap map(tileMap, 10, 10);

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

/*

In order to pass the tilemap by reference into the constructor, the tilemap needs to exist before
passing it in.

For loading in - have a file to load in the map and metadata, make a vertex array out of it, pass it into 
main and then from there pass it into the tileMap constructor

For randomly generating - have a file to randomly generate the correct size map, and use perlin noise
to smooth the terrain. Then, load this into main and hence pass it into the tileMap constructor

tileMap.cpp/.hpp have no part in making the array/list, they just take it and render it to the screen

*/