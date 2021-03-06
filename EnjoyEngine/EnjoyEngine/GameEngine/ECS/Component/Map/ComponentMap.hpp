#pragma once
#include <map>
#include "IComponentMap.hpp"

namespace EnjoyEngine {
	template<typename T>
	class ComponentMap : public IComponentMap {
	private:
		std::map<uint32_t, T*> _componentMap;

	public:
		T* getComponent(EntityID entityID) {
			return _componentMap[entityID];
		}

		void addComponent(EntityID entityID, T* component) {
			_componentMap[entityID] = component;
		}

		void removeComponent(EntityID entityID) override {
			delete _componentMap[entityID];
			_componentMap.erase(entityID);
		}

	};
}
