#pragma once

namespace EnjoyEngine {
	class SettingsManager {
	private:
		SettingsManager() {}
		SettingsManager(const SettingsManager&) = delete;
		SettingsManager& operator=(SettingsManager const&) = delete;

	public:
		static SettingsManager& settingsManager() {
			static SettingsManager manager;
			return manager;
		};
		
		bool showBoundingBox = false;
		bool usingGravity = true;
		Vector2D<float> cameraPosition = { 0.f, 0.f };
		sf::Color backgroundColor = sf::Color::Black;

	};
}
