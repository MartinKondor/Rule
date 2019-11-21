#include "game_screen.hpp"

#include <iostream>


extern Config CONFIG;


GameScreen::GameScreen(irr::IrrlichtDevice* device)
{}

ScreenType GameScreen::display()
{
    return ScreenType::GAME;
}
