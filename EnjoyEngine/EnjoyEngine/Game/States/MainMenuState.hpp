#pragma once
#include "State.hpp"
#include "Game.hpp"

#include "SystemManager.hpp"
#include "SettingsManager.hpp"

#include "Definitions.hpp"
#include "ComponentHeaders.hpp"

#include "SpriteSystem.hpp"
#include "ClickableSystem.hpp"
#include "TransformSystem.hpp"
#include "ColliderSystem.hpp"

#include "Slider.hpp"
#include "Player.hpp"

namespace EnjoyEngine {
	class MainMenuState : public State {
	private:
		GameDataRef _data;
		Slider *sliderR;
		Slider *sliderG;
		Slider *sliderB;
		Player *player;

	public:
		MainMenuState(GameDataRef data) : _data(data) {};
		~MainMenuState() { delete sliderR; delete sliderG; delete sliderB; };

		void Init() override;
		void Update(float deltaTime) override;
		void HandleEvents() override;

		void onExitButtonClicked();

	};

	typedef void (MainMenuState::*onClick)(void);
}
