#include "tileTypes.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

std::vector<tileType> getTileTypes() {
    return {
        {"Grass", false, sf::FloatRect(sf::Vector2f(0, 0), sf::Vector2f(16, 16))},
        {"Flowers", false, sf::FloatRect(sf::Vector2f(16, 0), sf::Vector2f(16, 16))},
        {"Water", true, sf::FloatRect(sf::Vector2f(32, 0), sf::Vector2f(16, 16))}
    };
}