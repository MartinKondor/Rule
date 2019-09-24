#include <random>
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
#include "log.hpp"
#include "gfx/animated_flag.hpp"


extern Config CONFIG;
extern std::string BASE_FOLDER;
extern std::string IMAGE_FOLDER;
extern std::string ANIMATION_FOLDER;
extern std::string TILESET_FOLDER;
extern std::string RESOURCES_FOLDER;
extern std::string FLAG_FOLDER;


int main(const int argc, const char** argv)
{
    srand(time(NULL));

    // Define global variables
    BASE_FOLDER = Utils::getBaseDir(argv[0]);
    IMAGE_FOLDER = BASE_FOLDER + "images/";
    ANIMATION_FOLDER = BASE_FOLDER + "gfx/animations/";
    FLAG_FOLDER = BASE_FOLDER + "gfx/flags/";
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
    sf::RenderWindow window(sf::VideoMode(CONFIG.WINDOW_WIDTH, CONFIG.WINDOW_HEIGHT), "Rule", CONFIG.IS_FULLSCREEN ? sf::Style::Fullscreen : sf::Style::Close);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(CONFIG.FPS_LIMIT);
    window.requestFocus();
    window.resetGLStates();

    // Variables for screen changes
    LoadingScreen* loadingScreen = new LoadingScreen();
    Screen* screen = loadingScreen;
    ScreenType nextScreenType = ScreenType::LOADING;
    ScreenType currentScreenType = ScreenType::LOADING;
    sf::Color gameBgColor(0, 0, 0);

    // Load flag background
    AnimatedFlag flagBg("rule_flag");

    // Main loop
    while (window.isOpen())
    {
        // Handle events
        while (window.pollEvent(windowEvent))
        {
            if (windowEvent.type == sf::Event::Closed)
            {
                window.close();
            }
            screen->event(windowEvent);
        }

        // Clear screen
        window.clear(CONFIG.BACKGROUND);
        flagBg.play(window);

        // Display screen if it's loaded
        if (screen->screenIsLoaded)
        {
            nextScreenType = screen->display(window);
        }
        else
        {
            loadingScreen->display(window);
        }
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
