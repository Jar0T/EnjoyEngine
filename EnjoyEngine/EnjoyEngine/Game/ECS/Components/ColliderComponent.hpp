#pragma once
#include "Component.hpp"
#include <vector>
#include "GameObject.hpp"

namespace EnjoyEngine {
	class ColliderComponent : public Component {
	public:
		ColliderComponent(float x = 0, float y = 0, float m = 10.f) : isStatic(false) {
			Position.x = x;
			Position.y = y;
		};

		std::vector<Vector2D<float>> Points;
		std::vector<Vector2D<float>> rotatedPoints;
		Vector2D<float> Position;
		float Radius;
		GameObject* object;
		float mass;
		bool isStatic;

		void addPoint(Vector2D<float> point) {
			if (point.magnitude() > Radius)
				Radius = point.magnitude();
			Points.push_back(point);
			rotatedPoints.push_back(point);
		}
	};
}
