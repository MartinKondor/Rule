#ifndef ANIMATEDFLAG_HPP
#define ANIMATEDFLAG_HPP

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "log.hpp"

extern Config CONFIG;
extern std::string FLAG_FOLDER;


class AnimatedFlag
{
private:
    sf::Vector2u imgSize;
    unsigned int waveCount;
    sf::Sprite flag;
    std::vector<sf::Sprite> darkWaves;
    std::vector<sf::Sprite> lightWaves;
    std::vector<int> darkWaveXs;
    std::vector<int> lightWaveXs;
    sf::Texture flagTexture;
    sf::Texture lightWaveTexture;
    sf::Texture darkWaveTexture;

public:
    AnimatedFlag(const std::string flagName, const unsigned int waveCount);
    void play(sf::RenderWindow &window);
};

#endif // ANIMATEDFLAG_HPP
