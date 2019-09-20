#ifndef CREDITS_SCREEN_HPP
#define CREDITS_SCREEN_HPP

#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "screen.hpp"
#include "gui/button.hpp"

extern Config CONFIG;
extern std::string IMAGE_FOLDER;


class CreditsScreen : public Screen
{
    /**
    Credits.
    */
private:
    sf::Text screenTitle;
    sf::Text credits;
    sf::Texture logoTexture;
    sf::Sprite logo;
    sf::Texture sfmlLogoTexture;
    sf::Sprite sfmlLogo;
    Button backButton;

public:
    CreditsScreen();
    virtual void event(sf::Event& event);
    virtual ScreenType display(sf::RenderWindow& window);
};

#endif // CREDITS_SCREEN_HPP
