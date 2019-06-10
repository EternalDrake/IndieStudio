/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Controller.cpp
*/

#include "Controller.hpp"
#include "../irrlicht/game-scene/GameScene.hpp"

Input::Controller::Controller(Irrlicht::GameScene &scene, std::vector<unsigned> &&keys, unsigned id) :
    _scene(scene),
    _keys(keys),
    _id(id)
{
   if (keys.size() != NB_OF_ACTIONS)
       throw ControllerErrors(); // la condition est pas bonne , enfin je croit, je revienderais dessu quand je retournerais sur les inputs

  //TODO THROW INVALID ARG AND NOT CONTROLLER ERROR
}

Input::Controller::~Controller() {}

std::vector<Input::Action> Input::Controller::getActions() { //does not work
    std::vector<Action> actions;

    for (unsigned i = 0; i < this->_keys.size(); i++) {
        if (this->_scene.isJoystickButtonPressed(_id, this->_keys[i]))
            actions.push_back(static_cast<Action>(i));
    }
    return (actions);
}

void Input::Controller::changeKey(Action, unsigned) {}