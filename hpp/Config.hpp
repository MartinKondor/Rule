#ifndef CONFIG_HPP_INCLUDED
#define CONFIG_HPP_INCLUDED

#include <string>
#include <fstream>
#include "Utils.hpp"


class Config {
public:
    std::string configFileName;
    std::string BASE_FOLDER = "";

    // Default values
    unsigned int WINDOW_WIDTH = 800;
    unsigned int WINDOW_HEIGHT = 600;
    unsigned int MUSIC_VOLUME = 50;
    unsigned int SOUND_VOLUME = 50;
    unsigned int MASTER_VOLUME = 100;
    bool IS_FULLSCREEN = false;
    bool VSYNC_ENABLED = true;
    // BACKGROUND

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
