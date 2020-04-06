#include "SliderButton.hpp"

namespace EnjoyEngine {
	SliderButton::SliderButton(float x, float y, float minX, float maxX, int renderLayer) : _minX(minX), _maxX(maxX), _x(x) {
		entity.addComponent<TransformComponent>(x, y);
		entity.addComponent<SpriteComponent>(Textures::SLIDER_BUTTON, renderLayer);
		entity.addComponent<ColliderComponent>(x, y);
		Vector2D<float> p = { -16.f, -16.f };
		entity.getComponent<ColliderComponent>().addPoint(p);
		p.x = 15.f;
		entity.getComponent<ColliderComponent>().addPoint(p);
		p.y = 15.f;
		entity.getComponent<ColliderComponent>().addPoint(p);
		p.x = -16.f;
		entity.getComponent<ColliderComponent>().addPoint(p);
		entity.getComponent<ColliderComponent>().object = this;
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