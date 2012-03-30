/*
 * SmokeEmitter.cpp
 *
 *  Created on: 2011-02-22
 *      Author: zapo
 */

#include "SmokeEmitter.h"
#include "VectorUtils.h"
#include "Particle.h"
#include <iostream>

SmokeEmitter::SmokeEmitter(int minTTL, int maxTTL) :
	Emitter(sf::Shape()),
	particleColor(sf::Color::White),
	maxTTL(maxTTL),
	minTTL(minTTL) {

}

SmokeEmitter::~SmokeEmitter() {
	// TODO Auto-generated destructor stub
}

void SmokeEmitter::UpdateParticle(ParticlePtr & particle, float dt) const {

	particle->SetRotation(sf::Randomizer::Random(particle->GetRotation() - 3, particle->GetRotation() + 3));
	particle->Move(particle->GetDirection() * particle->GetVelocity() * dt);

}

void SmokeEmitter::InitParticle(ParticlePtr & particle) const {

	particle->SetVelocity(sf::Randomizer::Random(100.f, 400.f));


	particle->SetColor(particleColor);

	particle->SetPosition(emissionPoint);
	particle->SetRotation(angle);

	particle->SetTTL(sf::Randomizer::Random(minTTL, maxTTL));



}

void SmokeEmitter::SetParticleColor(const sf::Color & color) {
	particleColor = color;
}

void SmokeEmitter::SetTTLRange(int min, int max) {
	minTTL = min;
	maxTTL = max;
}

