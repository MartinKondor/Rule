#ifndef SCREEN_HPP_INCLUDED
#define SCREEN_HPP_INCLUDED


#include <irrlicht.h>

enum ScreenType
{
    EXIT,
    MAIN_MENU,
    SETTINGS,
    GAME
};


class Screen
{
public:
    irr::gui::IGUIEnvironment* env;
    irr::IrrlichtDevice* device;
    irr::scene::ISceneManager* smgr;
    irr::video::IVideoDriver* driver;

    Screen(irr::IrrlichtDevice* device, irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* driver);
    virtual ScreenType display() = 0;
};

#endif // SCREEN_HPP_INCLUDED
