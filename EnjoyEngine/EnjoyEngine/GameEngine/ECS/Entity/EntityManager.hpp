#pragma once
#include <vector>
#include <queue>

#include "../../../Helpers/Definitions.hpp"

namespace EnjoyEngine {
	class EntityManager {
	public:
		static EntityManager* get() {
			static EntityManager instance;
			return &instance;
		}

		uint32_t getID() {
			uint32_t ID = _freeIDs.front();
			_freeIDs.pop();
			entities.push_back(ID);
			return ID;
		}

		void entityDestroyed(uint32_t ID) {
			entities.erase(std::remove(entities.begin(), entities.end(), ID), entities.end());
			_freeIDs.push(ID);
		}

		std::vector<uint32_t> entities;

	private:
		EntityManager() {
			for (uint32_t i = 0; i < MAX_ENTITIES; i++) {
				_freeIDs.push(i);
			}
		}

		std::queue<uint32_t> _freeIDs;

	};
}
