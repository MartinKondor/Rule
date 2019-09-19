#include "map.hpp"

#include <iostream>


Map::Map() {}

Map::Map(const std::string mapName)
{
    const std::string fileName = MAP_FOLDER + mapName;

    if (!Utils::isFileExists(fileName))
    {
        std::cout << "Cannot load map, as the " << fileName << "doesn't exist." << std::endl;
        exit(1);
    }

    std::cout << fileName << std::endl;

}

void Map::display(sf::RenderWindow& window) {}
