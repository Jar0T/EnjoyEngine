#pragma once
#include "GameObject.hpp"
#include "ComponentHeaders.hpp"
#include "Vectors.hpp"

namespace EnjoyEngine {
	class FireBall : public GameObject {
	private:

	public:
		FireBall(Vector2D<float> position, Vector2D<float> velocity, float lifeTime, int renderLayer);
		~FireBall();

		void Update(float deltaTime) override;

		void onColision(Vector2D<float> minimumSeparationVector, int tag, int layer) override;
		void onClick(Vector2D<float> mousePosition, int mouseButton) override;

		Entity entity;
		float lifeTime;
		bool isDead = false;

	};
}
