#include "tileset.hpp"

#include <iostream>


Tileset::Tileset() {}

void Tileset::load(const std::string tilesetName, const unsigned int tileWidth, const unsigned int tileHeight)
{
    this->tileWidth = tileWidth;
    this->tileHeight = tileHeight;

    sf::Image tilesetImg;
    if (!tilesetImg.loadFromFile(TILESET_FOLDER + tilesetName))
    {
        openMessageBox("Tileset cannot be loaded (" + TILESET_FOLDER + tilesetName + ")");
        exit(EXIT_FAILURE);
    }

    sf::Vector2u imgSize = tilesetImg.getSize();

    for (unsigned int i = 0; i < (unsigned int) (imgSize.y / this->tileHeight); i++)
    {
        for (unsigned int j = 0; j < (unsigned int) (imgSize.x / this->tileWidth); j++)
        {
            sf::Texture* texture = new sf::Texture();
            texture->loadFromImage(tilesetImg, sf::IntRect(j * this->tileWidth, i * this->tileHeight, this->tileWidth, this->tileHeight));
            this->tiles.push_back(texture);
        }
    }
}
