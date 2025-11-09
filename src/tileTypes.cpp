#include "tileTypes.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

std::vector<tileType> getTileTypes() {
    return {
        {"Grass", false, sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(16, 16))},
        {"Flowers", false, sf::IntRect(sf::Vector2i(16, 0), sf::Vector2i(16, 16))},
        {"Water", true, sf::IntRect(sf::Vector2i(32, 0), sf::Vector2i(16, 16))}
    };
}
