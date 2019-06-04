//
// Created by Eben on 27/05/2019.
//

#ifndef BOMBERMAN_SCREEN_HPP
#define BOMBERMAN_SCREEN_HPP

#include <string>
#include "Animations.hpp"
#include "../ecs/Entity.hpp"
#include "../ecs/data/Vector2.hpp"

//#define TRANSFORM_COLOR_TO_SFML_COLOR(color) sf::Color(static_cast<sf::Uint8>(color >> 16), static_cast<sf::Uint8>(color >> 8), static_cast<sf::Uint8>(color))

namespace Irrlicht
{
    typedef unsigned Color;

    class IrrEntity {
    public:
        unsigned id;
        ECS::Point pos;
        irr::scene::IAnimatedMesh* mesh;
        Animations anim;
        ECS::Vector2<unsigned> size;
        Color color;

        IrrEntity(const std::string &name, unsigned id);
    };

    class Irrlicht {
    private:
        std::vector<IrrEntity> _entities;
        irr::IrrlichtDevice *_device;
        irr::video::E_DRIVER_TYPE driverType; // TODO differenciate OpenGL and Dx9 when running under win32/64 or GNU/UNIX
        unsigned _lastId;

        void drawRect(ECS::Point pos, ECS::Vector2<unsigned> size, Color color = 0xFFFFFF, bool filled = false);

    public:
        Irrlicht();

//        unsigned registerEntity(const std::string &name);
//        bool areColliding(unsigned entity1, unsigned entity2);
//        void setAnimation(unsigned entity, Animations anim);
//        void setPosition(unsigned entity, float x, float y);
//        void display();
    };
    class screen {
    public:
        screen(int width = 640, int height = 480, int colorDepth = 32, bool fullscreen = false, bool vsync = true);
        ~screen() = default;

        //MEMBER FUNCTIONS
        int display();
        bool setFullscreen(bool fullscreen);
        bool setVsync(bool vsync);
        bool setWindowSize(int width, int height);

        //PROPERTIES
        irr::IrrlichtDevice* _device;
        irr::video::IVideoDriver* _driver;
        irr::scene::ISceneManager* _smgr;


    private:
        std::vector<IrrEntity> _entities;
        irr::video::E_DRIVER_TYPE _driverType; // TODO differenciate OpenGL and Dx9 when running under win32/64 or GNU/UNIX
        int _width;
        int _height;
        int _colorDepth;
        bool _fullscreen;
        bool _vsync;
        //unsigned _lastId;

        //void drawRect(ECS::Point pos, ECS::Vector2<unsigned> size, Color color = 0xFFFFFF, bool filled = false);

};
}


#endif //BOMBERMAN_IRRLICHT_HPP
