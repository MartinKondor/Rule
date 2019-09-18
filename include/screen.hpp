#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <SFML/Graphics.hpp>


enum class ScreenType {
    EXIT,
    SETTINGS,
    LOADING,
    MAIN_MENU,
    CREDITS,
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
