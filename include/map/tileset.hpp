#ifndef TILESET_HPP
#define TILESET_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "log.hpp"

extern std::string TILESET_FOLDER;


class Tileset
{
    /**
    Represents a tileset.
    */
public:
    unsigned int tileWidth;
    unsigned int tileHeight;
    std::vector<sf::Texture*> tiles;


    Tileset();
    void load(const std::string tilesetName, const unsigned int tileWidth, const unsigned int tileHeight);
};

#endif // TILESET_HPP
