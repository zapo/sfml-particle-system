/*
 * RandomColorAffector.cpp
 *
 *  Created on: 2011-02-23
 *      Author: zapo
 */

#include "RandomColorAffector.h"
#include <SFML/Graphics.hpp>
#include "Particle.h"

RandomColorAffector::RandomColorAffector() {
	// TODO Auto-generated constructor stub

}

RandomColorAffector::~RandomColorAffector() {
	// TODO Auto-generated destructor stub
}

void RandomColorAffector::Update(ParticlePtr & particle, float dt) {

	sf::Color color = particle->GetColor();

	color.r = sf::Randomizer::Random(0, 255);
	color.g = sf::Randomizer::Random(0, 255);
	color.b = sf::Randomizer::Random(0, 255);

	particle->SetColor(color);

}
