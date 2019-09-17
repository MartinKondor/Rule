#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <SFML/Graphics.hpp>


class Config {
    public:
        int WINDOW_WIDTH = 800;
        int WINDOW_HEIGHT = 600;
        bool IS_FULLSCREEN = false;
        int FPS_LIMIT = 60;
        sf::Keyboard::Key KEY_UP = sf::Keyboard::W;
        sf::Keyboard::Key KEY_DOWN = sf::Keyboard::S;
        sf::Keyboard::Key KEY_LEFT = sf::Keyboard::A;
        sf::Keyboard::Key KEY_RIGHT = sf::Keyboard::D;

        Config();
};

#endif // CONFIG_HPP
