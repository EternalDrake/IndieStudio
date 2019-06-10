//
// Created by Eben on 05/06/2019.
//

#ifndef INDIE_IRRENTITY_HPP
#define INDIE_IRRENTITY_HPP

#include <string>
#include <irrlicht/irrlicht.h>
#include <iostream>
#include "../../Animations.hpp"
#include "../../../ecs/Entity.hpp"
#include "../../../ecs/data/Vector2.hpp"
#include "../../screen/Screen.hpp"

namespace Irrlicht {
    class IrrEntity {
    public:
        IrrEntity(
            const std::string &filename,
            unsigned id,
            irr::scene::ISceneManager *smgr,
            irr::video::IVideoDriver *driver,
            irr::video::SColor defaultColor = irr::video::SColor(255, 255, 255, 255),
            std::string texturePath = ""
        );
        ~IrrEntity();

        bool isEntityLoaded();
        void setScale(float x, float z);
        void setPos(float x, float y);
    //PROPERTIES
        unsigned id;
        Animations anim;
        irr::video::SColor _defaultColor;
    private:
        std::string _meshPath;
        irr::scene::ISceneManager* _smgr;
        irr::scene::IAnimatedMesh* _mesh;
        irr::scene::IAnimatedMeshSceneNode* _node;
        irr::scene::ISceneNode* _parent;
        std::string _texturePath;
        bool _loaded;
    };
}


#endif //INDIE_IRRENTITY_HPP
