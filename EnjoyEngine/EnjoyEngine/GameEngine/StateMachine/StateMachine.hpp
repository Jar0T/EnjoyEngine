#pragma once

#include <memory>
#include <stack>

#include "State.hpp"

namespace EnjoyEngine {
	typedef std::unique_ptr<State> StateRef;

	class StateMachine {
	private:
		std::stack<StateRef> _states;

	public:
		void pushState(StateRef newState, bool isReplacing = true);
		void popState();

		StateRef &getActiveState();

	};
}