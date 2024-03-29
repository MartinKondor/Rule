#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <SFML/Graphics.hpp>


enum class ScreenType
{
    EXIT,
    SETTINGS,
    LOADING,
    MAIN_MENU,
    CREDITS,
    GAME
};

class Screen
{
    /**
    Abstract screen object.
    */
public:

    /**
    Stores the next screen, what must be
    loaded when this screen is closing
    */
    Screen* nextScreen = nullptr;

    /**
    Must become true at the end of the constructor.
    */
    bool screenIsLoaded = false;


    /**
    Handle the polled window event.
    */
    virtual void event(sf::Event& event) = 0;

    /**
    Called for displaying and updating the given screen.
    */
    virtual ScreenType display(sf::RenderWindow& window) = 0;
};

#endif // SCREEN_HPP
