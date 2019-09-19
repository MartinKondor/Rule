#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "log.hpp"

extern std::string ANIMATION_FOLDER;


class Animation
{
    /**
    Represents drawable animation,
    which is loaded from a spritesheet file.
    */
private:
    std::vector<sf::Texture*> textures;
    std::vector<sf::Sprite*> frames;
    std::string animationName;
    sf::Clock counter;
    unsigned int framesPerSecond;
    unsigned int width;
    unsigned int height;
    unsigned int frameIndex;
    unsigned int frameCount;

public:
    Animation();

    /**
    @param animationName is the folder in the ANIMATION_FOLDER,
        which contains a spritesheet.png file.
    */
    Animation(const std::string animationName);

    /**
    Loads animation from the given file.
    @returns false if animation cannot be loaded.
    */
    bool load(const std::string fileName);

    /**
    Changes the animation frame to the next one, and draws it out.
    */
    void play(const unsigned int xPos, const unsigned int yPos, sf::RenderWindow &window);
};

#endif // ANIMATION_HPP
