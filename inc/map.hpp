#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Tilemap : public sf::Drawable, public sf::VertexArray {

    public:

        int tilesWide;
        int tilesHigh;

        sf::Texture &textureMap;

        const int TILESIZE = 16;

        std::vector<int> &tiles;

        Tilemap(int mapWidth, int mapHeight);
        
        
};

#endif

/*

Things it needs to do:

- Take in an array of any size
- Draws the array to the screen
- Only draws things in the view


*/