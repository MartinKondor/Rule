#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <utils.hpp>


class Config {
    public:
        unsigned int WINDOW_WIDTH = 800;
        unsigned int WINDOW_HEIGHT = 600;
        unsigned int FPS_LIMIT = 60;
        unsigned int CHARACTER_SIZE = 15;
        unsigned int MASTER_VOLUME = 100;
        unsigned int SOUND_VOLUME = 100;
        unsigned int MUSIC_VOLUME = 100;
        bool IS_FULLSCREEN = false;
        sf::Keyboard::Key KEY_UP = sf::Keyboard::W;
        sf::Keyboard::Key KEY_DOWN = sf::Keyboard::S;
        sf::Keyboard::Key KEY_LEFT = sf::Keyboard::A;
        sf::Keyboard::Key KEY_RIGHT = sf::Keyboard::D;
        sf::Font MAIN_FONT;

        Config();

        /**
        @returns true if loading was successful.
        */
        bool load(std::string fileName);
        void save(std::string fileName);

    private:

        /**
        Setting the "config" class variable "key" to the given "value"
        */
        void parseConfigKey(std::string key, std::string value);
};

#endif // CONFIG_HPP
