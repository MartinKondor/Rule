#include "screen.hpp"


Screen::Screen(irr::IrrlichtDevice* device, irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* driver)
{
    this->device = device;
    this->smgr = smgr;
    this->driver = driver;
}
