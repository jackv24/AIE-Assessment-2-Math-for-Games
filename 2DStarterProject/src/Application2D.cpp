#include "Application2D.h"
#include <GLFW/glfw3.h>

#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#include <vector>

#include "MathLib.h"
#include "Scene.h"
#include "Planet.h"

Scene* scene;

Planet* sun;

Planet* blue_planet;
Planet* blue_planet_moon;

Planet* green_planet;
Planet* green_planet_moon1;
Planet* green_planet_moon2;

Application2D::Application2D() {
	
}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	createWindow("A.I. Project", 1280, 720);

	m_spriteBatch = new SpriteBatch();

	scene = new Scene();

	sun = new Planet("./bin/textures/Sun.png", Vector3(1280, 720, 1), 0, Vector3(0.5f, 0.5f, 1));
	scene->SetRoot(sun);

	blue_planet = new Planet("./bin/textures/Planet_Blue.png", Vector3(400, 100, 1), 0, Vector3(1, 1, 1));
	sun->AddChild(blue_planet);
	blue_planet_moon = new Planet("./bin/textures/Moon.png", Vector3(150, 0, 1), 0, Vector3(0.8f, 0.8f, 1));
	blue_planet->AddChild(blue_planet_moon);

	green_planet = new Planet("./bin/textures/Planet_Green.png", Vector3(-600, 0, 1), 0, Vector3(1, 1, 1));
	sun->AddChild(green_planet);
	green_planet_moon1 = new Planet("./bin/textures/Moon.png", Vector3(300, 0, 1), 0, Vector3(0.5f, 0.5f, 1));
	green_planet->AddChild(green_planet_moon1);
	green_planet_moon2 = new Planet("./bin/textures/Moon.png", Vector3(150, 0, 1), 0, Vector3(0.6f, 0.6f, 1));
	green_planet_moon1->AddChild(green_planet_moon2);

	return true;
}

void Application2D::shutdown() {

	delete sun;

	delete m_spriteBatch;

	destroyWindow();
}

bool Application2D::update(float deltaTime) {
	
	// close the application if the window closes or we press escape
	if (hasWindowClosed() || isKeyPressed(GLFW_KEY_ESCAPE))
		return false;

	sun->Update(1.0f);

	blue_planet->Update(0.5f);
	blue_planet_moon->Update(2.0f);

	green_planet->Update(1.5f);
	green_planet_moon1->Update(-3.0f);
	green_planet_moon2->Update(-0.5f);

	scene->UpdateTransforms();

	// the applciation closes if we return false
	return true;
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_spriteBatch->begin();

	sun->Draw(m_spriteBatch);

	blue_planet->Draw(m_spriteBatch);
	blue_planet_moon->Draw(m_spriteBatch);

	green_planet->Draw(m_spriteBatch);
	green_planet_moon1->Draw(m_spriteBatch);
	green_planet_moon2->Draw(m_spriteBatch);

	// done drawing sprites
	m_spriteBatch->end();	
}