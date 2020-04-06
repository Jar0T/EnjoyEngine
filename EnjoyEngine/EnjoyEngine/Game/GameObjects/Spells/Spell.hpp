#pragma once
#include "Vectors.hpp"

namespace EnjoyEngine {
	class Spell {
	private:

	protected:
		int _renderLayer;
		float _cooldown;
		float _actualCooldown;

	public:
		Spell() {};
		virtual ~Spell() {};

		virtual void Update(float deltaTime) = 0;

		virtual void cast(Vector2D<float> position, Vector2D<float> direction) = 0;
	};
}