#pragma once
#include "../../../GameEngine/ECS/Component/Component.hpp"
#include "../../../GameEngine/GameObjects/GameObject.hpp"
#include <vector>


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

		Vector2D<float> getOrigin() {
			float minX = INFINITY, minY = INFINITY;
			for (auto& point : Points) {
				if (point.x < minX)
					minX = point.x;
				if (point.y < minY)
					minY = point.y;
			}
			return(Vector2D<float>{-minX, -minY});
		}

		void setOrigin(Vector2D<float> newOrigin) {
			Vector2D<float> origin = getOrigin();
			newOrigin = origin - newOrigin;
			for (auto& point : Points) {
				point = point + newOrigin;
			}
		}
	};
}
