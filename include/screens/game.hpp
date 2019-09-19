#ifndef GAME_SCREEN_HPP
#define GAME_SCREEN_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "screen.hpp"
#include "gui/button.hpp"
#include "game_play.hpp"

extern Config CONFIG;
extern std::string IMAGE_FOLDER;


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

    // In game menu elements
    sf::Texture* inGameMenuBackgroundTexture;
    sf::Sprite inGameMenuBackground;
    sf::Sprite logo;
    sf::Texture logoTexture;
    Button inGameResumeButton;
    Button inGameSaveGameButton;
    Button inGameResignButton;
    Button inGameSettingsButton;
    Button inGameExitButton;

public:
    GameScreen();
    ScreenType displayInGameMenu(sf::RenderWindow& window);
    virtual ScreenType display(sf::RenderWindow& window);
};

#endif // GAME_SCREEN_HPP
