#include "Slider.hpp"

namespace EnjoyEngine {
	Slider::Slider(float x, float y, float minVal, float maxVal, int renderLayer) : _minValue(minVal), _maxValue(maxVal) {
		_sliderButton = new SliderButton(x, y, x - 126.f, x + 126.f, renderLayer + 1);
		_sliderBar = new SliderBar(x, y, renderLayer);
	};

	Slider::~Slider() {
		delete _sliderButton;
		delete _sliderBar;
	};

	void Slider::Update(float deltaTime) {

	};

	void Slider::onColision(Vector2D<float> minimumSeparationVector, int tag, int layer) {

	}

	void Slider::onClick(Vector2D<float> mousePosition, int mouseButton) {

	}

	float Slider::getValue() {
		float val = (_sliderButton->getX() - _sliderButton->getMinX()) / _sliderButton->getMaxX();
		val *= (_maxValue - _minValue);
		val += _minValue;
		return val;
	}
}
