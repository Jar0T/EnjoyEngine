#pragma once
#include "System.hpp"
#include "TransformComponent.hpp"
#include "ColliderComponent.hpp"
#include "SFML/Graphics.hpp"

namespace EnjoyEngine {
	class TransformSystem : public System {
	public:
		void update(float deltaTime, sf::RenderWindow *window) override {
			for (auto &entity : EntityManager::get()->entities) {
				if (ComponentManager::get()->getComponent<TransformComponent>(entity) != nullptr) {
					bool isStatic = ComponentManager::get()->getComponent<TransformComponent>(entity)->isStatic;
					//Move entity
					if (!isStatic) {
						Vector2D<float> position = ComponentManager::get()->getComponent<TransformComponent>(entity)->Position;
						Vector2D<float> velocity = ComponentManager::get()->getComponent<TransformComponent>(entity)->Velocity;
						Vector2D<float> acceleration = ComponentManager::get()->getComponent<TransformComponent>(entity)->Acceleration;
						float maxVelocity = ComponentManager::get()->getComponent<TransformComponent>(entity)->maxVelocity;
						position = position + velocity * deltaTime;
						velocity = velocity + acceleration * deltaTime;
						if (ComponentManager::get()->getComponent<TransformComponent>(entity)->affectedByGravity) {
							velocity = velocity + ComponentManager::get()->getComponent<TransformComponent>(entity)->Gravity * deltaTime;
						}
						ComponentManager::get()->getComponent<TransformComponent>(entity)->Position = position;
						ComponentManager::get()->getComponent<TransformComponent>(entity)->Velocity = (velocity.magnitude() > maxVelocity ? velocity.setMagnitude(maxVelocity) : velocity);
					}

					//Rotate entity
					ComponentManager::get()->getComponent<TransformComponent>(entity)->Rotation = ComponentManager::get()->getComponent<TransformComponent>(entity)->Rotation + ComponentManager::get()->getComponent<TransformComponent>(entity)->RotationVelocity * deltaTime;
					
					//Transform collider
					if (ComponentManager::get()->getComponent<ColliderComponent>(entity) != nullptr) {
						//Move collider to position
						ComponentManager::get()->getComponent<ColliderComponent>(entity)->Position = ComponentManager::get()->getComponent<TransformComponent>(entity)->Position;

						//Rotate collider
						std::vector<Vector2D<float>>::iterator it = ComponentManager::get()->getComponent<ColliderComponent>(entity)->rotatedPoints.begin();
						float angle = ComponentManager::get()->getComponent<TransformComponent>(entity)->Rotation * 3.14f / 180.f;
						Vector2D<float> position = ComponentManager::get()->getComponent<ColliderComponent>(entity)->Position;
						for (auto &point : ComponentManager::get()->getComponent<ColliderComponent>(entity)->Points) {
							it->x = (point.x * cos(angle)) - (point.y * sin(angle));
							it->y = (point.x * sin(angle)) + (point.y * cos(angle));

							it->x = it->x + position.x;
							it->y = it->y + position.y;

							it++;
						}
					}
				}
			}
		}

	};
}
