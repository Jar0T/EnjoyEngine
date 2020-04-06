#pragma once
#include "../../../GameEngine/ECS/System/System.hpp"
#include "../Components/ColliderComponent.hpp"
#include <SFML/Graphics.hpp>

namespace EnjoyEngine {
	class ColliderSystem : public System {
	private:
		Vector2D<float> SATCollision(ColliderComponent &a, ColliderComponent &b) {

			ColliderComponent *c1 = &a;
			ColliderComponent *c2 = &b;

			float overlap = INFINITY;
			Vector2D<float> minimumSeparationVector = { 0.f, 0.f };

			for (int x = 0; x < 2; x++) {

				if (x == 1) {
					c1 = &b;
					c2 = &a;
				}
				
				for (unsigned int i = 0; i < c1->rotatedPoints.size(); i++) {
					int j = (i + 1) % c1->rotatedPoints.size();
					Vector2D<float> projectionAxis = { -(c1->rotatedPoints[j].y - c1->rotatedPoints[i].y), (c1->rotatedPoints[j].x - c1->rotatedPoints[i].x) };
					projectionAxis.normalize();

					//Project points of polygon c1 to projection matrix
					float min_c1 = INFINITY, max_c1 = -INFINITY;
					for (unsigned int p = 0; p < c1->rotatedPoints.size(); p++) {
						float dot = c1->rotatedPoints[p].dot(projectionAxis);
						min_c1 = std::min(min_c1, dot);
						max_c1 = std::max(max_c1, dot);
					}

					//Project points of polygon c2 to projection matrix
					float min_c2 = INFINITY, max_c2 = -INFINITY;
					for (unsigned int p = 0; p < c2->rotatedPoints.size(); p++) {
						float dot = c2->rotatedPoints[p].dot(projectionAxis);
						min_c2 = std::min(min_c2, dot);
						max_c2 = std::max(max_c2, dot);
					}

					float dist = std::min(max_c1, max_c2) - std::max(min_c1, min_c2);
					overlap = (overlap > dist ? dist : overlap);

					if (!(max_c2 >= min_c1 && max_c1 >= min_c2)) {
						Vector2D<float> noOverlapVector = { 0.f, 0.f };
						return noOverlapVector;
					}
				}
			}
			minimumSeparationVector = c2->Position - c1->Position;
			minimumSeparationVector.setMagnitude(overlap);
			return minimumSeparationVector;
		}

	public:
		void update(float deltaTime, sf::RenderWindow *window) override {
			for (std::vector<uint32_t>::iterator it1 = EntityManager::get()->entities.begin(); it1 != EntityManager::get()->entities.end(); ++it1) {
				if (ComponentManager::get()->getComponent<ColliderComponent>(*it1) != nullptr) {
					for (std::vector<uint32_t>::iterator it2 = it1 + 1; it2 != EntityManager::get()->entities.end(); ++it2) {
						if (ComponentManager::get()->getComponent<ColliderComponent>(*it2) != nullptr) {
							ColliderComponent* c1 = ComponentManager::get()->getComponent<ColliderComponent>(*it1);
							ColliderComponent* c2 = ComponentManager::get()->getComponent<ColliderComponent>(*it2);
							float distance = (c1->Position - c2->Position).magnitude();
							if (distance <= (c1->Radius + c2->Radius)) {
								Vector2D<float> overlapVector = SATCollision(*c1, *c2);
								if (overlapVector.x != 0.f || overlapVector.y != 0.f) {
									if (c1->isStatic) {
										c2->object->onColision(overlapVector * -1, c1->object->mTag, c1->object->mLayer);
									}
									else if (c2->isStatic) {
										c1->object->onColision(overlapVector, c2->object->mTag, c2->object->mLayer);
									}
									else {
										c1->object->onColision(overlapVector * (c2->mass / (c1->mass + c2->mass)), c2->object->mTag, c2->object->mLayer);
										c2->object->onColision(overlapVector * -1 * (c1->mass / (c1->mass + c2->mass)), c1->object->mTag, c1->object->mLayer);
									}
								}
							}
						}
					}
				}
			}
		}
	};
}
