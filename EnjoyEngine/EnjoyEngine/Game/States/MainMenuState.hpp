#pragma once
#include "../../GameEngine/StateMachine/State.hpp"
#include "../../GameEngine/Game/Game.hpp"

#include "../../GameEngine/ECS/System/Manager/SystemManager.hpp"
#include "../Managers/SettingsManager/SettingsManager.hpp"

#include "../../Helpers/Definitions.hpp"
#include "../ECS/Components/ComponentHeaders.hpp"

#include "../ECS/Systems/SpriteSystem.hpp"
#include "../ECS/Systems/ClickableSystem.hpp"
#include "../ECS/Systems/TransformSystem.hpp"
#include "../ECS/Systems/ColliderSystem.hpp"

#include "../GameObjects/Slider/Slider.hpp"
#include "../GameObjects/Player/Player.hpp"

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
