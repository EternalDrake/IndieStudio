/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** DroppedBonusKick.cpp
*/

#include "DroppedBonusKick.hpp"
#include "../components/HealthComponent.hpp"
#include "../components/DisplayableComponent.hpp"
#include "../components/ColliderComponent.hpp"
#include "../components/PositionComponent.hpp"
#include "../../config.hpp"
#include "../components/PowerUpComponent.hpp"
#include "../components/PickableComponent.hpp"
#include "../components/PowerUpPickedComponent.hpp"

ECS::DroppedBonusKick::DroppedBonusKick(unsigned id, Ressources &ressources) :
    Entity(id, "DroppedBonusKick", {
        new HealthComponent(1),
        new DisplayableComponent("DroppedBonusKick", ressources),
        new ColliderComponent(0),
        new PositionComponent({0, 0}, {TILESIZE, TILESIZE}),
        new PowerUpComponent({{"Kick", true}}),
        new PickableComponent(),
        new PowerUpPickedComponent()
    })
{
}