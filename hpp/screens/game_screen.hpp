#ifndef GAME_SCREEN_HPP_INCLUDED
#define GAME_SCREEN_HPP_INCLUDED

#include <irrlicht.h>
#include "screen.hpp"
#include "config.hpp"
#include "input_holder.hpp"


class GameScreen : public Screen
{
public:

    // Camera variables
    irr::scene::ICameraSceneNode* cam;
    float cameraX;
    float cameraY;
    float cameraZ;

    /// TEST
    irr::scene::IAnimatedMesh* mesh;
    irr::scene::IAnimatedMeshSceneNode* node;
    /// END TEST

    GameScreen(irr::IrrlichtDevice* device, irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* driver);
    ScreenType display();
};

#endif // GAME_SCREEN_HPP_INCLUDED
