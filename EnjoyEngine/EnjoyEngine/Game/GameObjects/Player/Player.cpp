#include "Player.hpp"

namespace EnjoyEngine {
	Player::Player(float x, float y, int renderLayer) {
		AssetManager::assetManager().loadTexture("Assets/Sprites/BlueSorcerer.png", Textures::PLAYER_SPRITE);

		entity.addComponent<TransformComponent>(x, y);
		entity.addComponent<SpriteComponent>(Textures::PLAYER_SPRITE, renderLayer, 2, 64, 64, 4);
		entity.addComponent<ColliderComponent>(x, y);

		entity.getComponent<ColliderComponent>().addPoint(Vector2D<float>{0, 0});
		entity.getComponent<ColliderComponent>().addPoint(Vector2D<float>{28, 0});
		entity.getComponent<ColliderComponent>().addPoint(Vector2D<float>{28, 40});
		entity.getComponent<ColliderComponent>().addPoint(Vector2D<float>{0, 40});
		entity.getComponent<ColliderComponent>().object = this;
		entity.getComponent<ColliderComponent>().setOrigin(Vector2D<float>{14, 20});

		entity.getComponent<SpriteComponent>().setOrigin(MIDDLE);

		mTag = Tags::Player;

		_spell = new FireBallSpell(renderLayer);
	}

	Player::~Player() {

	}

	void Player::Update(float deltaTime) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			entity.getComponent<TransformComponent>().Velocity.x = -100;
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			entity.getComponent<TransformComponent>().Velocity.x = 100;
		else entity.getComponent<TransformComponent>().Velocity.x = 0;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			entity.getComponent<TransformComponent>().Velocity.y = -100;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			entity.getComponent<TransformComponent>().Velocity.y = 100;
		else entity.getComponent<TransformComponent>().Velocity.y = 0;

		if (VariableManager::variableManager().getMousePosition().x > entity.getComponent<TransformComponent>().Position.x)
			entity.getComponent<SpriteComponent>().getSprite()->setScale(sf::Vector2f(-1, 1));
		else
			entity.getComponent<SpriteComponent>().getSprite()->setScale(sf::Vector2f(1, 1));

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			Vector2D<float> direction = VariableManager::variableManager().getMousePosition() - entity.getComponent<TransformComponent>().Position;
			direction.normalize();
			_spell->cast(entity.getComponent<TransformComponent>().Position, direction);
		}

		_spell->Update(deltaTime);

	}

	void Player::onColision(Vector2D<float> minimumSeparationVector, int tag, int layer) {

	}

	void Player::onClick(Vector2D<float> mousePosition, int mouseButton) {

	}
}