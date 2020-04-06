#pragma once
#include "../../../GameEngine/ECS/System/System.hpp"
#include "../Components/ClickableComponent.hpp"
#include "../Components/ColliderComponent.hpp"
#include "../../../Helpers/Vectors.hpp"
#include "../../Managers/VariableManager/VariableManager.hpp"
#include <Windows.h>

namespace EnjoyEngine {
	class ClickableSystem : public System {
	public:
		bool SATCollision(ColliderComponent &a, Vector2D<float> pos) {

			ColliderComponent *c1 = &a;

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

				//Project point to projection axis
				float dot = pos.dot(projectionAxis);

				if (!(dot >= min_c1 && max_c1 >= dot)) {
					return false;
				}
			}
			return true;
		}

		void update(float deltaTime, sf::RenderWindow *window) override {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				//Get mouse position
				Vector2D<float> mPos = VariableManager::variableManager().getMousePosition();

				for (auto &entity : EntityManager::get()->entities) {
					//Check if entities have necessary components
					if (ComponentManager::get()->getComponent<ClickableComponent>(entity) != nullptr) {
						if (ComponentManager::get()->getComponent<ColliderComponent>(entity) != nullptr) {
							//Check if entity has chance to be clicked
							if (ComponentManager::get()->getComponent<ColliderComponent>(entity)->Radius >= (mPos - ComponentManager::get()->getComponent<ColliderComponent>(entity)->Position).magnitude()) {
								//Check if entity was actually clicked
								if (SATCollision(*ComponentManager::get()->getComponent<ColliderComponent>(entity), mPos)) {
									ComponentManager::get()->getComponent<ClickableComponent>(entity)->object->onClick(mPos, sf::Mouse::Left);
								}
							}

						}
					}
				}
			}
		}
	};
}
