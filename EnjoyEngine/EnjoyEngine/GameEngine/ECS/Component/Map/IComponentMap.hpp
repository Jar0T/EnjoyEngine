#pragma once
#include "../../../Helpers/Definitions.hpp"

namespace EnjoyEngine {
	class IComponentMap {
	public:
		virtual ~IComponentMap() = default;
		virtual void removeComponent(EntityID entityID) = 0;
	};
}
