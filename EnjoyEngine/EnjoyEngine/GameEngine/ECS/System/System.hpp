#pragma once

#include "EntityManager.hpp"
#include "ComponentManager.hpp"

namespace EnjoyEngine {
	class System {
	public:
		virtual ~System() {};

		virtual void update(float deltaTime, sf::RenderWindow *window) = 0;

	private:

	};
}
