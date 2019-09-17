#ifndef GAMESCREEN_HPP
#define GAMESCREEN_HPP

#include <enums.hpp>
#include <screen.hpp>
#include <button.hpp>


class GameScreen : public Screen {
    public:
        GameScreen();
        virtual ScreenType display(sf::RenderWindow&);
};

#endif // GAMESCREEN_HPP
