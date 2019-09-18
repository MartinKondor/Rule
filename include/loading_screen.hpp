#ifndef LOADING_SCREEN_HPP
#define LOADING_SCREEN_HPP

#include <SFML/Graphics.hpp>
#include <screen.hpp>


class LoadingScreen : public Screen {
    public:
        LoadingScreen();
        virtual ScreenType display(sf::RenderWindow& window);
};

#endif // LOADING_SCREEN_HPP
