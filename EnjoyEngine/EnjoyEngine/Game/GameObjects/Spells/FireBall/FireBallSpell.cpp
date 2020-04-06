#include "FireBallSpell.hpp"

namespace EnjoyEngine {
	FireBallSpell::FireBallSpell(int renderLayer) {
		_renderLayer = renderLayer;
		_cooldown = 0.2f;
		_actualCooldown = -1.f;
	}

	FireBallSpell::~FireBallSpell() {

	}

	void FireBallSpell::Update(float deltaTime) {
		if (_actualCooldown >= 0)
			_actualCooldown -= deltaTime;
		for (unsigned int i = 0; i < _fireballs.size(); i++) {
			if (_fireballs[i]->isDead) {
				FireBall *temp = _fireballs[i];
				_fireballs.erase(_fireballs.begin() + i);
				delete temp;
			}
			else {
				_fireballs[i]->Update(deltaTime);
			}
		}
	}

	void FireBallSpell::cast(Vector2D<float> position, Vector2D<float> direction) {
		if (_actualCooldown < 0) {
			_actualCooldown = _cooldown;
			Vector2D<float> velocity = direction * 100.f;
			position = position + direction * 40.f;
			_fireballs.push_back(new FireBall(position, velocity, 5.f, _renderLayer));
		}
	}
}
