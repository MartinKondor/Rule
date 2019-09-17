#include <iostream>
#include <SFML/Graphics.hpp>
#include "utils.hpp"
#include <config.hpp>
#include <consts.hpp>
#include <loading_screen.hpp>
#include <settings_screen.hpp>
#include <main_menu_screen.hpp>
#include <game_screen.hpp>


// Define global variables
extern std::string BASE_FOLDER = "";
extern Config CONFIG = Config();

/**
Parses the current working directory from the exeFilePath parameter.
*/
std::string getBaseDir(std::string exeFilePath);


int main(const int argc, const char** argv) {

    // Load global variables
    BASE_FOLDER = getBaseDir(argv[0]);
    if (!CONFIG.load(BASE_FOLDER + "config.ini")) {
        std::cout << "Cannot load config." << std::endl;
        return EXIT_FAILURE;
    }

    sf::Event windowEvent;
    sf::RenderWindow window(sf::VideoMode(CONFIG.WINDOW_WIDTH, CONFIG.WINDOW_HEIGHT),
                                WINDOW_TITLE, CONFIG.IS_FULLSCREEN ? sf::Style::Fullscreen : sf::Style::Close);
    window.setFramerateLimit(CONFIG.FPS_LIMIT);
    window.resetGLStates();

    Screen* screen = new LoadingScreen();
    ScreenType nextScreenType = ScreenType::LOADING;
    ScreenType currentScreenType = ScreenType::LOADING;

    while (window.isOpen()) {
        while (window.pollEvent(windowEvent)) {
            if (windowEvent.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        nextScreenType = screen->display(window);
        window.display();

        // Navigate to the next screen
        if (nextScreenType != currentScreenType) {

            if (nextScreenType == ScreenType::MAIN_MENU) {
                screen = new MainMenuScreen();
            }
            else if (nextScreenType == ScreenType::SETTINGS) {
                screen = new SettingsScreen();
            }
            else if (nextScreenType == ScreenType::GAME) {
                screen = new GameScreen();
            }
            else if (nextScreenType == ScreenType::LOADING) {
                screen = new LoadingScreen();
            }

            currentScreenType = nextScreenType;
        }

    }

    return EXIT_SUCCESS;
}

std::string getBaseDir(std::string exeFilePath) {
    int lastSlashIndex = 0;
    for (unsigned int i = 0; i < exeFilePath.length(); i++) {
        if (exeFilePath[i] == '\\' || exeFilePath[i] == '/') {
            lastSlashIndex = i;
        }
    }
    return exeFilePath.substr(0, lastSlashIndex + 1);
}

