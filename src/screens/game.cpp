#include "screens/game.hpp"


GameScreen::GameScreen() {
    this->subScreen = GameSubScreen::GAME;
}

ScreenType GameScreen::display(sf::RenderWindow&) {
    return ScreenType::GAME;
}
