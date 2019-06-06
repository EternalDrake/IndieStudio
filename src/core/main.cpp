#include <iostream>
#include <fstream>
#include "irrlicht/Keycodes.h"
#include "../irrlicht/Irrlicht.hpp"
#include "../map/Map.hpp"
#include "../input/Keyboard.hpp"
#include "../ecs/Exceptions.hpp"

Map::Map *loadMap(ECS::Ressources &res, std::string path)
{
	std::ifstream stream(path);

	try {
		if (stream.is_open())
			return new Map::Map{res, stream};
	} catch (ECS::InvalidSerializedStringException &e) {
		std::cerr << "The saved map is invalid " << e.what() << std::endl;
	}

	auto map = new Map::Map{res};

	map->generateMap({20, 20}, 70);
	return map;
}

int main()
{
	try {
		Irrlicht::Irrlicht screen;
		std::vector<std::unique_ptr<Input::Input>> inputs;
		inputs.emplace_back(
			new Input::Keyboard(screen, {
				irr::KEY_KEY_Z,
				irr::KEY_KEY_Q,
				irr::KEY_KEY_S,
				irr::KEY_KEY_D,
				irr::KEY_SPACE,
				irr::KEY_KEY_A,
			})
		);
		ECS::Ressources res{screen, inputs, {}};
		Map::Map *map = loadMap(res, "save.txt");

		for (auto &sound_name : sound_to_load)
			res.soundSystem.loadSound(sound_name);
		res.soundSystem.setLoop("battle_music", true);

		res.soundSystem.playSound("battle_music"); // tmp
		while (!screen.isEnd()) {
			map->update();
			screen.display();
		}
		std::ofstream stream("save.txt");
		stream << *map << std::endl;
		delete map;
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}