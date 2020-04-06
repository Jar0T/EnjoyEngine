#include "Game.hpp"
#include "../../Game/States/MainMenuState.hpp"

namespace EnjoyEngine {
	void Game::Init(int wWidth, int wHeight, const char* wTitle) {
		this->_data->windowSize.x = wWidth;
		this->_data->windowSize.y = wHeight;
		this->_data->window.create(sf::VideoMode(wWidth, wHeight), wTitle, sf::Style::Titlebar | sf::Style::Close);
		this->_data->machine.pushState(StateRef(new MainMenuState(this->_data)));
		this->Run();
	}

	void Game::Run() {
		float lastUpdate = .0f, deltaTime = .0f;
		while (this->_data->window.isOpen()) {
			deltaTime = this->_clock.getElapsedTime().asSeconds() - lastUpdate;
			lastUpdate = this->_clock.getElapsedTime().asSeconds();
			this->_data->machine.getActiveState()->Update(deltaTime);
			this->_data->machine.getActiveState()->HandleEvents();
		}
	}
}