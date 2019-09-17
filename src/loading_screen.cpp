#include <loading_screen.hpp>


LoadingScreen::LoadingScreen() {

}

ScreenType LoadingScreen::display(sf::RenderWindow &window) {
    return ScreenType::MAIN_MENU;
}
