#ifndef LAYER_HPP
#define LAYER_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include "tileset.hpp"


class Layer
{
    /**
    Represents a map layer.
    */
private:
    std::vector<std::vector<unsigned int>> tiles;

public:

    Layer();
    Layer(std::vector<std::vector<unsigned int>> tiles);

    /**
    Displays the layer.
    */
    void display(sf::RenderWindow &window, Tileset &tileset);
};

#endif // LAYER_HPP
