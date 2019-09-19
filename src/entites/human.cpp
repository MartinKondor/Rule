#include "human.hpp"


Human::Human() {}

Human::Human(const unsigned int id, const unsigned int xPos, const unsigned int yPos)
    : Human(id, xPos, yPos, Animation("human"))
{}

Human::Human(const unsigned int id, unsigned int xPos, const unsigned int yPos, Animation animation)
{
    this->id = id;
    this->xPos = xPos;
    this->yPos = yPos;
    this->xSpeed = 0;
    this->ySpeed = 0;
    this->animation = animation;
}

void Human::display(sf::RenderWindow& window)
{
    this->xPos += this->xSpeed;
    this->yPos += this->ySpeed;
    this->animation.play(this->xPos, this->yPos, window);
}
