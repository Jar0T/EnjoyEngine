#pragma once
#include "../../../GameEngine/ECS/Component/Component.hpp"
#include "../../../Helpers/Vectors.hpp"

namespace EnjoyEngine {
	class TransformComponent : public Component {
	public:
		TransformComponent(float px = 0.f, float py = 0.f, float m = 10.f, float mVel = 10000.f, bool grounded = true) : RotationVelocity(0.f), Rotation(0.f), affectedByGravity(false), isStatic(false), mass(m), maxVelocity(mVel), grounded(grounded) {
			Position = { px, py };
			Velocity = { 0.f, 0.f };
			Acceleration = { 0.f, 0.f };
		};

		float mass;

		bool affectedByGravity;
		bool isStatic;
		bool grounded;

		Vector2D<float> Position;
		Vector2D<float> Velocity;
		Vector2D<float> Acceleration;

		float maxVelocity;

		float RotationVelocity;
		float Rotation;

		void addForce(Vector2D<float> force) {
			Acceleration = Acceleration + force / mass;
		}

		void setForce(Vector2D<float> force) {
			Acceleration = force / mass;
		}
	};
}
