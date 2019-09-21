#include "layer.hpp"


Layer::Layer() {}

Layer::Layer(std::vector<std::vector<unsigned int>> tiles)
{
    this->tiles = tiles;
}

void Layer::display(sf::RenderWindow &window, Tileset &tileset)
{
    sf::Sprite tileSprite;
    int cartX = 0;
    int cartY = 0;

    for (unsigned int i = 0; i < this->tiles.size(); i++)
    {
        for (unsigned int j = 0; j < this->tiles[i].size(); j++)
        {
            if (this->tiles[i][j] == 0)
            {
                continue;
            }

            tileSprite.setTexture(*tileset.tiles[this->tiles[i][j]]);

            cartX = j * tileset.tileWidth / 2;
            cartY = i * tileset.tileHeight / 2;

            tileSprite.setPosition(cartX - cartY, (cartX + cartY) / 2);
            window.draw(tileSprite);
        }
    }
}
