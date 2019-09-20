#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "screen.hpp"
#include "screens/credits.hpp"
#include "screens/loading.hpp"
#include "screens/settings.hpp"
#include "screens/main_menu.hpp"
#include "screens/game.hpp"
#include "log.hpp"


#define WINDOW_TITLE "Rule"
extern Config CONFIG;
extern std::string BASE_FOLDER;
extern std::string IMAGE_FOLDER;
extern std::string ANIMATION_FOLDER;
extern std::string TILESET_FOLDER;
extern std::string RESOURCES_FOLDER;


class Flag
{
    /**
    Displays the game's flag.
    */
private:
    sf::Texture flagTexture;
    sf::Sprite flag;
    sf::Vector2u flagImgSize;

    sf::Texture darkWaveTexture;
    sf::Texture lightWaveTexture;
    std::vector<sf::Sprite> darkWaves;
    std::vector<sf::Sprite> lightWaves;
    std::vector<unsigned int> darkWaveXs;
    std::vector<unsigned int> lightWaveXs;

public:
    Flag(unsigned int waveCount);
    void display(sf::RenderWindow &window);
};

Flag::Flag(unsigned int waveCount)
{
    sf::Image flagImg;
    sf::Image lightWaveImg;
    sf::Image darkWaveImg;

    if (!flagImg.loadFromFile(IMAGE_FOLDER + "flag/flag.png"))
    {
        openMessageBox("Cannot load flag file.");
        exit(EXIT_FAILURE);
    }
    if (!lightWaveImg.loadFromFile(IMAGE_FOLDER + "flag/light_wave.png"))
    {
        openMessageBox("Cannot load light_wave file.");
        exit(EXIT_FAILURE);
    }
    if (!darkWaveImg.loadFromFile(IMAGE_FOLDER + "flag/dark_wave.png"))
    {
        openMessageBox("Cannot load dark_wave file.");
        exit(EXIT_FAILURE);
    }

    this->flagImgSize = flagImg.getSize();
    this->darkWaveTexture = sf::Texture();
    this->lightWaveTexture = sf::Texture();
    this->darkWaveTexture.loadFromImage(darkWaveImg);
    this->lightWaveTexture.loadFromImage(lightWaveImg);

    unsigned int prevXd = darkWaveImg.getSize().x - darkWaveImg.getSize().x / 4;
    unsigned int prevXl = 0;

    for (unsigned int i = 0; i < waveCount; i++)
    {
        this->darkWaves.push_back(sf::Sprite());
        this->lightWaves.push_back(sf::Sprite());
        this->darkWaveXs.push_back(prevXd);
        this->lightWaveXs.push_back(prevXl);

        prevXl += 2 * prevXd;
        prevXd *= 2;

        this->darkWaves[i].setTexture(this->darkWaveTexture);
        this->lightWaves[i].setTexture(this->lightWaveTexture);
    }

    this->flagTexture.loadFromImage(flagImg);
    this->flag.setTexture(this->flagTexture);
    this->flag.setScale((double) CONFIG.WINDOW_WIDTH / this->flagImgSize.x, (double) CONFIG.WINDOW_HEIGHT / this->flagImgSize.y);
}

void Flag::display(sf::RenderWindow &window)
{
    window.draw(this->flag);

    for (unsigned int i = 0; i < this->darkWaves.size(); i++)
    {
        window.draw(this->darkWaves[i]);
        this->darkWaves[i].setPosition(this->darkWaveXs[i], 0);
        this->darkWaveXs[i] += 2;
    }

    for (unsigned int i = 0; i < this->lightWaves.size(); i++)
    {
        window.draw(this->lightWaves[i]);
        this->lightWaves[i].setPosition(this->lightWaveXs[i], 0);
        this->lightWaveXs[i] += 2;
    }
}


int main(const int argc, const char** argv)
{

    // Define global variables
    BASE_FOLDER = Utils::getBaseDir(argv[0]);
    IMAGE_FOLDER = BASE_FOLDER + "images/";
    ANIMATION_FOLDER = BASE_FOLDER + "gfx/animations/";
    TILESET_FOLDER = BASE_FOLDER + "tilesets/";
    MAP_FOLDER = BASE_FOLDER + "maps/";
    RESOURCES_FOLDER = MAP_FOLDER + "resources/";

    if (!CONFIG.load(BASE_FOLDER + "config.ini"))
    {
        std::cout << "Cannot load config." << std::endl;
        return EXIT_FAILURE;
    }

    // Initialize window
    sf::Event windowEvent;
    sf::RenderWindow window(sf::VideoMode(CONFIG.WINDOW_WIDTH, CONFIG.WINDOW_HEIGHT), WINDOW_TITLE, CONFIG.IS_FULLSCREEN ? sf::Style::Fullscreen : sf::Style::Close);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(CONFIG.FPS_LIMIT);
    window.requestFocus();
    window.resetGLStates();

    // Variables for screen changes
    LoadingScreen* loadingScreen = new LoadingScreen();
    Screen* screen = loadingScreen;
    ScreenType nextScreenType = ScreenType::LOADING;
    ScreenType currentScreenType = ScreenType::LOADING;
    sf::Color gameBgColor(0, 0, 0);

    // Load flag background
    Flag flag(2);

    // Main loop
    while (window.isOpen())
    {
        // Handle events
        while (window.pollEvent(windowEvent))
        {
            if (windowEvent.type == sf::Event::Closed)
            {
                window.close();
            }
            screen->event(windowEvent);
        }

        // Clear screen
        // window.clear(CONFIG.BACKGROUND);
        window.clear();
        flag.display(window);

        // Display screen if it's loaded
        if (screen->screenIsLoaded)
        {
            nextScreenType = screen->display(window);
        }
        else
        {
            loadingScreen->display(window);
        }
        window.display();

        if (nextScreenType == ScreenType::EXIT)
        {
            window.close();
        }

        // Navigate to the next screen
        if (nextScreenType != currentScreenType)
        {
            currentScreenType = nextScreenType;

            // Switch to nextScreen if defined
            if (screen->nextScreen != nullptr)
            {
                screen = screen->nextScreen;
            }
            else if (nextScreenType == ScreenType::MAIN_MENU)
            {
                screen = new MainMenuScreen();
            }
            else if (nextScreenType == ScreenType::GAME)
            {
                screen = new GameScreen();
            }
            else if (nextScreenType == ScreenType::SETTINGS)
            {
                screen = new SettingsScreen(screen);
            }
            else if (nextScreenType == ScreenType::CREDITS)
            {
                screen = new CreditsScreen();
            }
            else if (nextScreenType == ScreenType::LOADING)
            {
                screen = new LoadingScreen();
            }
        }
    }
    return EXIT_SUCCESS;
}
