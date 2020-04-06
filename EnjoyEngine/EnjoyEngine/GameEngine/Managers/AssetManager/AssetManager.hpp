#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>

namespace EnjoyEngine {
	class AssetManager {
	private:
		AssetManager() {}
		AssetManager(const AssetManager&) = delete;
		AssetManager& operator=(AssetManager const&) = delete;

		std::map<unsigned int, sf::Texture*> _textureMap;
		std::map<unsigned int, sf::SoundBuffer*> _soundMap;

	public:
		static AssetManager& assetManager();

		void loadTexture(const char* fileName, unsigned int key);
		void deleteTexture(unsigned int key);
		sf::Texture& getTexture(unsigned int key);

		void loadSound(const char* filename, unsigned int key);
		void deleteSound(unsigned int key);
		sf::SoundBuffer& getSound(unsigned int key);
	};
}