#pragma once
#include <SFML/System.hpp>

#define SCREEN_WIDTH_720p 1280
#define SCREEN_HEIGHT_720p 720
#define SCREEN_WIDTH_1080p 1920
#define SCREEN_HEIGHT_1080p 1080

#define MAX_COMPONENTS 32
#define MAX_ENTITIES 5000

using EntityID = uint32_t;
using ComponentTypeID = uint8_t;

enum Textures {
	SLIDER_BUTTON,
	SLIDER_BAR,
	PLAYER_SPRITE,
	FIRE_BALL_SPRITE
};

enum RenderLayers {
	Layer00,
	Layer01,
	Layer02,
	Layer04,
	Layer05,
	Layer06,
	Layer07,
	Layer08,
	Layer09,
	UILayer00,
	UILayer01,
	UILayer02,
	ColliderBoxes,
	numberOfLayers
};

enum Tags {
	Player,
	FireBall
};
