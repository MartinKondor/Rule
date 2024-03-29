#ifndef MAP_HPP
#define MAP_HPP

#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "resource.hpp"
#include "tileset.hpp"
#include "utils.hpp"
#include "log.hpp"
#include "layer.hpp"

extern Config CONFIG;
extern std::string MAP_FOLDER;


class Map
{
    /**
    Represents an isometric map.
    */
private:

    /**
    Each layer has a tile matrix.
    */
    std::vector<Layer> layers;
    std::vector<Resource> resources;


    /**
    @returns the value from the given line
            which looks like this:
    ```
    key = value
    ```
    */
    std::string parseKeyValue(const std::string line);

    /**
    Loads in one tile vector from a line like:
    ```
    0, 1, 2, 3
    ```
    */
    std::vector<unsigned int> parseTileRow(std::string line);

public:
    Tileset tileset;


    Map();

    /**
    Loads the map from the given MAP_FOLDER + mapName parameter.
    */
    Map(const std::string mapName);

    /**
    Loads the map from the given file.
    */
    void load(const std::string fileName);
    void loadResources(const std::string fileName);

    /**
    Displays the map.
    */
    void display(sf::RenderWindow& window);
};

#endif // MAP_HPP
