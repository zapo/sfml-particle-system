/*
 * main.cpp
 *
 *  Created on: 2011-02-17
 *      Author: zapo
 */
#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <sstream>
#include "Types.h"
#include "FadeOutAffector.h"
#include "RandomColorAffector.h"
#include "ParticleSystem.h"
#include "SmokeEmitter.h"
#include "Rocket.h"


using namespace std;

int main(int argc, char** argv) {

	sf::RenderWindow window(sf::VideoMode(1024, 768, 32), "Particle system");

	sf::Vector2f center(1024 / 2, 768 / 2);

	sf::Image particleImage;

	if(!particleImage.LoadFromFile("Debug/particle.png")) {
		return EXIT_FAILURE;
	}

	ParticleSystem particleSystem;

	boost::shared_ptr<SmokeEmitter> rocketSmoke(new SmokeEmitter(100, 200));

	rocketSmoke->AddAffector(AffectorPtr(new FadeOutAffector()));
	//rocketSmoke->AddAffector(AffectorPtr(new RandomColorAffector()));

	rocketSmoke->SetParticleColor(sf::Color(255, 255, 255, 40));

	rocketSmoke->SetTexture(particleImage);
	rocketSmoke->SetMaxParticles(0);
	rocketSmoke->SetEmissionRate(100);
	rocketSmoke->SetTTLRange(10, 30);
	rocketSmoke->Init();

	boost::shared_ptr<SmokeEmitter> rocketFire(new SmokeEmitter((SmokeEmitter&)*rocketSmoke));

	rocketFire->SetEmissionRate(10);
	rocketFire->SetParticleColor(sf::Color::Yellow);
	rocketFire->SetTTLRange(30, 70);
	rocketFire->Init();

	particleSystem.AddEmitter("main_smoke", (EmitterPtr &)rocketSmoke);
	particleSystem.AddEmitter("main_fire", (EmitterPtr &)rocketFire);


	Rocket rocket;
	rocket.SetPosition(center);

	sf::String fps, livingParticles;
	fps.SetPosition(sf::Vector2f(1024 - 100, 50));
	livingParticles.SetPosition(sf::Vector2f(1024 - 250, 100));


	glClearColor(0.f, 0.f, 0.f, 0.f);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	while(window.IsOpened()) {

		sf::Event event;

		while(window.GetEvent(event)) {

			if(event.Type == sf::Event::Closed) {
				window.Close();
		 	}
		}

		if(window.GetInput().IsKeyDown(sf::Key::Left)) {
			rocket.Rotate(100 * window.GetFrameTime());
		}

		if(window.GetInput().IsKeyDown(sf::Key::Right)) {
			rocket.Rotate(-100 * window.GetFrameTime());
		}

		if(window.GetInput().IsKeyDown(sf::Key::Space)) {

			sf::Vector2f direction;

			direction.x = cos(rocket.GetRotation() * M_PI / 180) * 2;
			direction.y = - sin(rocket.GetRotation() * M_PI / 180) * 2;

			rocketFire->SetAngle(180 + rocket.GetRotation());
			rocketSmoke->SetAngle(180 + rocket.GetRotation());

			rocketFire->SetEmissionPoint(rocket.GetPosition());
			rocketSmoke->SetEmissionPoint(rocket.GetPosition() - (direction * 10.f));
			rocketSmoke->Play();
			rocketFire->Play();
			rocket.Move(direction * 100.f * window.GetFrameTime());

		}
		if(window.GetInput().IsKeyDown(sf::Key::Escape)) {
			rocketSmoke->Stop();
			rocketFire->Stop();
		}

		glClear(GL_COLOR_BUFFER_BIT);


		particleSystem.Update(window.GetFrameTime());
		window.Draw(rocket);
		window.Draw(particleSystem);


		// draw infos on screen

		std::stringstream text, text2;

		int framerate = 1/window.GetFrameTime();

		text << framerate << " fps";
		text2 << particleSystem.GetNumLivingParticles() << " alive particles !";

		fps.SetText(text.str());
		livingParticles.SetText(text2.str());

		window.Draw(fps);
		window.Draw(livingParticles);

		window.Display();
	}

	return EXIT_SUCCESS;
}
