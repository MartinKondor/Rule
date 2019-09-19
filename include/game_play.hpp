#ifndef GAME_PLAY_HPP
#define GAME_PLAY_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include "screen.hpp"
#include "entity.hpp"
#include "human.hpp"


class GamePlay
{
private:
    std::vector<Entity*> entities;

public:
    GamePlay();

    /**
    Called from GameScreen.
    */
    void display(sf::RenderWindow& window);
};

#endif // GAME_PLAY_HPP
