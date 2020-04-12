#pragma once
#include "../../../GameEngine/ECS/Component/Component.hpp"
#include "../../../GameEngine/Managers/AssetManager/AssetManager.hpp"
#include "../../../Helpers/Definitions.hpp"
#include <SFML/Graphics.hpp>

#include <vector>

namespace EnjoyEngine {
	enum OriginPosition {
		MIDDLE,
		ZERO
	};

	class SpriteComponent : public Component {
	private:
		std::vector<sf::Sprite> spriteVector;

	public:
		SpriteComponent(int textureID, int layer, int numberOfSprites = 1, int width = 0, int height = 0, int FPS = 0) : numberOfSprites(numberOfSprites), layer(layer), index(0), isVisible(true) {
			(FPS == 0 ? frameTime = 0.f : frameTime = 1.f / ((float)FPS));
			elapsedTime = frameTime;
			
			if (numberOfSprites > 1) {
				for (int i = 0; i < numberOfSprites; i++) {
					sf::Sprite sprite;
					sprite.setTexture(AssetManager::assetManager().getTexture(textureID));
					if ((width != 0) && (height != 0)) {
						sprite.setTextureRect(sf::IntRect(0, (i * height), width, height));
					}
					spriteVector.push_back(sprite);
				}
			}
			else {
				sf::Sprite sprite;
				sprite.setTexture(AssetManager::assetManager().getTexture(textureID));
				spriteVector.push_back(sprite);
			}
		};

		bool isVisible;
		int layer;
		int numberOfSprites;
		int index;
		float frameTime;
		float elapsedTime;

		sf::Sprite* getSprite() {
			return &spriteVector[index];
		};

		void setOrigin(Vector2D<float> newOrigin) {
			for (auto& sprite : spriteVector) {
				sprite.setOrigin(newOrigin.x, newOrigin.y);
			}
		}

		void setOrigin(int position) {
			switch (position)
			{
			case ZERO:
				for (auto& sprite : spriteVector) {
					sprite.setOrigin(0.f, 0.f);
				}
				break;
			case MIDDLE:
				for (auto& sprite : spriteVector) {
					sprite.setOrigin(sprite.getLocalBounds().width / 2.f, sprite.getLocalBounds().height / 2.f);
				}
				break;
			default:
				break;
			}
		}

	};
}
