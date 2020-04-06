#pragma once
#include <vector>

#include "../System.hpp"

namespace EnjoyEngine {
	class SystemManager {
	public:
		static SystemManager* getInstance() {
			static SystemManager instance;
			return &instance;
		}

		void update(float deltaTime, sf::RenderWindow *window) {
			for (auto &system : _systemsVector) {
				system->update(deltaTime, window);
			}
		}

		template<typename T>
		void registerSystem() {
			_systemsVector.push_back(new T());
		}

	private:
		SystemManager() {}

		std::vector<System*> _systemsVector;

	};
}
