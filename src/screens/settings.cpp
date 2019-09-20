#include "screens/settings.hpp"


const unsigned int KEY_COUNT = 101;
std::string KEY_LABELS[KEY_COUNT] =
{
    "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W",
    "X","Y","Z","0","1","2","3","4","5","6","7","8","9","Escape","Left Control","Left Shift",
    "Left Alt","Left System","Right Control","Right Shift","Right Alt","Right System","Menu",
    "Left Bracket","Right Bracket","Semicolon","Comma","Period","Quote","Slash","Backslash",
    "Tilde","Equal","Hyphen","Space","Enter","Backspace","Tab","PageUp","PageDown","End",
    "Home","Insert","Delete","Add","Subtract","Multiply","Divide","Left arrow","Right arrow",
    "Up arrow","Down arrow","Numpad 0","Numpad 1","Numpad 2","Numpad 3","Numpad 4","Numpad 5",
    "Numpad 6","Numpad 7","Numpad 8","Numpad 9","F1","F2","F3","F4","F5","F6","F7","F8","F9",
    "F10","F11","F12","F13","F14","F15","Pause"
};


SettingsScreen::SettingsScreen(Screen* nextScreen)
{
    this->nextScreen = nextScreen;

    sf::Image logoImage;
    logoImage.loadFromFile(IMAGE_FOLDER + "logo.png");
    this->logoTexture.loadFromImage(logoImage);
    this->logo.setTexture(this->logoTexture);
    this->logo.setPosition(CONFIG.WINDOW_WIDTH - logoImage.getSize().x, 0);

    // Texts
    this->screenTitle = sf::Text("Settings", CONFIG.TITLE_FONT, CONFIG.TITLE_CHARACTER_SIZE);
    this->controlsTitle = sf::Text("CONTROLS", CONFIG.MAIN_FONT, CONFIG.CHARACTER_SIZE);
    this->videoTitle = sf::Text("VIDEO", CONFIG.MAIN_FONT, CONFIG.CHARACTER_SIZE);
    this->upKeyLabel = sf::Text("Up key", CONFIG.MAIN_FONT, CONFIG.CHARACTER_SIZE);
    this->downKeyLabel = sf::Text("Down key", CONFIG.MAIN_FONT, CONFIG.CHARACTER_SIZE);
    this->leftKeyLabel = sf::Text("Left key", CONFIG.MAIN_FONT, CONFIG.CHARACTER_SIZE);
    this->rightKeyLabel = sf::Text("Right key", CONFIG.MAIN_FONT, CONFIG.CHARACTER_SIZE);
    this->volumeTitle = sf::Text("VOLUME", CONFIG.MAIN_FONT, CONFIG.CHARACTER_SIZE);
    this->masterVolumeLabel = sf::Text("MASTER", CONFIG.MAIN_FONT, CONFIG.CHARACTER_SIZE);
    this->soundVolumeLabel = sf::Text("SOUND", CONFIG.MAIN_FONT, CONFIG.CHARACTER_SIZE);
    this->musicVolumeLabel = sf::Text("MUSIC", CONFIG.MAIN_FONT, CONFIG.CHARACTER_SIZE);

    int thirdX = this->controlsTitle.getString().getSize() * CONFIG.CHARACTER_SIZE;
    int commonX = thirdX / 2;
    int sliderCommonX = CONFIG.WINDOW_WIDTH - 2.5 * thirdX;

    this->backButton = Button(2 * CONFIG.CHARACTER_SIZE, CONFIG.WINDOW_HEIGHT - 3.5 * CONFIG.CHARACTER_SIZE, "BACK");
    this->fullscreenCheckbox = Checkbox(0, 0, "Full screen");
    this->upButton = Button(3.5 * commonX, 11 * CONFIG.CHARACTER_SIZE, KEY_LABELS[CONFIG.KEY_UP]);
    this->downButton = Button(3.5 * commonX, 14 * CONFIG.CHARACTER_SIZE, KEY_LABELS[CONFIG.KEY_DOWN]);
    this->leftButton = Button(3.5 * commonX, 17 * CONFIG.CHARACTER_SIZE, KEY_LABELS[CONFIG.KEY_LEFT]);
    this->rightButton = Button(3.5 * commonX, 20 * CONFIG.CHARACTER_SIZE, KEY_LABELS[CONFIG.KEY_RIGHT]);
    this->fullscreenCheckbox = Checkbox(commonX, 29 * CONFIG.CHARACTER_SIZE, "Full screen");
    this->masterVolumeSlider = Slider(CONFIG.WINDOW_WIDTH - sliderCommonX / 2, 29 * CONFIG.CHARACTER_SIZE + 0.85 * CONFIG.CHARACTER_SIZE, 0, 100);
    this->soundVolumeSlider = Slider(CONFIG.WINDOW_WIDTH - sliderCommonX / 2, 32 * CONFIG.CHARACTER_SIZE + 0.85 * CONFIG.CHARACTER_SIZE, 0, 100);
    this->musicVolumeSlider = Slider(CONFIG.WINDOW_WIDTH - sliderCommonX / 2, 35 * CONFIG.CHARACTER_SIZE + 0.85 * CONFIG.CHARACTER_SIZE, 0, 100);

    this->controlsTitle.setStyle(sf::Text::Bold);
    this->volumeTitle.setStyle(sf::Text::Bold);
    this->videoTitle.setStyle(sf::Text::Bold);

    this->screenTitle.setPosition(2 * CONFIG.CHARACTER_SIZE, 2 * CONFIG.CHARACTER_SIZE);
    this->controlsTitle.setPosition(thirdX, 7 * CONFIG.CHARACTER_SIZE);
    this->upKeyLabel.setPosition(commonX, 11 * CONFIG.CHARACTER_SIZE + CONFIG.CHARACTER_SIZE / 2);
    this->downKeyLabel.setPosition(commonX, 14 * CONFIG.CHARACTER_SIZE + CONFIG.CHARACTER_SIZE / 2);
    this->leftKeyLabel.setPosition(commonX, 17 * CONFIG.CHARACTER_SIZE + CONFIG.CHARACTER_SIZE / 2);
    this->rightKeyLabel.setPosition(commonX, 20 * CONFIG.CHARACTER_SIZE + CONFIG.CHARACTER_SIZE / 2);
    this->videoTitle.setPosition(thirdX, 26 * CONFIG.CHARACTER_SIZE);
    this->volumeTitle.setPosition(CONFIG.WINDOW_WIDTH - 1.5 * thirdX, 26 * CONFIG.CHARACTER_SIZE);
    this->masterVolumeLabel.setPosition(sliderCommonX - 2 * CONFIG.CHARACTER_SIZE, 29 * CONFIG.CHARACTER_SIZE);
    this->soundVolumeLabel.setPosition(sliderCommonX - 2 * CONFIG.CHARACTER_SIZE, 32 * CONFIG.CHARACTER_SIZE);
    this->musicVolumeLabel.setPosition(sliderCommonX - 2 * CONFIG.CHARACTER_SIZE, 35 * CONFIG.CHARACTER_SIZE);

    this->fullscreenCheckbox.isChecked = CONFIG.IS_FULLSCREEN;
    this->masterVolumeSlider.setSliderValue(CONFIG.MASTER_VOLUME);
    this->soundVolumeSlider.setSliderValue(CONFIG.SOUND_VOLUME);
    this->musicVolumeSlider.setSliderValue(CONFIG.MUSIC_VOLUME);

    this->screenIsLoaded = true;
}

ScreenType SettingsScreen::display(sf::RenderWindow &window)
{
    window.draw(this->logo);
    this->backButton.display(window);
    this->upButton.display(window);
    this->downButton.display(window);
    this->leftButton.display(window);
    this->rightButton.display(window);
    window.draw(this->screenTitle);
    window.draw(this->videoTitle);
    window.draw(this->controlsTitle);
    window.draw(this->upKeyLabel);
    window.draw(this->downKeyLabel);
    window.draw(this->leftKeyLabel);
    window.draw(this->rightKeyLabel);
    window.draw(this->volumeTitle);
    window.draw(this->masterVolumeLabel);
    window.draw(this->soundVolumeLabel);
    window.draw(this->musicVolumeLabel);
    this->masterVolumeSlider.display(window);
    this->soundVolumeSlider.display(window);
    this->musicVolumeSlider.display(window);
    this->fullscreenCheckbox.display(window);

    // Handle buttons
    if (this->backButton.state == ButtonState::RELEASED)
    {
        CONFIG.save(BASE_FOLDER + "config.ini");
        return ScreenType::MAIN_MENU;
    }
    else if (this->upButton.state == ButtonState::RELEASED && !this->waitingForKey)
    {
        this->waitingForKey = true;
        this->upButton.label.setString("...");
        this->upButton.display(window);
        window.display();
        CONFIG.KEY_UP = this->getPressedKey(CONFIG.KEY_UP);
        this->upButton.label.setString(KEY_LABELS[CONFIG.KEY_UP]);
    }
    else if (this->downButton.state == ButtonState::RELEASED && !this->waitingForKey)
    {
        this->waitingForKey = true;
        this->downButton.label.setString("...");
        this->downButton.display(window);
        window.display();
        CONFIG.KEY_DOWN = this->getPressedKey(CONFIG.KEY_DOWN);
        this->downButton.label.setString(KEY_LABELS[CONFIG.KEY_DOWN]);
    }
    else if (this->leftButton.state == ButtonState::RELEASED && !this->waitingForKey)
    {
        this->waitingForKey = true;
        this->leftButton.label.setString("...");
        this->leftButton.display(window);
        window.display();
        CONFIG.KEY_LEFT = this->getPressedKey(CONFIG.KEY_LEFT);
        this->leftButton.label.setString(KEY_LABELS[CONFIG.KEY_LEFT]);
    }
    else if (this->rightButton.state == ButtonState::RELEASED && !this->waitingForKey)
    {
        this->waitingForKey = true;
        this->rightButton.label.setString("...");
        this->rightButton.display(window);
        window.display();
        CONFIG.KEY_RIGHT = this->getPressedKey(CONFIG.KEY_RIGHT);
        this->rightButton.label.setString(KEY_LABELS[CONFIG.KEY_RIGHT]);
    }

    // Update config
    CONFIG.MASTER_VOLUME = this->masterVolumeSlider.sliderValue;
    CONFIG.SOUND_VOLUME = this->soundVolumeSlider.sliderValue;
    CONFIG.MUSIC_VOLUME = this->musicVolumeSlider.sliderValue;
    CONFIG.IS_FULLSCREEN = this->fullscreenCheckbox.isChecked;
    return ScreenType::SETTINGS;
}

void SettingsScreen::event(sf::Event& event) {}

sf::Keyboard::Key SettingsScreen::getPressedKey(sf::Keyboard::Key currentKey)
{
    while (this->waitingForKey)
    {
        for (unsigned int i = 0; i < KEY_COUNT; i++)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                this->waitingForKey = false;
                return currentKey;
            }
            else if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key) i))
            {
                this->waitingForKey = false;
                return (sf::Keyboard::Key) i;
            }
        }
    }
    this->waitingForKey = false;
    return currentKey;
}
