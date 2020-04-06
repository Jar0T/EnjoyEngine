#include "StateMachine.hpp"

namespace EnjoyEngine {
	void StateMachine::pushState(StateRef newState, bool isReplacing) {
		if (isReplacing) {
			this->popState();
		}
		this->_states.push(std::move(newState));
		this->_states.top()->Init();
	}

	void StateMachine::popState() {
		if (!this->_states.empty()) {
			this->_states.top().reset();
			this->_states.pop();
		}
	}

	StateRef &StateMachine::getActiveState() {
		return this->_states.top();
	}
}