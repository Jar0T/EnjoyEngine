#include "AssetManager.hpp"
#include <iostream>

namespace EnjoyEngine {
	AssetManager& AssetManager::assetManager() {
		static AssetManager manager;
		return manager;
	}

	void AssetManager::loadTexture(const char* fileName, unsigned int key) {
		if (_textureMap[key] == nullptr) {
			_textureMap[key] = new sf::Texture;
			_textureMap[key]->loadFromFile(fileName);
			_textureMap[key]->setSmooth(true);
		}
	}

	void AssetManager::deleteTexture(unsigned int key) {
		delete _textureMap[key];
		_textureMap.erase(key);
	}

	sf::Texture& AssetManager::getTexture(unsigned int key) {
		return *_textureMap[key];
	}

	void AssetManager::loadSound(const char* filename, unsigned int key) {
		if (_soundMap[key] == nullptr) {
			_soundMap[key] = new sf::SoundBuffer;
			_soundMap[key]->loadFromFile(filename);
		}
	}

	void AssetManager::deleteSound(unsigned int key) {
		delete _soundMap[key];
		_soundMap.erase(key);
	}

	sf::SoundBuffer& AssetManager::getSound(unsigned int key) {
		return *_soundMap[key];
	}
}