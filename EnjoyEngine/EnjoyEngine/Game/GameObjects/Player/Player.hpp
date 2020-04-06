#pragma once
#include "GameObject.hpp"
#include "Vectors.hpp"
#include "ComponentHeaders.hpp"
#include "AssetManager.hpp"
#include "VariableManager.hpp"
#include "Spell.hpp"
#include "FireBallSpell.hpp"

namespace EnjoyEngine {
	class Player : public GameObject {
	private:
		Spell* _spell;

	public:
		Player(float x, float y, int renderLayer);
		~Player();

		void Update(float deltaTime) override;

		void onColision(Vector2D<float> minimumSeparationVector, int tag, int layer) override;
		void onClick(Vector2D<float> mousePosition, int mouseButton) override;

		Entity entity;
	};
}
