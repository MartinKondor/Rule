#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "screen.hpp"
#include "screens/credits.hpp"
#include "screens/loading.hpp"
#include "screens/settings.hpp"
#include "screens/main_menu.hpp"
#include "screens/game.hpp"


#define WINDOW_TITLE "Rule"
extern Config CONFIG;
extern std::string BASE_FOLDER;
extern std::string IMAGE_FOLDER;
extern std::string ANIMATION_FOLDER;
extern std::string TILESET_FOLDER;
extern std::string RESOURCES_FOLDER;


int main(const int argc, const char** argv)
{

    // Define global variables
    BASE_FOLDER = Utils::getBaseDir(argv[0]);
    IMAGE_FOLDER = BASE_FOLDER + "images/";
    ANIMATION_FOLDER = BASE_FOLDER + "gfx/";
    TILESET_FOLDER = BASE_FOLDER + "tilesets/";
    MAP_FOLDER = BASE_FOLDER + "maps/";
    RESOURCES_FOLDER = MAP_FOLDER + "resources/";

    if (!CONFIG.load(BASE_FOLDER + "config.ini"))
    {
        std::cout << "Cannot load config." << std::endl;
        return EXIT_FAILURE;
    }

    // Initialize window
    sf::Event windowEvent;
    sf::RenderWindow window(sf::VideoMode(CONFIG.WINDOW_WIDTH, CONFIG.WINDOW_HEIGHT),
                            WINDOW_TITLE, CONFIG.IS_FULLSCREEN ? sf::Style::Fullscreen : sf::Style::Close);
    window.setFramerateLimit(CONFIG.FPS_LIMIT);
    window.resetGLStates();

    // Variables for screen changes
    Screen* screen = new LoadingScreen();
    ScreenType nextScreenType = ScreenType::LOADING;
    ScreenType currentScreenType = ScreenType::LOADING;
    sf::Color gameBgColor(0, 0, 0);


    // Main loop
    while (window.isOpen())
    {
        while (window.pollEvent(windowEvent))
        {
            if (windowEvent.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        if (currentScreenType == ScreenType::GAME)
        {
            window.clear(gameBgColor);
        }
        else
        {
            window.clear(CONFIG.BG_COLOR);
        }

        nextScreenType = screen->display(window);
        window.display();

        if (nextScreenType == ScreenType::EXIT)
        {
            window.close();
        }

        // Navigate to the next screen
        if (nextScreenType != currentScreenType)
        {
            currentScreenType = nextScreenType;

            // Switch to nextScreen if defined
            if (screen->nextScreen != nullptr)
            {
                screen = screen->nextScreen;
            }
            else if (nextScreenType == ScreenType::MAIN_MENU)
            {
                screen = new MainMenuScreen();
            }
            else if (nextScreenType == ScreenType::GAME)
            {
                screen = new GameScreen();
            }
            else if (nextScreenType == ScreenType::SETTINGS)
            {
                screen = new SettingsScreen(screen);
            }
            else if (nextScreenType == ScreenType::CREDITS)
            {
                screen = new CreditsScreen();
            }
            else if (nextScreenType == ScreenType::LOADING)
            {
                screen = new LoadingScreen();
            }
        }

    }

    return EXIT_SUCCESS;
}
