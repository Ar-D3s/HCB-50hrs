#ifndef RENDERMAP_HPP
#define RENDERMAP_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Tilemap : public sf::VertexArray {

    public:

        int tilesWide;
        int tilesHigh;

        const int TILESIZE = 64;

        sf::Texture& textureMap;
        std::vector<int>& tiles;

        Tilemap(sf::Texture& texture, std::vector<int>& tilemap, int mapWidth, int mapHeight);

};

#endif