#ifndef SETTINGS_SCREEN_HPP_INCLUDED
#define SETTINGS_SCREEN_HPP_INCLUDED

#include <irrlicht.h>
#include "screen.hpp"
#include "config.hpp"


class SettingsScreen : public Screen
{
public:
    SettingsScreen(irr::IrrlichtDevice* device, irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* driver);
    ScreenType display();
};


#endif // SETTINGS_SCREEN_HPP_INCLUDED
