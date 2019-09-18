#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <SFML/Graphics.hpp>


enum class ScreenType {
    LOADING,
    MAIN_MENU,
    SETTINGS,
    GAME
};

class Screen {
    /**
    Abstract screen object.
    */
    public:
        virtual ScreenType display(sf::RenderWindow& window) = 0;
};

#endif // SCREEN_HPP
