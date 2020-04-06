#pragma once
#include "../../../GameEngine/ECS/Component/Component.hpp"
#include "../../../GameEngine/GameObjects/GameObject.hpp"

namespace EnjoyEngine {
	class ClickableComponent : public Component {
	public:
		ClickableComponent() {};

		GameObject* object;
	};
}
