#ifndef CONFIG_HPP_INCLUDED
#define CONFIG_HPP_INCLUDED

#include <string>
#include <fstream>
#include <irrlicht.h>
#include "utils.hpp"


class Config
{
public:
    bool keyState[irr::KEY_KEY_CODES_COUNT];  // Keys status
    std::string configFileName;
    std::string BASE_FOLDER = "";

    // Default values
    unsigned int WINDOW_WIDTH;
    unsigned int WINDOW_HEIGHT;
    unsigned int MUSIC_VOLUME;
    unsigned int SOUND_VOLUME;
    unsigned int MASTER_VOLUME;
    bool IS_FULLSCREEN;
    bool VSYNC_ENABLED;

    Config();
    Config(std::string baseFolder, std::string fileName);
    void load(std::string baseFolder, std::string fileName);
    void load(std::string fileName);
    void save(std::string fileName);
    void setDefault();

private:
    /**
    Setting the "config" class variable "key" to the given "value"
    */
    void parseConfigKey(std::string key, std::string value);
};

#endif // CONFIG_HPP_INCLUDED
