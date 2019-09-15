#include <iostream>
#include <SFML/Graphics.hpp>

#include "../include/consts.hpp"
#include "../include/main_menu_screen.hpp"



int main(const int argc, const char** argv) {
    sf::Event windowEvent;
    sf::RenderWindow window(sf::VideoMode(CONFIG.WINDOW_WIDTH, CONFIG.WINDOW_HEIGHT), WINDOW_TITLE, CONFIG.IS_FULLSCREEN ? sf::Style::Fullscreen : sf::Style::Close);
    window.setFramerateLimit(CONFIG.FPS_LIMIT);
    window.resetGLStates();

    Screen* screen = new MainMenuScreen();

    while (window.isOpen()) {
        while (window.pollEvent(windowEvent)) {
            if (windowEvent.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        screen->display(window);
        window.display();
    }

    return EXIT_SUCCESS;
}
