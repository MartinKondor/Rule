#ifndef SCREEN_HPP_INCLUDED
#define SCREEN_HPP_INCLUDED


enum ScreenType
{
    EXIT,
    MAIN_MENU,
    SETTINGS,
    GAME
};


class Screen
{
public:
    irr::gui::IGUIEnvironment* env;

    virtual ScreenType display() = 0;
};

#endif // SCREEN_HPP_INCLUDED
