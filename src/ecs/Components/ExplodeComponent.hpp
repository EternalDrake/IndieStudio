/*
** EPITECH PROJECT, 2018
** ECS
** File description:
** ExplodeComponent.hpp
*/

#ifndef EXPLODECOMPONENT_HPP
#define EXPLODECOMPONENT_HPP

#include "../Component.hpp"
#include "../Ressources.hpp"

namespace ECS
{
    class ExplodeComponent : public Component
    {
        public:
            unsigned int range;
            unsigned int strength;
            bool exploded = false;
            ExplodeComponent(unsigned int range, unsigned int strength);
            ExplodeComponent(const Ressources &ressources, std::istream &stream);
	    std::ostream &serialize(std::ostream &stream) const override;
    };
} // namespace ECS

#endif