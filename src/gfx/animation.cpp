#include "animation.hpp"

#include <iostream>


Animation::Animation()
{}

Animation::Animation(const std::string animationName)
{
    this->animationName = animationName;
    this->width = 0;
    this->height = 0;
    this->frameIndex = 0;
    this->frameCount = 0;
    this->framesPerSecond = 1;
    this->counter.restart();

    // Determine animation size
    if (animationName == "human")
    {
        this->width = 138;
        this->height = 138;
    }
    else
    {
        std::cout << "Unknown animation name (" << animationName << ")" << std::endl;
        exit(1);
    }

    // Load animation image
    sf::Image animImg;
    if (!animImg.loadFromFile(ANIMATION_FOLDER + animationName + "/spritesheet.png"))
    {
        std::cout << "Cannot load animation (" << animationName << ")" << std::endl;
        exit(1);
    }



}

void Animation::play(const unsigned int xPos, const unsigned int yPos, sf::RenderWindow &window)
{
    /*
    // Set the position of each frame
    for (int i = 0; i < this->frameCount; i++)
    {
        this->frames[i].setPosition(this->xPos, this->yPos);
    }

    if (this->framesPerSecond > 0 && this->counter.getElapsedTime().asMilliseconds() >= (1000 / this->framesPerSecond))
    {
        //if (++this->frameIndex >= this->frameCount) {
        //    this->frameIndex = 0;
        //}
        if (this->frameIndex < this->frameCount - 1)
        {
            this->frameIndex++;
        }
        else
        {
            this->frameIndex = 0;
        }

        this->counter.restart();
    }
    */
}
