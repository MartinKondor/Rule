#ifndef GAME_SCREEN_HPP_INCLUDED
#define GAME_SCREEN_HPP_INCLUDED

#include <irrlicht.h>
#include "screen.hpp"
#include "config.hpp"


class GameScreen : public Screen
{
public:
    GameScreen(irr::IrrlichtDevice* device);
    ScreenType display();
};

#endif // GAME_SCREEN_HPP_INCLUDED
