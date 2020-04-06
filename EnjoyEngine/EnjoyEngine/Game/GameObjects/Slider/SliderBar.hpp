#pragma once
#include "../../../GameEngine/GameObjects/GameObject.hpp"
#include "../../../Helpers/Vectors.hpp"
#include "../../ECS/Components/ComponentHeaders.hpp"

namespace EnjoyEngine {
	class SliderBar : public GameObject {
	private:

	public:
		SliderBar(float x, float y, int renderLayer);
		~SliderBar();

		void Update(float deltaTime) override;

		void onColision(Vector2D<float> minimumSeparationVector, int tag, int layer) override;
		void onClick(Vector2D<float> mousePosition, int mouseButton) override;

		Entity entity;
	};
}
