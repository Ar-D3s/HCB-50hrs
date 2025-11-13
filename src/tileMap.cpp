#include "tileMap.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "tileTypes.hpp"

Tilemap::Tilemap(int mapWidth, int mapHeight) : sf::VertexArray(sf::PrimitiveType::Triangles),
    tilesWide(mapWidth), tilesHigh(mapHeight) {}

void Tilemap::load(std::vector<int>& tileMap) {

    resize(6 * tilesWide * tilesHigh);
    auto tileTypes = getTileTypes();

    // Lets the numbers in tiles list be accessed in order
    int textureIndex = 0;

    // Cycles through and gives each tile the right position
    for (int tileH = 0; tileH < tilesHigh; tileH ++) {
        for (int tileW = 0; tileW < tilesWide; tileW ++) {

            int tileNumber = tileH * tilesWide * 6 + (tileW * 6);
            int tileNumberTesting = tileMap[tileH * tilesWide + tileW];

            if (tileNumber == tileNumberTesting) std::cout << "True" << "\n";

            float xPos = tileW * TILESIZE;
            float yPos = tileH * TILESIZE;

            sf::Vector2f v0 = {xPos, yPos};
            sf::Vector2f v1 = {xPos + TILESIZE, yPos};
            sf::Vector2f v2 = {xPos, yPos + TILESIZE};
            sf::Vector2f v3 = {xPos + TILESIZE, yPos + TILESIZE};

            (*this)[tileNumber].position = v0;
            (*this)[tileNumber + 1].position = v1;
            (*this)[tileNumber + 2].position = v2;
            (*this)[tileNumber + 3].position = v3;
            (*this)[tileNumber + 4].position = v2;
            (*this)[tileNumber + 5].position = v1;  

            int tilePos = tileMap[textureIndex];

            (*this)[tileNumber].texCoords = sf::Vector2f(16.f * tilePos, 0.f);            
            (*this)[tileNumber + 1].texCoords = sf::Vector2f(16.f * tilePos + 16, 0.f);
            (*this)[tileNumber + 2].texCoords = sf::Vector2f(16.f * tilePos, 16.f);
            (*this)[tileNumber + 3].texCoords = sf::Vector2f(16.f * tilePos + 16, 16.f);
            (*this)[tileNumber + 4].texCoords = sf::Vector2f(16.f * tilePos, 16.f);
            (*this)[tileNumber + 5].texCoords = sf::Vector2f(16.f * tilePos + 16, 0.f);

            textureIndex ++;

        }
    }
}