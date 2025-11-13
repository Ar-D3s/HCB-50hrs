#include "tileMap.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

Tilemap::Tilemap(int mapWidth, int mapHeight) : sf::VertexArray(sf::PrimitiveType::Triangles),
    tilesWide(mapWidth), tilesHigh(mapHeight) {}

void Tilemap::load(std::vector<int>& tileMap) {

    resize(6 * tilesWide * tilesHigh);

    // Lets the numbers in tiles list be accessed in order
    int textureIndex = 0;

    // Cycles through each column
    for (int tileH = 0; tileH < tilesHigh; tileH ++) {

        // Keeps track of the elements in the vertex array
        int yIndex = tileH * tilesWide * 6;

        // Cycles through each row
        for (int tileW = 0; tileW < tilesWide; tileW ++) {

            // 
            int xIndex = yIndex + (tileW * 6);

            float xPos = tileW * TILESIZE;
            float yPos = tileH * TILESIZE;

            sf::Vector2f v0 = {xPos, yPos};
            sf::Vector2f v1 = {xPos + TILESIZE, yPos};
            sf::Vector2f v2 = {xPos, yPos + TILESIZE};
            sf::Vector2f v3 = {xPos + TILESIZE, yPos + TILESIZE};

            (*this)[xIndex].position = v0;
            (*this)[xIndex + 1].position = v1;
            (*this)[xIndex + 2].position = v2;
            (*this)[xIndex + 3].position = v3;
            (*this)[xIndex + 4].position = v2;
            (*this)[xIndex + 5].position = v1;  

            int tilePos = tileMap[textureIndex];

            (*this)[xIndex].texCoords = sf::Vector2f(16.f * tilePos, 0.f);            
            (*this)[xIndex + 1].texCoords = sf::Vector2f(16.f * tilePos + 16, 0.f);
            (*this)[xIndex + 2].texCoords = sf::Vector2f(16.f * tilePos, 16.f);
            (*this)[xIndex + 3].texCoords = sf::Vector2f(16.f * tilePos + 16, 16.f);
            (*this)[xIndex + 4].texCoords = sf::Vector2f(16.f * tilePos, 16.f);
            (*this)[xIndex + 5].texCoords = sf::Vector2f(16.f * tilePos + 16, 0.f);

            textureIndex ++;

        }
    }

}