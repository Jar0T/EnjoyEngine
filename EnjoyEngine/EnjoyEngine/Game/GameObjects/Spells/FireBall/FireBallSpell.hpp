#pragma once
#include "../Spell.hpp"
#include "FireBall.hpp"

namespace EnjoyEngine {
	class FireBallSpell : public Spell {
	private:
		std::vector<FireBall*> _fireballs;

	public:
		FireBallSpell(int renderLayer);
		~FireBallSpell();

		void Update(float deltaTime) override;

		void cast(Vector2D<float> position, Vector2D<float> direction) override;

	};
}
