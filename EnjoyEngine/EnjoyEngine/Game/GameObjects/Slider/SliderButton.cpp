#include "SliderButton.hpp"

namespace EnjoyEngine {
	SliderButton::SliderButton(float x, float y, float minX, float maxX, int renderLayer) : _minX(minX), _maxX(maxX), _x(x) {
		entity.addComponent<TransformComponent>(x, y);
		entity.addComponent<SpriteComponent>(Textures::SLIDER_BUTTON, renderLayer);
		entity.addComponent<ColliderComponent>(x, y);

		entity.getComponent<ColliderComponent>().addPoint(Vector2D<float>{0, 0});
		entity.getComponent<ColliderComponent>().addPoint(Vector2D<float>{31, 0});
		entity.getComponent<ColliderComponent>().addPoint(Vector2D<float>{31, 31});
		entity.getComponent<ColliderComponent>().addPoint(Vector2D<float>{0, 31});
		entity.getComponent<ColliderComponent>().object = this;
		entity.getComponent<ColliderComponent>().setOrigin(Vector2D<float>{16, 16});

		entity.getComponent<SpriteComponent>().setOrigin(MIDDLE);

		entity.addComponent<ClickableComponent>();
		entity.getComponent<ClickableComponent>().object = this;
	};

	SliderButton::~SliderButton() {
		
	};

	void SliderButton::Update(float deltaTime) {

	};

	void SliderButton::onColision(Vector2D<float> minimumSeparationVector, int tag, int layer) {

	}

	void SliderButton::onClick(Vector2D<float> mousePosition, int mouseButton) {
		if ((mousePosition.x) >= _minX && (mousePosition.x) <= _maxX) {
			entity.getComponent<TransformComponent>().Position.x = mousePosition.x;
			_x = mousePosition.x;
		}
	}
}