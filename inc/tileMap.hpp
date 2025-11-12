#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Tilemap : public sf::VertexArray {

    public:

        int tilesWide;
        int tilesHigh;
        std::vector<int>& tileMap;

        const int TILESIZE = 64;

        Tilemap(std::vector<int>& tilemap, int mapWidth, int mapHeight);

        void load();

};

#endif