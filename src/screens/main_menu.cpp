#include "screens/main_menu.hpp"


MainMenuScreen::MainMenuScreen()
{
    int buttonMargin = 45;
    int commonX = 50;
    int commonY = 29;

    this->newGameButton = Button(commonX, CONFIG.WINDOW_HEIGHT - 5 * buttonMargin - commonY, "NEW GAME", 157, 0);
    this->loadSaveGameButton = Button(commonX, CONFIG.WINDOW_HEIGHT - 4 * buttonMargin - commonY, "LOAD GAME", 157, 0);
    this->settingsButton = Button(commonX, CONFIG.WINDOW_HEIGHT - 3 * buttonMargin - commonY, "SETTINGS", 157, 0);
    this->creditsButton = Button(commonX, CONFIG.WINDOW_HEIGHT - 2 * buttonMargin - commonY, "CREDITS", 157, 0);
    this->exitButton = Button(commonX, CONFIG.WINDOW_HEIGHT - buttonMargin - commonY, "EXIT", 157, 0);
    this->subScreenBackButton = Button(2 * CONFIG.CHARACTER_SIZE, CONFIG.WINDOW_HEIGHT - 3.5 * CONFIG.CHARACTER_SIZE, "BACK");

    // Load logo
    sf::Image logoImage;
    logoImage.loadFromFile(IMAGE_FOLDER + "logo.png");
    this->logoTexture.loadFromImage(logoImage);
    this->logo.setTexture(logoTexture);
    this->logo.setPosition(CONFIG.WINDOW_WIDTH - logoImage.getSize().x, 0);

    this->subScreen = MainMenuSubScreen::NONE;
    this->newGameSubScreenTitle = sf::Text("New game", CONFIG.TITLE_FONT, CONFIG.TITLE_CHARACTER_SIZE);
    this->loadGameSubScreenTitle = sf::Text("Load game", CONFIG.TITLE_FONT, CONFIG.TITLE_CHARACTER_SIZE);
    this->newGameSubScreenTitle.setPosition(2 * CONFIG.CHARACTER_SIZE, 2 * CONFIG.CHARACTER_SIZE);
    this->loadGameSubScreenTitle.setPosition(2 * CONFIG.CHARACTER_SIZE, 2 * CONFIG.CHARACTER_SIZE);
}

ScreenType MainMenuScreen::displaySubScreen(sf::RenderWindow &window)
{
    if (this->subScreen == MainMenuSubScreen::NEW_GAME)
    {
        window.draw(this->newGameSubScreenTitle);
    }
    else if (this->subScreen == MainMenuSubScreen::LOAD_GAME)
    {
        window.draw(this->loadGameSubScreenTitle);
    }

    window.draw(this->logo);
    this->subScreenBackButton.display(window);

    if (this->subScreenBackButton.state == ButtonState::RELEASED)
    {
        this->subScreen = MainMenuSubScreen::NONE;
    }
    return ScreenType::MAIN_MENU;
}

ScreenType MainMenuScreen::display(sf::RenderWindow &window)
{
    if (this->subScreen != MainMenuSubScreen::NONE)
    {
        return this->displaySubScreen(window);
    }

    this->newGameButton.display(window);
    this->loadSaveGameButton.display(window);
    this->settingsButton.display(window);
    this->creditsButton.display(window);
    this->exitButton.display(window);
    window.draw(this->logo);

    if (this->exitButton.state == ButtonState::RELEASED)
    {
        return ScreenType::EXIT;
    }
    else if (this->newGameButton.state == ButtonState::RELEASED)
    {
        // Open the game imediatly for testing
        // this->subScreen = MainMenuSubScreen::NEW_GAME;
        // return ScreenType::MAIN_MENU;
        return ScreenType::GAME;
    }
    else if (this->loadSaveGameButton.state == ButtonState::RELEASED)
    {
        this->subScreen = MainMenuSubScreen::LOAD_GAME;
        return ScreenType::MAIN_MENU;
    }
    else if (this->settingsButton.state == ButtonState::RELEASED)
    {
        return ScreenType::SETTINGS;
    }
    else if (this->creditsButton.state == ButtonState::RELEASED)
    {
        return ScreenType::CREDITS;
    }

    return ScreenType::MAIN_MENU;
}
