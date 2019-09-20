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
    sf::Texture logoTexture;
    sf::Sprite logo;

    sf::Texture inGameMenuBackgroundTexture;
    sf::Sprite inGameMenuBackground;
    Button inGameResumeButton;
    Button inGameSaveGameButton;
    Button inGameResignButton;
    Button inGameSettingsButton;
    Button inGameExitButton;

public:
    GameScreen();
    ScreenType displayInGameMenu(sf::RenderWindow& window);
    virtual void event(sf::Event& event);
    virtual ScreenType display(sf::RenderWindow& window);
};

#endif // GAME_SCREEN_HPP
