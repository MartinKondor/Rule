#include "config.hpp"


Config::Config() {}

Config::Config(std::string baseFolder, std::string fileName)
{
    this->load(baseFolder, fileName);
}

void Config::load(std::string baseFolder, std::string fileName)
{
    this->BASE_FOLDER = baseFolder;
    this->load(baseFolder + fileName);
}

void Config::load(std::string fileName)
{
    this->setDefault();
    this->configFileName = fileName;

    if (!utils::isFileExists(fileName))
    {
        this->save(fileName);
    }

    std::ifstream infile(fileName);
    std::string line;

    // Start reading from file
    if (infile.is_open())
    {
        while (std::getline(infile, line))
        {

            std::string key;
            std::string value;
            bool parseKey = true;

            // Parse each line char by char
            for (uint8_t i = 0; i < line.length(); i++)
            {
                if (line[i] == ' ')
                {
                    continue;
                }

                if (line[i] == '=')
                {
                    parseKey = false;
                    continue;
                }

                if (parseKey)
                {
                    key += line[i];
                }
                else
                {
                    value += line[i];
                }
            }

            this->parseConfigKey(key, value);
        }
        infile.close();
    }

    // Check errorous settings
    if (this->WINDOW_WIDTH < 800)
    {
        this->WINDOW_WIDTH = 800;
    }
    else if (this->WINDOW_HEIGHT < 600)
    {
        this->WINDOW_HEIGHT = 600;
    }
}

void Config::save(std::string fileName)
{
    std::string data = "";
    std::ofstream configFile;
    configFile.open(fileName);

    data += "WINDOW_WIDTH=" + utils::to_string(this->WINDOW_WIDTH) + "\n";
    data += "WINDOW_HEIGHT=" + utils::to_string(this->WINDOW_HEIGHT) + "\n";
    data += "MASTER_VOLUME=" + utils::to_string(this->MASTER_VOLUME) + "\n";
    data += "SOUND_VOLUME=" + utils::to_string(this->SOUND_VOLUME) + "\n";
    data += "MUSIC_VOLUME=" + utils::to_string(this->MUSIC_VOLUME) + "\n";
    data += "IS_FULLSCREEN=" + utils::to_string(this->IS_FULLSCREEN) + "\n";
    data += "VSYNC_ENABLED=" + utils::to_string(this->VSYNC_ENABLED) + "\n";

    configFile.write(data.c_str(), data.length());
    configFile.close();
}

void Config::setDefault()
{
    // Set every key's state to false by default
    for (unsigned int i = 0; i < irr::KEY_KEY_CODES_COUNT; i++)
    {
        this->keyState[i] = false;
    }

    this->WINDOW_WIDTH = 800;
    this->WINDOW_HEIGHT = 600;
    this->MUSIC_VOLUME = 50;
    this->SOUND_VOLUME = 50;
    this->MASTER_VOLUME = 100;
    this->IS_FULLSCREEN = false;
    this->VSYNC_ENABLED = true;
}

void Config::parseConfigKey(std::string key, std::string value)
{
    if ("WINDOW_WIDTH" == key)
    {
        try
        {
            this->WINDOW_WIDTH = std::stoi(value.c_str());
        }
        catch (std::exception) {}
    }
    else if ("WINDOW_HEIGHT" == key)
    {
        try
        {
            this->WINDOW_HEIGHT = std::stoi(value.c_str());
        }
        catch (std::exception) {}
    }
    else if ("MASTER_VOLUME" == key)
    {
        try
        {
            this->MASTER_VOLUME = std::stoi(value.c_str());
        }
        catch (std::exception) {}
    }
    else if ("SOUND_VOLUME" == key)
    {
        try
        {
            this->SOUND_VOLUME = std::stoi(value.c_str());
        }
        catch (std::exception) {}
    }
    else if ("MUSIC_VOLUME" == key)
    {
        try
        {
            this->MUSIC_VOLUME = std::stoi(value.c_str());
        }
        catch (std::exception) {}
    }
    else if ("IS_FULLSCREEN" == key)
    {
        try
        {
            this->IS_FULLSCREEN = (bool) std::stoi(value.c_str());
        }
        catch (std::exception) {}
    }
    else if ("VSYNC_ENABLED" == key)
    {
        try
        {
            this->VSYNC_ENABLED = (bool) std::stoi(value.c_str());
        }
        catch (std::exception) {}
    }
}
