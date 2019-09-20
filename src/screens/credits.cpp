#include "screens/credits.hpp"


CreditsScreen::CreditsScreen()
{
    this->backButton = Button(2 * CONFIG.CHARACTER_SIZE, CONFIG.WINDOW_HEIGHT - 3.5 * CONFIG.CHARACTER_SIZE, "BACK");

    sf::Image logoImage;
    sf::Image sfmlLogoImage;

    logoImage.loadFromFile(IMAGE_FOLDER + "logo.png");
    sfmlLogoImage.loadFromFile(IMAGE_FOLDER + "sfml_logo.png");
    this->logoTexture.loadFromImage(logoImage);
    this->sfmlLogoTexture.loadFromImage(sfmlLogoImage);

    this->logo.setTexture(this->logoTexture);
    this->sfmlLogo.setTexture(this->sfmlLogoTexture);
    this->screenTitle = sf::Text("Credits", CONFIG.TITLE_FONT, CONFIG.TITLE_CHARACTER_SIZE);
    this->credits = sf::Text("...", CONFIG.MAIN_FONT, CONFIG.CHARACTER_SIZE);

    this->sfmlLogo.setScale(0.15, 0.15);
    this->sfmlLogo.setPosition(CONFIG.WINDOW_WIDTH / 2 - 0.15 * this->sfmlLogoTexture.getSize().x / 2, CONFIG.WINDOW_HEIGHT - 0.25 * this->sfmlLogoTexture.getSize().y);
    this->logo.setPosition(CONFIG.WINDOW_WIDTH - logoImage.getSize().x, 0);
    this->screenTitle.setPosition(2 * CONFIG.CHARACTER_SIZE, 2 * CONFIG.CHARACTER_SIZE);
    this->credits.setPosition(CONFIG.WINDOW_WIDTH / 2, 2.2 * this->logoTexture.getSize().y);

    this->screenIsLoaded = true;
}

void CreditsScreen::event(sf::Event& event) {}

ScreenType CreditsScreen::display(sf::RenderWindow& window)
{
    window.draw(screenTitle);
    window.draw(credits);
    window.draw(logo);
    window.draw(sfmlLogo);
    this->backButton.display(window);

    if (this->backButton.state == ButtonState::RELEASED)
    {
        return ScreenType::MAIN_MENU;
    }
    return ScreenType::CREDITS;
}
