#include "animation.hpp"


Animation::Animation() {}

Animation::Animation(const std::string animationName)
{
    this->animationName = animationName;
    this->width = 0;
    this->height = 0;
    this->frameIndex = 0;
    this->frameCount = 0;
    this->framesPerSecond = 8;
    this->width = 0;
    this->height = 0;
    this->counter.restart();

    const std::string infoFileName = ANIMATION_FOLDER + animationName + "/info.txt";
    const std::string spritesheetFileName = ANIMATION_FOLDER + animationName + "/spritesheet.png";

    // Check the info file
    if (!Utils::isFileExists(infoFileName) || !Utils::isFileExists(spritesheetFileName))
    {
        openMessageBox("Unknown animation name (" + animationName + ")");
        exit(EXIT_FAILURE);
    }

    // Load the animation
    if (!this->load(spritesheetFileName, infoFileName))
    {
        openMessageBox("Cannot load animation (" + spritesheetFileName + ")");
        exit(EXIT_FAILURE);
    }
}

bool Animation::load(const std::string fileName, const std::string infoFileName)
{
    // Load animation image
    sf::Image animImg;
    if (!animImg.loadFromFile(fileName) || !this->loadInfo(infoFileName))
    {
        return false;
    }

    // Determine sprite size from the info file
    sf::Vector2u imgSize = animImg.getSize();

    for (unsigned int i = 0; i < (unsigned int) (imgSize.y / this->height); i++)
    {
        for (unsigned int j = 0; j < (unsigned int) (imgSize.x / this->width); j++)
        {
            sf::Texture* texture = new sf::Texture();
            if (!texture->loadFromImage(animImg, sf::IntRect(j * this->width, i * this->height, this->width, this->height)))
            {
                return false;
            }

            sf::Sprite* sprite = new sf::Sprite();
            sprite->setTexture(*texture);
            this->frames.push_back(sprite);
        }
    }

    this->frameCount = imgSize.x / this->width;  // this->frames.size();
    return true;
}

bool Animation::loadInfo(const std::string infoFileName)
{
    std::string key;
    std::string value;
    bool inValue = false;

    std::string line;
    std::ifstream infoFile;
    infoFile.open(infoFileName);

    while (std::getline(infoFile, line))
    {
        for (unsigned int i = 0; i < line.length(); i++)
        {
            if (line[i] == ' ' || line[i] == '\t')
            {
                continue;
            }
            else if (line[i] == '=')
            {
                inValue = true;
                continue;
            }

            if (inValue)
            {
                value += line[i];
            }
            else
            {
                key += line[i];
            }
        }

        if (key == "width")
        {
            this->width = std::stoi(value);
        }
        else if (key == "height")
        {
            this->height = std::stoi(value);
        }

        key = "";
        value = "";
        inValue = false;
    }

    infoFile.close();
    return true;
}

void Animation::play(const unsigned int xPos, const unsigned int yPos, Direction direction, sf::RenderWindow &window)
{
    if (this->framesPerSecond > 0 && this->counter.getElapsedTime().asMilliseconds() >= (1000 / this->framesPerSecond))
    {
        if (++this->frameIndex >= this->frameCount)
        {
            this->frameIndex = 0;
        }
        this->counter.restart();
    }

    // Set the position of the frame
    sf::Sprite* currentFrame = this->frames[10 * (int)(direction) + this->frameIndex];
    currentFrame->setPosition(xPos, yPos);
    window.draw(*currentFrame);
}
