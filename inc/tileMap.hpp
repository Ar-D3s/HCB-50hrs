#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Tilemap : public sf::VertexArray {

    public:

        int tilesWide;
        int tilesHigh;

        const int TILESIZE = 64;

        sf::Texture& textureMap;
        std::vector<int>& tiles;

        Tilemap(int mapWidth, int mapHeight, sf::Texture& texture, std::vector<int>& tileMap);

        void load();
        void generateTileMap();
        
};

#endif