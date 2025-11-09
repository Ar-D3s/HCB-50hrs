#ifndef TILETYPES_HPP
#define TILETYPES_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

struct tileType {

    std::string name;
    bool solid;
    sf::IntRect textureRect;

};

std::vector<tileType> getTileTypes();

#endif