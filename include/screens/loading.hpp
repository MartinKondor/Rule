#ifndef LOADING_SCREEN_HPP
#define LOADING_SCREEN_HPP

#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "screen.hpp"

extern Config CONFIG;
extern std::string IMAGE_FOLDER;


class LoadingScreen : public Screen {
    /**
    The first screen what the user see.
    */
    private:
        sf::Text screenTitle;
        sf::Texture logoTexture;
        sf::Texture sfmlLogoTexture;
        sf::Sprite logo;
        sf::Sprite sfmlLogo;

    public:
        LoadingScreen();
        virtual ScreenType display(sf::RenderWindow& window);
};

#endif // LOADING_SCREEN_HPP
