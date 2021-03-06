#pragma once
#include "../../../GameEngine/ECS/System/System.hpp"
#include "../Components/TransformComponent.hpp"
#include "../Components/ColliderComponent.hpp"
#include <SFML/Graphics.hpp>

namespace EnjoyEngine {
	class TransformSystem : public System {
	public:
		void update(float deltaTime, sf::RenderWindow *window) override {
			for (auto &entity : EntityManager::get()->entities) {
				if (ComponentManager::get()->getComponent<TransformComponent>(entity) != nullptr) {
					bool isStatic = ComponentManager::get()->getComponent<TransformComponent>(entity)->isStatic;
					//Move entity
					if (!isStatic) {
						float mass = ComponentManager::get()->getComponent<TransformComponent>(entity)->mass;
						Vector2D<float> position = ComponentManager::get()->getComponent<TransformComponent>(entity)->Position;
						Vector2D<float> velocity = ComponentManager::get()->getComponent<TransformComponent>(entity)->Velocity;
						Vector2D<float> acceleration = ComponentManager::get()->getComponent<TransformComponent>(entity)->Acceleration;
						if (velocity.magnitude() < 0.001)
							velocity.setMagnitude(0);
						Vector2D<float> friction = velocity * -1.f;
						if (ComponentManager::get()->getComponent<TransformComponent>(entity)->grounded)
							friction.setMagnitude(mass * 9.81 * 3.f);
						else
							friction.setMagnitude(0.f);
						float maxVelocity = ComponentManager::get()->getComponent<TransformComponent>(entity)->maxVelocity;
						acceleration = acceleration + friction * deltaTime;
						velocity = velocity + acceleration * deltaTime;
						position = position + velocity * deltaTime;

						if (ComponentManager::get()->getComponent<TransformComponent>(entity)->affectedByGravity) {
							acceleration.y = acceleration.y + 9.81f * deltaTime * deltaTime * mass;
						}

						ComponentManager::get()->getComponent<TransformComponent>(entity)->Position = position;
						ComponentManager::get()->getComponent<TransformComponent>(entity)->Velocity = (velocity.magnitude() > maxVelocity ? velocity.setMagnitude(maxVelocity) : velocity);
						ComponentManager::get()->getComponent<TransformComponent>(entity)->Acceleration.setMagnitude(0.f);
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
