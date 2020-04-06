#include "SliderBar.hpp"

namespace EnjoyEngine {
	SliderBar::SliderBar(float x, float y, int renderLayer) {
		entity.addComponent<TransformComponent>(x, y);
		entity.addComponent<SpriteComponent>(Textures::SLIDER_BAR, renderLayer);
	};

	SliderBar::~SliderBar() {

	};

	void SliderBar::Update(float deltaTime) {

	};

	void SliderBar::onColision(Vector2D<float> minimumSeparationVector, int tag, int layer) {

	}

	void SliderBar::onClick(Vector2D<float> mousePosition, int mouseButton) {
		
	}
}