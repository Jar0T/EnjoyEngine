#pragma once
#include <iostream>
#include <bitset>
#include <memory>

#include "../../../Helpers/Definitions.hpp"
#include "EntityManager.hpp"
#include "../Component/Manager/ComponentManager.hpp"

namespace EnjoyEngine {
	class Entity {
	private:
		std::bitset<MAX_COMPONENTS> _components;
		bool _isActive = true;


	public:
		Entity() {
			ID = EntityManager::get()->getID();
		}

		~Entity() {
			ComponentManager::get()->deleteAllFromEntity(ID);
			EntityManager::get()->entityDestroyed(ID);
		}

		template<typename T, typename... TArgs>
		void addComponent(TArgs&&... mArgs) {
			_components.set(getComponentTypeID<T>());
			ComponentManager::get()->addComponent<T>(ID, std::forward<TArgs>(mArgs)...);
		}

		template<typename T>
		bool hasComponent() {
			return _components[getComponentTypeID<T>()];
		}

		template<typename T>
		T& getComponent() {
			return *ComponentManager::get()->getComponent<T>(ID);
		}

		template<typename T>
		void removeComponent() {
			_components.reset(getComponentTypeID<T>());
			ComponentManager::get()->removeComponent<T>(ID);
		}

		bool isActive() {
			return _isActive;
		}

		EntityID ID;

	};
}
