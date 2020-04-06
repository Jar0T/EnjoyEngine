#pragma once
#include <map>
#include <memory>

#include "../Map/ComponentMap.hpp"
#include "../Component.hpp"

namespace EnjoyEngine {
	class ComponentManager {
	private:
		ComponentManager() {}

		std::map<ComponentTypeID, std::shared_ptr<IComponentMap>> _map{};

		template<typename T>
		std::shared_ptr<ComponentMap<T>> getComponentMap() {
			uint8_t typeID = getComponentTypeID<T>();
			if (_map.find(typeID) == _map.end())
				_map.insert({ typeID , std::make_shared<ComponentMap<T>>() });
			return std::static_pointer_cast<ComponentMap<T>>(_map[typeID]);
		}

	public:
		static ComponentManager* get() {
			static ComponentManager instance;
			return &instance;
		}

		template<typename T>
		T* getComponent(EntityID entityID) {
			return getComponentMap<T>()->getComponent(entityID);
		}

		template<typename T, typename... TArgs>
		void addComponent(EntityID entityID, TArgs&&... mArgs) {
			T* component(new T(std::forward<TArgs>(mArgs)...));
			getComponentMap<T>()->addComponent(entityID, component);
		}

		template<typename T>
		void removeComponent(EntityID entityID) {
			getComponentMap<T>()->removeComponent(entityID);
		}

		void deleteAllFromEntity(EntityID entityID) {
			for (auto &a : _map) {
				a.second->removeComponent(entityID);
			}
		}

	};
}
