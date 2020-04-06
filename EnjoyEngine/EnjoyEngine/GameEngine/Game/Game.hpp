#pragma once
#include <memory>

#include <SFML/Graphics.hpp>
#include "../StateMachine/StateMachine.hpp"
#include "../../Helpers/Vectors.hpp"

namespace EnjoyEngine {
	struct GameData {
		sf::RenderWindow window;
		StateMachine machine;
		Vector2D<int> windowSize;
	};

	typedef std::shared_ptr<GameData> GameDataRef;

	class Game {
	private:
		sf::Clock _clock;
		GameDataRef _data = std::make_shared<GameData>();

		void Run();

	public:
		void Init(int wWidth, int wHeight, const char* wTitle);

	};
}