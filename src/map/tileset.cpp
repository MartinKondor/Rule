#include "tileset.hpp"

#include <iostream>


Tileset::Tileset() {}

void Tileset::load(const std::string tilesetName, const unsigned int tileWidth, const unsigned int tileHeight)
{
    sf::Image tilesetImg;
    if (!tilesetImg.loadFromFile(TILESET_FOLDER + tilesetName))
    {
        std::cout << "Tileset cannot be loaded (" << TILESET_FOLDER + tilesetName << ")" << std::endl;
        exit(1);
    }

    sf::Vector2u imgSize = tilesetImg.getSize();

    for (unsigned int i = 0; i < (unsigned int) (imgSize.y / tileHeight); i++)
    {
        for (unsigned int j = 0; j < (unsigned int) (imgSize.x / tileWidth); j++)
        {
            sf::Texture* texture = new sf::Texture();
            texture->loadFromImage(tilesetImg, sf::IntRect(j * tileWidth, i * tileHeight, tileWidth, tileHeight));
            this->tiles.push_back(texture);
        }
    }
}
