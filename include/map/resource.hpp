#ifndef RESOURCE_HPP
#define RESOURCE_HPP

#include <string>

extern std::string RESOURCES_FOLDER;


class Resource
{
    /**
    Represents a resource like water, rock, wood, food and so on.
    */
public:
    Resource();
    void load(const std::string tilesetName);
};

#endif // RESOURCE_HPP
