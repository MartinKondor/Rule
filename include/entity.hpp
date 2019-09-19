#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>


enum class Direction
{
    SOUTH,
    SOUTH_WEST,
    WEST,
    NORTH_WEST,
    NORTH,
    NORTH_EAST,
    EAST,
    SOUTH_EAST
};


class Entity
{
    /**
    Abstract entity class.

    Every living object must inherit this class.
    */
public:
    unsigned int id;
    unsigned int xPos;
    unsigned int yPos;
    unsigned int xSpeed;
    unsigned int ySpeed;
    Direction direction;

    virtual void display(sf::RenderWindow& window) = 0;
};

#endif // ENTITY_HPP
