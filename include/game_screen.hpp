#ifndef GAMESCREEN_HPP
#define GAMESCREEN_HPP

#include <SFML/Graphics.hpp>
#include <screen.hpp>
#include <button.hpp>


enum class GameSubScreen {
    IN_GAME,
    GAME
};


class GameScreen : public Screen {
    private:
        GameSubScreen subScreen;

    public:
        GameScreen();
        virtual ScreenType display(sf::RenderWindow& window);
};

#endif // GAMESCREEN_HPP
