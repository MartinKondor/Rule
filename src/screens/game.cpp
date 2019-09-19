#include "screens/game.hpp"


GameScreen::GameScreen()
{
    this->game = GamePlay(true);
    this->subScreen = GameSubScreen::GAME;

    // Load logo
    sf::Image logoImage;
    logoImage.loadFromFile(IMAGE_FOLDER + "logo.png");
    this->logoTexture.loadFromImage(logoImage);
    this->logo.setTexture(logoTexture);
    this->logo.setPosition(CONFIG.WINDOW_WIDTH - logoImage.getSize().x, 0);

    // In game menu elements
    unsigned int buttonMargin = 42;
    unsigned int commonWidth = 9 * CONFIG.CHARACTER_SIZE;
    unsigned int commonY = CONFIG.WINDOW_HEIGHT / 4;

    this->inGameResumeButton = Button(CONFIG.WINDOW_WIDTH / 2 - commonWidth / 2, commonY + buttonMargin, "Resume", commonWidth, 0);
    this->inGameSaveGameButton = Button(CONFIG.WINDOW_WIDTH / 2 - commonWidth / 2, commonY + 2 * buttonMargin, "Save game", commonWidth, 0);
    this->inGameResignButton = Button(CONFIG.WINDOW_WIDTH / 2 - commonWidth / 2, commonY + 3 * buttonMargin, "Resign", commonWidth, 0);
    this->inGameSettingsButton = Button(CONFIG.WINDOW_WIDTH / 2 - commonWidth / 2, commonY + 4 * buttonMargin, "Settings", commonWidth, 0);
    this->inGameExitButton = Button(CONFIG.WINDOW_WIDTH / 2 - commonWidth / 2, commonY + 5 * buttonMargin, "Exit", commonWidth, 0);
}

ScreenType GameScreen::displayInGameMenu(sf::RenderWindow& window)
{
    window.draw(this->inGameMenuBackground);
    window.draw(this->logo);
    this->inGameResumeButton.display(window);
    this->inGameSaveGameButton.display(window);
    this->inGameResignButton.display(window);
    this->inGameSettingsButton.display(window);
    this->inGameExitButton.display(window);

    if (this->inGameExitButton.state == ButtonState::RELEASED)
    {
        return ScreenType::MAIN_MENU;
    }
    else if (this->inGameSaveGameButton.state == ButtonState::RELEASED)
    {
        log("Save button pressed");
    }
    else if (this->inGameResignButton.state == ButtonState::RELEASED)
    {
        log("Resign button pressed");
    }
    else if (this->inGameSettingsButton.state == ButtonState::RELEASED)
    {
        this->subScreen = GameSubScreen::IN_GAME;
        return ScreenType::SETTINGS;
    }
    else if (this->inGameResumeButton.state == ButtonState::RELEASED)
    {
        this->subScreen = GameSubScreen::GAME;
        return ScreenType::GAME;
    }
    return ScreenType::GAME;
}

ScreenType GameScreen::display(sf::RenderWindow& window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        // Make a screenshot of the game as a wallpaper
        this->game.display(window);
        sf::Vector2u windowSize = window.getSize();
        sf::Texture* tempTexture = new sf::Texture();
        tempTexture->create(windowSize.x, windowSize.y);
        tempTexture->update(window);
        this->inGameMenuBackground.setTexture(*tempTexture);
        this->inGameMenuBackground.setColor(sf::Color(127, 127, 127, 255));

        window.setView(window.getDefaultView());
        this->subScreen = GameSubScreen::IN_GAME;
        return this->displayInGameMenu(window);
    }
    else if (this->subScreen == GameSubScreen::IN_GAME)
    {
        return this->displayInGameMenu(window);
    }

    this->game.display(window);
    return ScreenType::GAME;
}
