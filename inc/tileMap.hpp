#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Tilemap : public sf::VertexArray {

    public:

        int tilesWide;
        int tilesHigh;

        const int TILESIZE = 64;

        Tilemap(int mapWidth, int mapHeight);

        void load(std::vector<int>& tileMap);

};

#endif