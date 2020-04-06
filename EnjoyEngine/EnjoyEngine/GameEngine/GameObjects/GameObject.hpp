#pragma once
#include "Entity.hpp"
#include "Vectors.hpp"

namespace EnjoyEngine {
	class GameObject {
	private:

	public:
		GameObject() {};
		virtual ~GameObject() {};

		virtual void Update(float deltaTime) = 0;

		virtual void onColision(Vector2D<float> minimumSeparationVector, int tag, int layer) = 0;
		virtual void onClick(Vector2D<float> mousePosition, int mouseButton) = 0;

		int mLayer, mTag;
	};
}
