/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Brick.cpp
*/

#include "Brick.hpp"
#include "../components/HealthComponent.hpp"
#include "../components/ColliderComponent.hpp"
#include "../components/PositionComponent.hpp"
#include "../components/DisplayableComponent.hpp"
#include "../components/BlockedComponent.hpp"
#include "../../config.hpp"
#include "../components/MortalComponent.hpp"

ECS::Brick::Brick(unsigned id, Ressources &ressources) :
	Entity(id, "Brick", {
		new HealthComponent(1),
		new DisplayableComponent("Brick", ressources),
		new ColliderComponent(1),
		new MortalComponent(),
		new PositionComponent({0, 0}, {TILESIZE, TILESIZE})
	})
{
}