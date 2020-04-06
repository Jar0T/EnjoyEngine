#pragma once
#include <iostream>

namespace EnjoyEngine {
	class State {
	public:
		virtual ~State() {};
		virtual void Init() = 0;
		virtual void Update(float deltaTime) = 0;
		virtual void HandleEvents() = 0;
	};
}
