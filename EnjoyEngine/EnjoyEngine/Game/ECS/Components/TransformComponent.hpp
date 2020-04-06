#pragma once
#include "../../../GameEngine/ECS/Component/Component.hpp"
#include "../../../Helpers/Vectors.hpp"

namespace EnjoyEngine {
	class TransformComponent : public Component {
	public:
		TransformComponent(float px = 0.f, float py = 0.f, float m = 10.f, float mVel = 10000.f) : RotationVelocity(0.f), Rotation(0.f), affectedByGravity(false), isStatic(false), mass(m), maxVelocity(mVel) {
			Position = { px, py };
			Velocity = { 0.f, 0.f };
			Acceleration = { 0.f, 0.f };
			Gravity = { 0.f, (m * 9.81f) };
		};

		float mass;

		bool affectedByGravity;
		bool isStatic;

		Vector2D<float> Position;
		Vector2D<float> Velocity;
		Vector2D<float> Acceleration;

		Vector2D<float> Gravity;

		float maxVelocity;

		float RotationVelocity;
		float Rotation;
	};
}
