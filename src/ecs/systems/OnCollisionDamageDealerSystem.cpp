/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** OnCollisionDamageDealerSystem.cpp
*/

#include "OnCollisionDamageDealerSystem.hpp"
#include "../ECSCore.hpp"
#include "../components/PositionComponent.hpp"
#include "../components/OnCollisionDamageDealerComponent.hpp"
#include "../components/CollisionComponent.hpp"
#include "../components/HealthComponent.hpp"

ECS::OnCollisionDamageDealerSystem::OnCollisionDamageDealerSystem(ECS::ECSCore &core):
    System("OnCollisionDamageDealer", core)
{
    this->_dependencies = {"Collision"};
}

void ECS::OnCollisionDamageDealerSystem::updateEntity(ECS::Entity &entity)
{
    CollisionComponent &cc = reinterpret_cast<CollisionComponent &>(entity.getComponentByName("Collision"));
    OnCollisionDamageDealerComponent &ddc = reinterpret_cast<OnCollisionDamageDealerComponent &>(entity.getComponentByName("OnCollisionDamageDealer"));

    for (Entity *entityCollided : cc.entitiesCollided) {
        if (entityCollided->hasComponent("Health")) {
            HealthComponent &hc = reinterpret_cast<HealthComponent &>(entityCollided->getComponentByName("Health"));

            hc.takeDamage(ddc.damage);
        }
    }
}