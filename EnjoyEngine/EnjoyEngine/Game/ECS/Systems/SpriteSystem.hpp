#pragma once
#include "../../../GameEngine/ECS/System/System.hpp"
#include "../Components/TransformComponent.hpp"
#include "../Components/SpriteComponent.hpp"
#include "../Components/ColliderComponent.hpp"
#include "../../Managers/SettingsManager/SettingsManager.hpp"

namespace EnjoyEngine {
	class SpriteSystem : public System {
	public:
		void update(float deltaTime, sf::RenderWindow *window) override {
			sf::RenderTexture renderTexture[RenderLayers::numberOfLayers];
			for (int i = 0; i < RenderLayers::numberOfLayers; i++) {
				renderTexture[i].create(window->getSize().x, window->getSize().y);
				renderTexture[i].clear(sf::Color::Transparent);
			}
			for (auto &entity : EntityManager::get()->entities) {
				if (ComponentManager::get()->getComponent<SpriteComponent>(entity) != nullptr &&
					ComponentManager::get()->getComponent<TransformComponent>(entity) != nullptr) {

					//Animation (change to next sprite)
					if (ComponentManager::get()->getComponent<SpriteComponent>(entity)->numberOfSprites > 1) {
						if (ComponentManager::get()->getComponent<SpriteComponent>(entity)->frameTime != 0.f) {
							float elapsedTime = ComponentManager::get()->getComponent<SpriteComponent>(entity)->elapsedTime -= deltaTime;
							if (elapsedTime <= 0.f) {
								ComponentManager::get()->getComponent<SpriteComponent>(entity)->index++;
								ComponentManager::get()->getComponent<SpriteComponent>(entity)->index = ComponentManager::get()->getComponent<SpriteComponent>(entity)->index % ComponentManager::get()->getComponent<SpriteComponent>(entity)->numberOfSprites;
								ComponentManager::get()->getComponent<SpriteComponent>(entity)->elapsedTime = ComponentManager::get()->getComponent<SpriteComponent>(entity)->frameTime + elapsedTime;
							}
						}
					}

					//Set sprite position
					ComponentManager::get()->getComponent<SpriteComponent>(entity)->getSprite()->setPosition(sf::Vector2f(
						ComponentManager::get()->getComponent<TransformComponent>(entity)->Position.x,
						ComponentManager::get()->getComponent<TransformComponent>(entity)->Position.y
					));

					//Set sprite rotation
					ComponentManager::get()->getComponent<SpriteComponent>(entity)->getSprite()->setRotation(
						ComponentManager::get()->getComponent<TransformComponent>(entity)->Rotation
					);

					//Check if entity isodd screen
					Vector2D<float> pos = { ComponentManager::get()->getComponent<SpriteComponent>(entity)->getSprite()->getPosition().x , ComponentManager::get()->getComponent<SpriteComponent>(entity)->getSprite()->getPosition().y };
					float size;
					size = ComponentManager::get()->getComponent<SpriteComponent>(entity)->getSprite()->getLocalBounds().width;
					size = (ComponentManager::get()->getComponent<SpriteComponent>(entity)->getSprite()->getLocalBounds().height > size ? ComponentManager::get()->getComponent<SpriteComponent>(entity)->getSprite()->getLocalBounds().height : size );
					if (pos.x + size < 0 || pos.x - size > window->getSize().x || pos.y + size < 0 || pos.y - size > window->getSize().y)
						ComponentManager::get()->getComponent<SpriteComponent>(entity)->isVisible = false;
					else
						ComponentManager::get()->getComponent<SpriteComponent>(entity)->isVisible = true;

					//Draw entity to renderTexture
					if (ComponentManager::get()->getComponent<SpriteComponent>(entity)->isVisible) {
						renderTexture[ComponentManager::get()->getComponent<SpriteComponent>(entity)->layer].draw(*ComponentManager::get()->getComponent<SpriteComponent>(entity)->getSprite());
						if (ComponentManager::get()->getComponent<ColliderComponent>(entity) != nullptr) {
							//Draw collider box to its own layer
							if (SettingsManager::settingsManager().showBoundingBox) {
								if (ComponentManager::get()->getComponent<ColliderComponent>(entity)->rotatedPoints.size() > 0) {
									std::vector<sf::Vertex> box;
									Vector2D<float> position = ComponentManager::get()->getComponent<ColliderComponent>(entity)->Position;
									for (auto &point : ComponentManager::get()->getComponent<ColliderComponent>(entity)->rotatedPoints) {
										box.push_back(sf::Vertex(sf::Vector2f(point.x, point.y), sf::Color::Red));
									}
									box.push_back(sf::Vertex(sf::Vector2f(ComponentManager::get()->getComponent<ColliderComponent>(entity)->rotatedPoints[0].x, ComponentManager::get()->getComponent<ColliderComponent>(entity)->rotatedPoints[0].y)));
									box.back().color = sf::Color::Red;
									renderTexture[RenderLayers::ColliderBoxes].draw(&box[0], box.size(), sf::LineStrip);
								}
							}
						}
					}

				}
			}

			//Draw renderLayers on window
			window->clear(SettingsManager::settingsManager().backgroundColor);

			for (int i = 0; i < RenderLayers::numberOfLayers; i++) {
				renderTexture[i].display();
				sf::Sprite sprite(renderTexture[i].getTexture());
				window->draw(sprite);
			}

			window->display();
		}

	};
}
