#include "map.hpp"

#include <iostream>


Map::Map() {}

Map::Map(const std::string mapName)
{
    const std::string fileName = MAP_FOLDER + mapName;

    // Check for the file first
    if (!Utils::isFileExists(fileName))
    {
        openMessageBox("Cannot load map, as the (" + fileName + ") doesn't exist.");
        exit(EXIT_FAILURE);
    }

    this->load(fileName);
}

void Map::load(const std::string fileName)
{
    this->layers = {};

    // Properties of the map
    std::string tileWidth = "32";
    std::string tileHeight = "32";
    std::vector<std::vector<unsigned int>> currentLayer;

    // Start reading file
    std::ifstream mapFile;
    mapFile.open(fileName);

    std::string line;
    std::string token;
    bool waitingForOpeningBraces = false;
    bool inTileMatrix = false;

    // Load it line by line
    while (std::getline(mapFile, line))
    {
        // Go character by character
        for (unsigned int i = 0; i < line.length(); i++)
        {
            // Ignore comments
            if (line[i] == '#')
            {
                break;
            }
            else if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n' || line[i] == '\r')
            {
                continue;
            }

            if (waitingForOpeningBraces)
            {
                if (line[i] == '{')
                {
                    inTileMatrix = true;
                    waitingForOpeningBraces = false;
                }
                continue;
            }
            else if (inTileMatrix)
            {
                if (line[i] == '}')
                {
                    this->layers.push_back(currentLayer);
                    currentLayer = {};
                    token = "";
                    inTileMatrix = false;
                    break;
                }
                currentLayer.push_back(this->parseTileRow(line));
                break;
            }

            token += line[i];

            if (token == "tileWidth")
            {
                tileWidth = this->parseKeyValue(line);
                token = "";
                break;
            }
            else if (token == "tileHeight")
            {
                tileHeight = this->parseKeyValue(line);
                token = "";
                break;
            }
            else if (token == "tileset")
            {
                this->tileset.load(this->parseKeyValue(line), std::stoi(tileWidth), std::stoi(tileHeight));
                token = "";
                break;
            }
            else if (token == "resources")
            {
                this->loadResources(this->parseKeyValue(line));
                token = "";
                break;
            }
            else if (token == "layer")
            {
                waitingForOpeningBraces = true;
            }

        }
    }

    mapFile.close();
}

void Map::loadResources(const std::string resourceName)
{
    std::cout << resourceName << std::endl;
}

std::string Map::parseKeyValue(const std::string line)
{
    std::string value = "";
    bool inValue = false;

    for (unsigned int i = 0; i < line.length(); i++)
    {
        if (inValue)
        {
            value += line[i];
        }

        if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n' || line[i] == '\r')
        {
            continue;
        }
        else if (line[i] == '=')
        {
            inValue = true;
            continue;
        }
    }

    Utils::trim(value);

    // Check for string notation
    if (value[0] == '"' && value[value.length() - 1] == '"')
    {
        value = value.substr(1, value.length() - 2);
    }

    return value;
}

std::vector<unsigned int> Map::parseTileRow(std::string line)
{
    std::vector<unsigned int> tileRow;
    std::string currentValue;

    for (unsigned int i = 0; i < line.length(); i++)
    {
        if (line[i] == ' ' || line[i] == '\t')
        {
            continue;
        }
        else if (line[i] == '\n' || line[i] == '\r')
        {
            break;
        }
        else if (line[i] == ',')
        {
            try
            {
                tileRow.push_back(std::stoi(currentValue));
            }
            catch (std::exception) {}
            currentValue = "";
            continue;
        }

        currentValue += line[i];
    }

    try
    {
        tileRow.push_back(std::stoi(currentValue));
    }
    catch (std::exception) {}
    return tileRow;
}

void Map::display(sf::RenderWindow& window)
{
    sf::Sprite tileSprite;
    int cartX = 0;
    int cartY = 0;

    for (std::vector<std::vector<unsigned int>> layer : this->layers)
    {
        for (unsigned int i = 0; i < layer.size(); i++)
        {
            for (unsigned int j = 0; j < layer[i].size(); j++)
            {
                tileSprite.setTexture(*this->tileset.tiles[layer[i][j]]);

                cartX = j * this->tileset.tileWidth / 2;
                cartY = i * this->tileset.tileHeight / 2;

                tileSprite.setPosition(cartX - cartY, (cartX + cartY) / 2);
                window.draw(tileSprite);
            }
        }
    }

}
