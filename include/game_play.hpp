#ifndef GAME_PLAY_HPP
#define GAME_PLAY_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include "screen.hpp"
#include "map.hpp"
#include "entity.hpp"
#include "human.hpp"


class GamePlay
{
private:
    Map* map;
    std::vector<Entity*> entities;

public:
    GamePlay();
    GamePlay(bool load);

    /**
    Called from GameScreen.
    */
    void display(sf::RenderWindow& window);
};

#endif // GAME_PLAY_HPP
