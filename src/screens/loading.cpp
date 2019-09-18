#include "screens/loading.hpp"


LoadingScreen::LoadingScreen()
{
    sf::Image logoImage;
    sf::Image sfmlLogoImage;

    logoImage.loadFromFile(IMAGE_FOLDER + "logo.png");
    this->logoTexture.loadFromImage(logoImage);
    sfmlLogoImage.loadFromFile(IMAGE_FOLDER + "sfml_logo.png");
    this->sfmlLogoTexture.loadFromImage(sfmlLogoImage);

    this->logo.setTexture(this->logoTexture);
    this->logo.setPosition((int) (CONFIG.WINDOW_WIDTH / 2) - this->logoTexture.getSize().x / 2, (int) (CONFIG.WINDOW_HEIGHT / 2) - this->logoTexture.getSize().y / 2);

    this->sfmlLogo.setTexture(this->sfmlLogoTexture);
    this->sfmlLogo.setScale(0.15, 0.15);
    this->sfmlLogo.setPosition(25, CONFIG.WINDOW_HEIGHT - 75);

    this->screenTitle = sf::Text("Loading ...", CONFIG.TITLE_FONT, CONFIG.TITLE_CHARACTER_SIZE);
    this->screenTitle.setPosition(2 * CONFIG.CHARACTER_SIZE, 2 * CONFIG.CHARACTER_SIZE);
}

ScreenType LoadingScreen::display(sf::RenderWindow &window)
{
    window.draw(this->screenTitle);
    window.draw(this->logo);
    window.draw(this->sfmlLogo);
    window.display();

    // sf::sleep(sf::seconds(2));

    return ScreenType::MAIN_MENU;
}
