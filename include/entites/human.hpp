#ifndef HUMAN_HPP
#define HUMAN_HPP

#include <string>
#include "gfx/animation.hpp"
#include "entity.hpp"


class Human : public Entity
{
private:
    Animation animation;

public:
    Human();
    Human(const unsigned int id, const unsigned int xPos, const unsigned int yPos);
    Human(const unsigned int id, const unsigned int xPos, const unsigned int yPos, Animation animation);
    virtual void display(sf::RenderWindow& window);
};

#endif // HUMAN_HPP
