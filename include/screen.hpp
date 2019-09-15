#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <SFML/Graphics.hpp>
#include "../include/enums.hpp"
#include "../include/button.hpp"


class Screen {
    /**
    Abstract screen object.
    */
    public:
        virtual ScreenType display(sf::RenderWindow&) = 0;
};

#endif // SCREEN_HPP
