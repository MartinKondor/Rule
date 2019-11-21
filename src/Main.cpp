#include <iostream>
#include <irrlicht.h>
#include "event_receiver.hpp"
#include "screen.hpp"
#include "main_menu_screen.hpp"
#include "game_screen.hpp"
#include "settings_screen.hpp"
#include "config.hpp"
#include "utils.hpp"


extern Config CONFIG;


int main(unsigned int argc, const char** argv)
{
    CONFIG.load(utils::getBaseDir(argv[0]), "config.ini");

    irr::IrrlichtDevice* device = irr::createDevice(
                    irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(CONFIG.WINDOW_WIDTH, CONFIG.WINDOW_HEIGHT),
                    32, CONFIG.IS_FULLSCREEN, false, CONFIG.VSYNC_ENABLED, 0);
    if (!device)
    {
        return EXIT_FAILURE;
    }

    // Setup window
    device->setWindowCaption(L"Rule");
    device->setResizable(false);
    irr::video::IVideoDriver* driver = device->getVideoDriver();
    irr::scene::ISceneManager* smgr = device->getSceneManager();

    // Screen variables
    ScreenType currentScreenType = ScreenType::MAIN_MENU;
    ScreenType lastScreenType = ScreenType::MAIN_MENU;
    Screen* currentScreen = new MainMenuScreen(device);

    // Background variables
    irr::video::SColor bgColor = irr::video::SColor(255, 119, 172, 242);
    bool incrementBlue = false;

    // Set event receiver
    SAppContext context;
    context.device = device;
    EventReceiver receiver(context);
    device->setEventReceiver(&receiver);

    irr::scene::ICameraSceneNode* cam = smgr->addCameraSceneNode();

    //// TEST
    const irr::scene::IGeometryCreator* geomentryCreator = smgr->getGeometryCreator();
    irr::scene::IMesh* plane = geomentryCreator->createPlaneMesh(irr::core::dimension2d<irr::f32>(100, 100), irr::core::dimension2d<irr::u32>(100, 100));
    irr::scene::ISceneNode* cube = smgr->addCubeSceneNode(20);
    irr::scene::ISceneNode* ground = smgr->addMeshSceneNode(plane);
    ground->setPosition(irr::core::vector3df(10, 0, 10));
    plane->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    smgr->addMeshSceneNode(plane);
    int camX = 0, camY = 50, camZ = 0;
    //// END TEST

    while (device->run())
    {
        if (currentScreenType != ScreenType::GAME)
        {
            bgColor.setBlue(bgColor.getBlue() + (incrementBlue ? 1 : -1));

            if (bgColor.getBlue() < 100)
            {
                incrementBlue = true;
            }
            else if (bgColor.getBlue() > 242)
            {
                incrementBlue = false;
            }

            driver->beginScene(true, true, bgColor);
        }
        else
        {
            driver->beginScene(true, true, irr::video::SColor(255, 0, 0, 0));
        }

        smgr->drawAll();

        //// TEST
        cube->render();
        cam->setPosition(irr::core::vector3df(camX, camY, camZ));
        cam->setTarget(ground->getPosition());

        if (CONFIG.keyState[irr::KEY_KEY_W])
        {
            camY++;
        }
        if (CONFIG.keyState[irr::KEY_KEY_S])
        {
            camY--;
        }

        if (CONFIG.keyState[irr::KEY_KEY_D])
        {
            camX++;
        }
        if (CONFIG.keyState[irr::KEY_KEY_A])
        {
            camX--;
        }

        if (CONFIG.keyState[irr::KEY_KEY_E])
        {
            camZ++;
        }
        if (CONFIG.keyState[irr::KEY_KEY_Q])
        {
            camZ--;
        }
        //// END TEST

        // currentScreenType = currentScreen->display();
        driver->endScene();

        // Choose screen
        if (lastScreenType != currentScreenType)
        {
            lastScreenType = currentScreenType;

            if (currentScreenType == ScreenType::EXIT)
            {
                break;
            }
            else if (currentScreenType == ScreenType::GAME)
            {
                currentScreen = new GameScreen(device);
            }
            else if (currentScreenType == ScreenType::SETTINGS)
            {
                currentScreen = new SettingsScreen(device);
            }
            else
            {
                currentScreen = new MainMenuScreen(device);
            }
        }

        if (!device->isWindowActive())
        {
            device->yield();
        }
    }

    device->drop();
    return EXIT_SUCCESS;
}
