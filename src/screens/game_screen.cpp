#include "game_screen.hpp"

#include <iostream>


extern Config CONFIG;
extern InputHolder INPUT;


GameScreen::GameScreen(irr::IrrlichtDevice* device, irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* driver)
    : Screen(device, smgr, driver)
{
    this->cam = smgr->addCameraSceneNode();
    this->cameraX = 0;
    this->cameraY = 0;
    this->cameraZ = 0;

    /// TEST
    mesh = this->smgr->getMesh((CONFIG.BASE_FOLDER + "gfx/map.obj").c_str());
    node = smgr->addAnimatedMeshSceneNode(mesh);
    /// END TEST
}

ScreenType GameScreen::display()
{
    this->cam->setPosition(irr::core::vector3df(this->cameraX, this->cameraY, this->cameraZ));
    // this->cam->setRotation(irr::core::vector3df(0, 100, 0));

    node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    node->setMD2Animation(irr::scene::EMAT_STAND);
    node->setMaterialTexture(0, this->driver->getTexture((CONFIG.BASE_FOLDER + "gfx/earth_test.png").c_str()));
    // node->setRotation(node->getPosition().rotationToDirection(irr::core::vector3df(INPUT.mouseInput.X, INPUT.mouseInput.Y * -1.0f, 0)));
    node->setRotation(node->getPosition().rotationToDirection(irr::core::vector3df(-45, 0, 0)));

    if (INPUT.keyState[irr::KEY_KEY_A])
    {
        this->cameraX -= 1;
    }
    if (INPUT.keyState[irr::KEY_KEY_D])
    {
        this->cameraX += 1;
    }

    // Scroll down and up
    if (INPUT.mouseInput.Wheel != 0)
    {
        this->cameraY += INPUT.mouseInput.Wheel;
        this->cameraZ += INPUT.mouseInput.Wheel / 2;
        INPUT.mouseInput.Wheel = 0;
    }

    if (INPUT.keyState[irr::KEY_KEY_S])
    {
        this->cameraZ -= 1;
    }
    if (INPUT.keyState[irr::KEY_KEY_W])
    {
        this->cameraZ += 1;
    }

    std::cout << "cameraX: " << this->cameraX << ", " << "cameraY: " << this->cameraY << ", " << "cameraZ: " << this->cameraZ << std::endl;

    return ScreenType::GAME;
}
