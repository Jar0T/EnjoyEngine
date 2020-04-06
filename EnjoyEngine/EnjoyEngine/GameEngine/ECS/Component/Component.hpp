#pragma once
#include "../../../Helpers/Definitions.hpp"

namespace EnjoyEngine {
	inline ComponentTypeID getComponentTypeID() {
		static ComponentTypeID lastID = 0;
		return lastID++;
	}

	template<typename T>
	inline ComponentTypeID getComponentTypeID() {
		static ComponentTypeID componentTypeID = getComponentTypeID();
		return componentTypeID;
	}

	class Component {
	public:
		virtual ~Component() {};

	};
}
