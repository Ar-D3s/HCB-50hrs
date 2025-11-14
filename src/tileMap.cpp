#include "tileMap.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "tileTypes.hpp"

Tilemap::Tilemap(int mapWidth, int mapHeight) : sf::VertexArray(sf::PrimitiveType::Triangles),
    tilesWide(mapWidth), tilesHigh(mapHeight) {}

void Tilemap::load(std::vector<int>& tileMap) {

    resize(6 * tilesWide * tilesHigh);
    std::vector<tileType> tileTypes = getTileTypes();    

    // Lets the numbers in tiles list be accessed in order
    int textureIndex = 0;

    // Cycles through and gives each tile the right position
    for (int tileH = 0; tileH < tilesHigh; tileH ++) {
        for (int tileW = 0; tileW < tilesWide; tileW ++) {

            int tileNumber = tileH * tilesWide * 6 + (tileW * 6);
            int currentTile = tileMap[tileH * tilesWide + tileW];

            const tileType& type = tileTypes[currentTile];
            sf::FloatRect texRect = type.textureRect;

            float xPos = tileW * TILESIZE;
            float yPos = tileH * TILESIZE;

            sf::Vector2f vp0 = {xPos, yPos};
            sf::Vector2f vp1 = {xPos + TILESIZE, yPos};
            sf::Vector2f vp2 = {xPos, yPos + TILESIZE};
            sf::Vector2f vp3 = {xPos + TILESIZE, yPos + TILESIZE};

            (*this)[tileNumber].position = vp0;
            (*this)[tileNumber + 1].position = vp1;
            (*this)[tileNumber + 2].position = vp2;
            (*this)[tileNumber + 3].position = vp3;
            (*this)[tileNumber + 4].position = vp2;
            (*this)[tileNumber + 5].position = vp1;  

            sf::Vector2f vt0 = {texRect.position.x, texRect.position.y};
            sf::Vector2f vt1 = {texRect.position.x + texRect.size.x, texRect.position.y};
            sf::Vector2f vt2 = {texRect.position.x, texRect.position.y + texRect.size.y};
            sf::Vector2f vt3 = {texRect.position.x + texRect.size.x, texRect.position.y + texRect.size.y};

            (*this)[tileNumber].texCoords = vt0;          
            (*this)[tileNumber + 1].texCoords = vt1;
            (*this)[tileNumber + 2].texCoords = vt2;
            (*this)[tileNumber + 3].texCoords = vt3;
            (*this)[tileNumber + 4].texCoords = vt2;
            (*this)[tileNumber + 5].texCoords = vt1;

        }
    }
}