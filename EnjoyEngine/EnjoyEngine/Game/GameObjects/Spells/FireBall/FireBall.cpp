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
		entity.getComponent<TransformComponent>().grounded = false;

		entity.addComponent<ColliderComponent>(position.x, position.y);
		entity.getComponent<ColliderComponent>().addPoint(Vector2D<float>{0, 0});
		entity.getComponent<ColliderComponent>().addPoint(Vector2D<float>{32, 0});
		entity.getComponent<ColliderComponent>().addPoint(Vector2D<float>{32, 32});
		entity.getComponent<ColliderComponent>().addPoint(Vector2D<float>{0, 32});
		entity.getComponent<ColliderComponent>().object = this;
		entity.getComponent<ColliderComponent>().setOrigin(Vector2D<float>{16, 16});

		entity.addComponent<SpriteComponent>(Textures::FIRE_BALL_SPRITE, renderLayer);
		entity.getComponent<SpriteComponent>().setOrigin(MIDDLE);

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
