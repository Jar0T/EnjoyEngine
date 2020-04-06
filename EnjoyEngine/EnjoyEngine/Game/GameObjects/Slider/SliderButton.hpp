#pragma once
#include "../../../GameEngine/GameObjects/GameObject.hpp"
#include "../../../Helpers/Vectors.hpp"
#include "../../ECS/Components/ComponentHeaders.hpp"

namespace EnjoyEngine {
	class SliderButton : public GameObject {
	private:
		float _minX, _maxX;
		float _x;
	public:
		SliderButton(float x, float y, float minX, float maxX, int renderLayer);
		~SliderButton();

		void Update(float deltaTime) override;

		void onColision(Vector2D<float> minimumSeparationVector, int tag, int layer) override;
		void onClick(Vector2D<float> mousePosition, int mouseButton) override;

		float getX() { return _x; };
		float getMinX() { return _minX; };
		float getMaxX() { return _maxX; };

		Entity entity;
	};
}
