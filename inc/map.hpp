#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Tilemap : public sf::Drawable, public sf::VertexArray {

    public:

        int tilesWide;
        int tilesHigh;

        const int TILESIZE = 16;

        sf::Texture& textureMap;
        std::vector<int>& tiles;

        Tilemap(int mapWidth, int mapHeight, sf::Texture& texture, std::vector<int>& tileMap);
        
};

#endif

/*

Things it needs to do:

- Take in an array of any size
- Draws the array to the screen
- Only draws things in the view


*/