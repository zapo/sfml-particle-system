/*
 * FadeOutAffector.cpp
 *
 *  Created on: 2011-02-21
 *      Author: zapo
 */

#include "FadeOutAffector.h"
#include "Particle.h"
#include <iostream>

FadeOutAffector::FadeOutAffector() {
	// TODO Auto-generated constructor stub

}

FadeOutAffector::~FadeOutAffector() {
	// TODO Auto-generated destructor stub
}

void FadeOutAffector::Update(ParticlePtr & particle, float dt) {

	sf::Color color = particle->GetColor();

	if(color.a > particle->GetTTL()) {
		color.a = particle->GetTTL();

	}

	particle->SetColor(color);


}
