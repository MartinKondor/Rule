#ifndef GAME_SCREEN_HPP
#define GAME_SCREEN_HPP

#include <SFML/Graphics.hpp>
#include "screen.hpp"
#include "gui/button.hpp"
#include "game_play.hpp"


enum class GameSubScreen
{
    IN_GAME,
    GAME
};


class GameScreen : public Screen
{
    /**
    Game screen, where the game is happending.
    */
private:
    GamePlay game;
    GameSubScreen subScreen;


public:
    GameScreen();
    virtual ScreenType display(sf::RenderWindow& window);
};

#endif // GAME_SCREEN_HPP
