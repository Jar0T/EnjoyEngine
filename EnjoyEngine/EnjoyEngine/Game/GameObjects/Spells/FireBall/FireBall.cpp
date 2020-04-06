#include "FireBall.hpp"

namespace EnjoyEngine {
	FireBall::FireBall(Vector2D<float> position, Vector2D<float> velocity, float lifeTime, int renderLayer) : lifeTime(lifeTime) {
		AssetManager::assetManager().loadTexture("Assets/Sprites/FireBall.png", Textures::FIRE_BALL_SPRITE);

		Vector2D<float> xVec = { 1.f, 0.f };
		float dot = xVec.dot(velocity);
		float angle = acos(dot / velocity.magnitude()) * 180.f / 3.14f;

		entity.addComponent<TransformComponent>(position.x, position.y);
		entity.getComponent<TransformComponent>().Velocity = velocity;
		entity.getComponent<TransformComponent>().Rotation = angle;

		entity.addComponent<ColliderComponent>(position.x, position.y);
		Vector2D<float> col = { -16, -16 };
		entity.getComponent<ColliderComponent>().addPoint(col);
		col.x = 16;
		entity.getComponent<ColliderComponent>().addPoint(col);
		col.y = 16;
		entity.getComponent<ColliderComponent>().addPoint(col);
		col.x = -16;
		entity.getComponent<ColliderComponent>().addPoint(col);
		entity.getComponent<ColliderComponent>().object = this;

		entity.addComponent<SpriteComponent>(Textures::FIRE_BALL_SPRITE, renderLayer);

		mTag = Tags::FireBall;
	}

	FireBall::~FireBall() {

	}

	void FireBall::Update(float deltaTime) {
		lifeTime -= deltaTime;
		if (lifeTime <= 0)
			isDead = true;

	}

	void FireBall::onColision(Vector2D<float> minimumSeparationVector, int tag, int layer) {
		if (tag != Tags::Player && tag != Tags::FireBall)
			isDead = true;
	}

	void FireBall::onClick(Vector2D<float> mousePosition, int mouseButton) {

	}
}
