#include <iostream>
#include <irrlicht.h>
#include "Config.hpp"
#include "Utils.hpp"


extern Config CONFIG;


int main(unsigned int argc, const char** argv)
{
    CONFIG.load(utils::getBaseDir(argv[0]), "config.ini");

    irr::IrrlichtDevice* device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(CONFIG.WINDOW_WIDTH, CONFIG.WINDOW_HEIGHT), 16, false, false, true, 0);
    if (!device)
    {
        return EXIT_FAILURE;
    }

    // Setup window
    device->setWindowCaption(L"Rule");
    device->setResizable(false);
    irr::video::IVideoDriver* driver = device->getVideoDriver();
    irr::scene::ISceneManager* smgr = device->getSceneManager();
    irr::gui::IGUIEnvironment* guienv = device->getGUIEnvironment();

    // Load and set fonts
    irr::gui::IGUIFont* basicFont = guienv->getFont("bin/fonts/basic.bmp");
    irr::gui::IGUISkin* skin = guienv->createSkin(irr::gui::EGUI_SKIN_TYPE::EGST_BURNING_SKIN);
    skin->setFont(basicFont);
    guienv->setSkin(skin);

    // Main menu elements
    irr::gui::IGUIButton* newGameButton = guienv->addButton(irr::core::rect<irr::s32>(CONFIG.WINDOW_WIDTH / 2, 50, 100, 100), 0, -1, L"New Game");
    irr::gui::IGUIButton* exitButton = guienv->addButton(irr::core::rect<irr::s32>(CONFIG.WINDOW_WIDTH / 2, 50, 250, 100), 0, -1, L"Exit");

    while (device->run())
    {
        driver->beginScene(true, true, irr::video::SColor(255, 20, 20, 20));
        smgr->drawAll();
        guienv->drawAll();

        // Drawing
        if (newGameButton->isPressed())
        {
            std::cout << "New Game" << std::endl;
        }
        else if (exitButton->isPressed())
        {
            std::cout << "Exit" << std::endl;
        }

        driver->endScene();

        if (!device->isWindowActive())
        {
            device->yield();
        }
    }

    device->drop();
    return EXIT_SUCCESS;
}
