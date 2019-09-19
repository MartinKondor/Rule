#ifndef MAP_HPP
#define MAP_HPP

#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "utils.hpp"

extern std::string MAP_FOLDER;


class Map
{
private:


public:
    Map();

    /**
    Loads the map from the given MAP_FOLDER + mapName parameter.
    */
    Map(const std::string mapName);

    /**
    Displays the map.
    */
    void display(sf::RenderWindow& window);
};

#endif // MAP_HPP
