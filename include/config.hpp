#ifndef CONFIG_HPP
#define CONFIG_HPP


class Config {
    public:
        int WINDOW_WIDTH = 800;
        int WINDOW_HEIGHT = 600;
        bool IS_FULLSCREEN = false;
        int FPS_LIMIT = 30;

        Config();
};

#endif // CONFIG_HPP
