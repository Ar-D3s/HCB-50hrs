#include "map.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

/*
For now, this and the tilemap will be hardcoded because I want to focus on other parts of world creation,
such as collisions and interactability. I will come back later and change it so that either a map can be 
loaded in from a binary file, or it can be randomly generated. For these approaches, the map width/height will
be determined by square rooting the number of tiles in the file as the map will always be a square.
*/ 

Tilemap::Tilemap(int mapWidth, int mapHeight) : tilesWide(mapWidth), tilesHigh(mapHeight) {

    setPrimitiveType(sf::PrimitiveType::Triangles);
    resize(6 * tilesWide * tilesHigh);

}










/*

For now, being hardcoded:
Create vertex array in constructor
Fill it with textures using hardcoded tilemap,
both passed into the textureise method

*/