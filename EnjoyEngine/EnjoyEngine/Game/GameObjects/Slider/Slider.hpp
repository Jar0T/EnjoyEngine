#pragma once
#include "../../../GameEngine/GameObjects/GameObject.hpp"
#include "../../../Helpers/Vectors.hpp"
#include "../../ECS/Components/ComponentHeaders.hpp"
#include "SliderButton.hpp"
#include "SliderBar.hpp"

namespace EnjoyEngine {
	class Slider : public GameObject {
	private:
		float _minValue, _maxValue;
		SliderButton* _sliderButton;
		SliderBar* _sliderBar;

	public:
		Slider(float x, float y, float minVal, float maxVal, int renderLayer);
		~Slider();

		void Update(float deltaTime) override;

		void onColision(Vector2D<float> minimumSeparationVector, int tag, int layer) override;
		void onClick(Vector2D<float> mousePosition, int mouseButton) override;

		float getValue();
	};
}
