#ifndef GAME_PLAY_HPP
#define GAME_PLAY_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "map.hpp"
#include "entity.hpp"
#include "human.hpp"

extern Config CONFIG;


class GamePlay
{
private:
    float cameraX;
    float cameraY;

    Map* map;
    std::vector<Entity*> entities;

public:
    sf::View view;  // Player's view


    GamePlay();
    GamePlay(bool load);

    /**
    Called from GameScreen.
    */
    void display(sf::RenderWindow& window);
};

#endif // GAME_PLAY_HPP
