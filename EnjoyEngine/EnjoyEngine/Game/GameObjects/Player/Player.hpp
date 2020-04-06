#pragma once
#include "../../../GameEngine/GameObjects/GameObject.hpp"
#include "../../../Helpers/Vectors.hpp"
#include "../../ECS/Components/ComponentHeaders.hpp"
#include "../../../GameEngine/Managers/AssetManager/AssetManager.hpp"
#include "../../Managers/VariableManager/VariableManager.hpp"
#include "../Spells/Spell.hpp"
#include "../Spells/FireBall/FireBallSpell.hpp"

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
