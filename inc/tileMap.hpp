#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Tilemap : public sf::VertexArray {

    public:

        int tilesWide;
        int tilesHigh;

        const int TILESIZE = 64;

        std::vector<int>& tiles;

        Tilemap(std::vector<int>& tilemap, int mapWidth, int mapHeight);

};

#endif