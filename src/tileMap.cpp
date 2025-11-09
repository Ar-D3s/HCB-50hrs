#include "tileMap.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

/*
For now, this and the tilemap will be hardcoded because I want to focus on other parts of world creation,
such as collisions and interactability. I will come back later and change it so that either a map can be 
loaded in from a binary file, or it can be randomly generated. For these approaches, the map width/height will
be determined by square rooting the number of tiles in the file as the map will always be a square.
*/ 

Tilemap::Tilemap(int mapWidth, int mapHeight, sf::Texture& texture, std::vector<int>& tileMap) 
    : sf::VertexArray(), tilesWide(mapWidth), tilesHigh(mapHeight), textureMap(texture), tiles(tileMap) {

    setPrimitiveType(sf::PrimitiveType::Triangles);
    resize(6 * tilesWide * tilesHigh);

    for (int tileH = 0; tileH < tilesHigh; tileH ++) {

        int counter = tileH * tilesWide * 6;

        for (int tileW = 0; tileW < tilesWide; tileW ++) {

            int realCounter = counter + (tileW * 6);

            float indexX = tileW * TILESIZE;
            float indexY = tileH * TILESIZE;

            sf::Vector2f v0 = {indexX, indexY};
            sf::Vector2f v1 = {indexX + TILESIZE, indexY};
            sf::Vector2f v2 = {indexX, indexY + TILESIZE};
            sf::Vector2f v3 = {indexX + TILESIZE, indexY + TILESIZE};

            (*this)[realCounter].position = v0;
            (*this)[realCounter + 1].position = v1;
            (*this)[realCounter + 2].position = v2;
            (*this)[realCounter + 3].position = v3;
            (*this)[realCounter + 4].position = v2;
            (*this)[realCounter + 5].position = v1;  
        }
    
    }

    int vertexCount = 0;
    for (int i : tileMap) {
    std::cout << i << std::endl;
        (*this)[vertexCount].texCoords = sf::Vector2f(16.f * i, 0.f);            
        (*this)[vertexCount + 1].texCoords = sf::Vector2f(16.f * i + 16, 0.f);
        (*this)[vertexCount + 2].texCoords = sf::Vector2f(16.f * i, 16.f);
        (*this)[vertexCount + 3].texCoords = sf::Vector2f(16.f * i + 16, 16.f);
        (*this)[vertexCount + 4].texCoords = sf::Vector2f(16.f * i, 16.f);
        (*this)[vertexCount + 5].texCoords = sf::Vector2f(16.f * i + 16, 0.f);
        vertexCount += 6;
    }

}
                          
/*

go through the tilemap, accessing its elements
multiply each element with the x coordinate of .texCoords


*/