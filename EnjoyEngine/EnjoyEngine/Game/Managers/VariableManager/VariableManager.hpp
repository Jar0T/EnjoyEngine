#pragma once

namespace EnjoyEngine {
	class VariableManager {
	private:
		VariableManager() {}
		VariableManager(const VariableManager&) = delete;
		VariableManager& operator=(VariableManager const&) = delete;

		Vector2D<float> mousePosition;

		Vector2D<float> cameraPosition;

	public:
		static VariableManager& variableManager() {
			static VariableManager manager;
			return manager;
		};

		Vector2D<float> getMousePosition() { return mousePosition; };
		void setMousePosition(Vector2D<float> newPos) { mousePosition = newPos; };
		void setMousePosition(float x, float y) { mousePosition.x = x; mousePosition.y = y; };

		Vector2D<float> getCameraPos() { return cameraPosition; };
		void setCameraPos(Vector2D<float> newPos) { cameraPosition = newPos; };
		void setCameraPos(float x, float y) { cameraPosition.x = x; cameraPosition.y = y; };
	};
}