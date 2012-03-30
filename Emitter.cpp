/*
 * Emitter.cpp
 *
 *  Created on: 2011-02-20
 *      Author: zapo
 */

#include <iostream>
#include "Emitter.h"
#include "VectorUtils.h"
#include "Types.h"
#include "Particle.h"
#include "Affector.h"

Emitter::Emitter(const sf::Shape & shape) : sf::Shape(shape), maxParticles(0) {
	// TODO Auto-generated constructor stub

}

Emitter::Emitter(const Emitter & emitter) {

	maxParticles = emitter.maxParticles;
	affectors = emitter.affectors;
	angle = emitter.angle;
	emissionPoint = emitter.emissionPoint;
	emissionRate = emitter.emissionRate;
	texture = emitter.texture;

}

Emitter::~Emitter() {
	// TODO Auto-generated destructor stub
}

void Emitter::Init() {

	if(maxParticles <= 0) return;

	for(int i = 0; i < maxParticles; i++) {

		ParticlePtr particlePtr(new Particle());
		particles.push_back(particlePtr);

	}
}



void Emitter::Render(sf::RenderTarget & target ) const {

	ParticlePtrList::const_iterator pit = emittedParticles.begin();

	if(texture) {
		texture->Bind();
	}

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	sf::FloatRect texCoords = texture->GetTexCoords(sf::IntRect(0, 0, texture->GetWidth(), texture->GetHeight()));
	sf::Vector2f halfSize = sf::Vector2f(texture->GetWidth() / 2.f, texture->GetHeight() / 2.f);

	for(; pit != emittedParticles.end(); pit++) {

		const ParticlePtr & particle = *pit;

		const sf::Color & color = particle->GetColor();

		glPushMatrix();
		glTranslatef(particle->GetPosition().x, particle->GetPosition().y, 0);
		glRotatef(particle->GetRotation(),0,0,1);
		glScalef(particle->GetScale().x, particle->GetScale().y, 0);
		glColor4ub(color.r, color.g, color.b, color.a);
		glBegin(GL_QUADS);
			glTexCoord2f(texCoords.Left,  texCoords.Top);	glVertex2f(-halfSize.x, -halfSize.y);
			glTexCoord2f(texCoords.Left,  texCoords.Bottom);	glVertex2f(-halfSize.x, halfSize.y);
			glTexCoord2f(texCoords.Right, texCoords.Bottom);	glVertex2f(halfSize.x,	halfSize.y);
			glTexCoord2f(texCoords.Right, texCoords.Top);	glVertex2f(halfSize.x,	-halfSize.y);
		glEnd();
		glColor4ub(255, 255, 255, 255);
		glPopMatrix();

	}

	target.Draw(sf::Shape(*this));
}

void Emitter::Update(float dt) {

	if(emittedParticles.empty()) return;

	ParticlePtrList::iterator pit = emittedParticles.begin();


	for(; pit != emittedParticles.end(); pit++) {

		ParticlePtr & particle = *pit;

		particle->DecrementTTL();

		if(!affectors.empty()) {

			AffectorPtrList::iterator ait = affectors.begin();

			for(; ait != affectors.end(); ait++) {
				Affector & affector = **ait;
				affector.Update(particle, dt);
			}
		}

		if(particle->IsAlive()) {

			UpdateParticle(particle, dt);

		} else {
			pit = emittedParticles.erase(pit);
		}

	}
}



void Emitter::AddAffector(const AffectorPtr & affector) {
	affectors.push_back(affector);
}

void Emitter::RemoveAffector(AffectorPtr & affector) {

	AffectorPtrList::iterator it = std::find(affectors.begin(), affectors.end(), affector);

	if(it != affectors.end()) {
		affectors.erase(it);
	}

}

void Emitter::SetTexture(const sf::Image & image) {
	texture = &image;
}

const sf::Image & Emitter::GetTexture() {
	return *texture;
}

void Emitter::SetMaxParticles(int num) {
	maxParticles = num;
}

void Emitter::Play() {

	if(particles.empty() && maxParticles > 0) return;

	for(int i = 0; i < emissionRate && (!particles.empty() || maxParticles == 0); i++) {

		ParticlePtr particle;

		if(maxParticles > 0) {

			particle = particles.front();
			particles.pop_front();

		} else {
			particle = ParticlePtr(new Particle());
		}

		InitParticle(particle);
		emittedParticles.push_front(particle);
		particle->SetIsVisible(true);
	}

}


void Emitter::Stop() {

	emittedParticles.clear();

}


void Emitter::SetEmissionPoint(const sf::Vector2f & point) {
	emissionPoint = point;
}

void Emitter::SetAngle(float angle) {
	this->angle = angle;
}

sf::Vector2f Emitter::GetDirection() {

	sf::Vector2f direction;
	direction.x = cos(angle * M_PI / 180);
	direction.y = -sin(angle * M_PI / 180);

	return direction;

}

void Emitter::SetEmissionRate(int num) {
	emissionRate = num;
}

ParticlePtrList Emitter::GetLivingParticles() const {
	return emittedParticles;
}
