//
// Created by Eben on 05/06/2019.
//

#ifndef INDIE_GAMESCENE_HPP
#define INDIE_GAMESCENE_HPP

#include <string>
#include <irrlicht/Keycodes.h>
#include <irrlicht/IEventReceiver.h>
#include <irrlicht/IVideoDriver.h>
#include <irrlicht/irrlicht.h>
#include <iostream>
#include "../../ecs/Entity.hpp"
#include "../../ecs/data/Vector2.hpp"
#include "IrrEntity/IrrEntity.hpp"
#include "../IrrInput/EventReceiver/EventReceiver.hpp"

namespace Irrlicht {

    class Screen;

    class GameScene {
    public:
        GameScene(Screen &screen, std::string name, unsigned id);
        ~GameScene() = default;


        void update();

        unsigned int registerEntity(const std::string &name);
        void deleteEntity(unsigned id);
        bool areColliding(unsigned entity1, unsigned entity2);
        void setAnimation(unsigned entity, Animations anim);
        void setPosition(unsigned entity, float x, float y);
        bool isKeyPressed(irr::EKEY_CODE key);
        bool isJoystickButtonPressed(unsigned id, unsigned button);
        float getJoystickAxisPosition(unsigned id, unsigned axis);
        // TODO void createMesh() or cube;

        const std::string sceneName;
        const unsigned id;
    private:
        std::vector<IrrEntity> _entities;
        unsigned _entities_id;
        Screen &_window;
        irr::scene::ISceneManager *_smgr;
        irr::gui::IGUIEnvironment *_guienv;
        EventReceiver &_eventReceiver;
    };
}


#endif //INDIE_GAMESCENE_HPP
