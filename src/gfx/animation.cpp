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
    this->framesPerSecond = 8;
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

    // Load the animation
    if (!this->load(ANIMATION_FOLDER + animationName + "/spritesheet.png"))
    {
        std::cout << "Cannot load animation (" << animationName << ")" << std::endl;
        exit(1);
    }
}

bool Animation::load(const std::string fileName)
{
    // Load animation image
    sf::Image animImg;
    if (!animImg.loadFromFile(fileName))
    {
        return false;
    }

    sf::Vector2u imgSize = animImg.getSize();

    /*
    For testing load only the first row of the spritesheet.
    */
    for (unsigned int i = 0; i < (unsigned int) (imgSize.y / this->height); i++)
    {
        for (unsigned int j = 0; j < 8; j++)  // (unsigned int) (imgSize.x / this->width)
        {
            sf::Texture* texture = new sf::Texture();
            if (!texture->loadFromImage(animImg, sf::IntRect(j * this->width, i * this->height, this->width, this->height)))
            {
                return false;
            }

            sf::Sprite* sprite = new sf::Sprite();
            sprite->setTexture(*texture);
            this->frames.push_back(sprite);
        }
    }

    this->frameCount = 8;  // this->frames.size();
    return true;
}

void Animation::play(const unsigned int xPos, const unsigned int yPos, sf::RenderWindow &window)
{
    if (this->framesPerSecond > 0 && this->counter.getElapsedTime().asMilliseconds() >= (1000 / this->framesPerSecond))
    {
        if (++this->frameIndex >= this->frameCount)
        {
            this->frameIndex = 0;
        }
        this->counter.restart();
    }

    // Set the position of the frame
    this->frames[this->frameIndex]->setPosition(xPos, yPos);
    window.draw(*this->frames[this->frameIndex]);
}
