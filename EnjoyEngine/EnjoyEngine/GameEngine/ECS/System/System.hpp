#pragma once

#include <SFML/Graphics.hpp>
#include "../Entity/EntityManager.hpp"
#include "../Component/Manager/ComponentManager.hpp"

namespace EnjoyEngine {
	class System {
	public:
		virtual ~System() {};

		virtual void update(float deltaTime, sf::RenderWindow *window) = 0;

	private:

	};
}
