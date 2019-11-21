#ifndef MAIN_MENU_SCREEN_HPP_INCLUDE
#define MAIN_MENU_SCREEN_HPP_INCLUDE

#include <irrlicht.h>
#include "screen.hpp"
#include "config.hpp"


class MainMenuScreen : public Screen
{
public:
    irr::gui::IGUIButton* newGameButton;
    irr::gui::IGUIButton* settingsButton;
    irr::gui::IGUIButton* exitButton;

    MainMenuScreen(irr::IrrlichtDevice* device);
    ScreenType display();
};

#endif // MAIN_MENU_SCREEN_HPP_INCLUDE
