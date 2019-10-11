#ifndef ANIMATEDFLAG_HPP
#define ANIMATEDFLAG_HPP

#include <random>
#include <math.h>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "log.hpp"

extern Config CONFIG;
extern std::string FLAG_FOLDER;


class AnimatedFlag
{
    /**
    Animated flag to fill the screen as a background.
    */
private:
    unsigned int waveCounter;
    sf::VertexArray flagVertices;
    sf::Sprite flag;
    std::vector<sf::Sprite> darkWaves;
    std::vector<sf::Sprite> lightWaves;
    sf::Texture flagTexture;
    sf::Texture lightWaveTexture;
    sf::Texture darkWaveTexture;

public:
    AnimatedFlag(const std::string flagName);
    void play(sf::RenderWindow &window);
};

#endif // ANIMATEDFLAG_HPP
