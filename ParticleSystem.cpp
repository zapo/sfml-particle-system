/*
 * ParticleSystem.cpp
 *
 *  Created on: 2011-02-20
 *      Author: zapo
 */

#include "ParticleSystem.h"
#include "Emitter.h"

ParticleSystem::ParticleSystem() {
	// TODO Auto-generated constructor stub

}

ParticleSystem::~ParticleSystem() {
	// TODO Auto-generated destructor stub
}

EmitterPtrList & ParticleSystem::GetEmitters() {
	return emitters;
}

void ParticleSystem::Init() {
}



void ParticleSystem::AddEmitter(std::string name, EmitterPtr & emitter) {

	emitters[name] = emitter;

}

EmitterPtr & ParticleSystem::GetEmitter(std::string name) {
	return emitters[name];
}

void ParticleSystem::Update(float dt) {

	eit = emitters.begin();

	for(; eit != emitters.end(); eit++) {

		Emitter & emitter = *(eit->second);
		emitter.Update(dt);

	}

}

long ParticleSystem::GetNumLivingParticles() const {

	EmitterPtrList::const_iterator it = emitters.begin();
	long count = 0;

	for(; it != emitters.end(); it++) {

		count += (it->second)->GetLivingParticles().size();

	}
	return count;
}

void ParticleSystem::Render(sf::RenderTarget & target) const {

	EmitterPtrList::const_iterator eit = emitters.begin();

	for(; eit != emitters.end(); eit++) {

		Emitter & emitter = *(eit->second);
		target.Draw(emitter);
	}

}
