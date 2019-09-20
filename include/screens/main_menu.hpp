#ifndef MAIN_MENU_SCREEN_HPP
#define MAIN_MENU_SCREEN_HPP

#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "screen.hpp"
#include "gui/button.hpp"

extern Config CONFIG;
extern std::string IMAGE_FOLDER;


enum class MainMenuSubScreen
{
    NONE,
    NEW_GAME,
    LOAD_GAME
};


class MainMenuScreen : public Screen
{
    /**
    Main menu screen.
    */
private:
    sf::Texture logoTexture;
    sf::Sprite logo;

    sf::Text newGameSubScreenTitle;
    sf::Text loadGameSubScreenTitle;
    Button newGameButton;
    Button loadSaveGameButton;
    Button settingsButton;
    Button creditsButton;
    Button exitButton;
    Button subScreenBackButton;
    MainMenuSubScreen subScreen;

public:
    MainMenuScreen();
    ScreenType displaySubScreen(sf::RenderWindow &window);
    virtual void event(sf::Event& event);
    virtual ScreenType display(sf::RenderWindow& window);
};

#endif // MAIN_MENU_SCREEN_HPP
