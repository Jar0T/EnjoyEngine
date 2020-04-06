#pragma once
#include "Component.hpp"
#include "GameObject.hpp"

namespace EnjoyEngine {
	class ClickableComponent : public Component {
	public:
		ClickableComponent() {};

		GameObject* object;
	};
}
