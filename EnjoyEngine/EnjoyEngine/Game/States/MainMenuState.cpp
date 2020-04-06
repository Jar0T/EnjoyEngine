#include "MainMenuState.hpp"

namespace EnjoyEngine {
	void MainMenuState::Init() {
		VariableManager::variableManager().setMousePosition((float)sf::Mouse::getPosition(_data->window).x, (float)sf::Mouse::getPosition(_data->window).y);
		AssetManager::assetManager().loadTexture("Assets/Textures/Slider/SliderButton.png", Textures::SLIDER_BUTTON);
		AssetManager::assetManager().loadTexture("Assets/Textures/Slider/SliderBar.png", Textures::SLIDER_BAR);

		player = new Player(100, 100, RenderLayers::Layer00);

		SystemManager::getInstance()->registerSystem<SpriteSystem>();
		SystemManager::getInstance()->registerSystem<TransformSystem>();
		SystemManager::getInstance()->registerSystem<ColliderSystem>();
		SystemManager::getInstance()->registerSystem<ClickableSystem>();

	}

	void MainMenuState::Update(float deltaTime) {
		VariableManager::variableManager().setMousePosition((float)sf::Mouse::getPosition(_data->window).x, (float)sf::Mouse::getPosition(_data->window).y);
		SystemManager::getInstance()->update(deltaTime, &this->_data->window);
		player->Update(deltaTime);

	}

	void MainMenuState::HandleEvents() {
		sf::Event event;

		while (this->_data->window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				this->_data->window.close();
				break;
			case sf::Event::KeyPressed:
				if(event.key.code == sf::Keyboard::F2)
					SettingsManager::settingsManager().showBoundingBox = !SettingsManager::settingsManager().showBoundingBox;
			default:
				break;
			}
		}
	}

	void MainMenuState::onExitButtonClicked() {
		this->_data->window.close();
	}
}