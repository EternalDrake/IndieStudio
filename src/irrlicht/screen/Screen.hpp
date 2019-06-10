//
// Created by Eben on 27/05/2019.
//

#ifndef BOMBERMAN_SCREEN_HPP
#define BOMBERMAN_SCREEN_HPP

#include <string>
#include "../Animations.hpp"
#include "irrlicht/irrlicht.h"
#include "../../ecs/Entity.hpp"
#include "../../ecs/data/Vector2.hpp"
#include "../irr-input/event-receiver/EventReceiver.hpp"


//#define TRANSFORM_COLOR_TO_SFML_COLOR(color) sf::Color(static_cast<sf::Uint8>(color >> 16), static_cast<sf::Uint8>(color >> 8), static_cast<sf::Uint8>(color))
#define WINDOW_NAME "Bomberman"

namespace Irrlicht
{
    class GameScene;

    class Screen {
    public:
        explicit Screen(int width = 640, int height = 480, int colorDepth = 32, bool fullscreen = false, bool vsync = true);
        ~Screen() = default;

        //MEMBER FUNCTIONS
        bool display();
        GameScene &getCurrentGameScene();
        bool setCurrentGameScene(unsigned id);
        bool setCurrentGameScene(const std::string &name);
        bool setFullscreen(bool fullscreen);
        bool setVsync(bool vsync);
        bool setWindowSize(int width, int height);
        bool setWindowAttributes(int width, int height, int colorDepth, bool fullscreen, bool vsync);
        unsigned addGameScene(const std::string &name);
        EventReceiver &getEventReceiver();
        irr::video::IVideoDriver* getDriver();
        irr::scene::ISceneManager* getSmgr();

    private:
        irr::video::E_DRIVER_TYPE _driverType; // TODO differenciate OpenGL and Dx9 when running under win32/64 or GNU/UNIX
        //TODO LIMIT BY DELTA TIME IN MOVEMENT TUTORIAL
        int _width;
        int _height;
        int _colorDepth;
        bool _fullscreen;
        bool _vsync;
        unsigned _currentSceneId;
        unsigned _lastSceneId;
        std::vector<std::unique_ptr<GameScene>> _scenes;

        //PROPERTIES
        irr::IrrlichtDevice* _device;
        irr::video::IVideoDriver* _driver;
        irr::gui::IGUIEnvironment* _guienv; //TODO GETTER SETTER
        irr::scene::ISceneManager* _smgr; //TODO GETTER SETTER
        EventReceiver _eventReceiver;

        //void drawRect(ECS::Point pos, ECS::Vector2<unsigned> size, Color color = 0xFFFFFF, bool filled = false);

    };
}


#endif //BOMBERMAN_IRRLICHT_HPP