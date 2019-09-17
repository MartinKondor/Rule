#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <SFML/Graphics.hpp>
#include <enums.hpp>


class Screen {
    /**
    Abstract screen object.
    */
    public:
        virtual ScreenType display(sf::RenderWindow& window) = 0;
};

#endif // SCREEN_HPP
