/*
 * Particle.cpp
 *
 *  Created on: 2011-02-17
 *      Author: zapo
 */

#include "Particle.h"
#include <iostream>


Particle::Particle() {

	isVisible = false;
}

Particle::~Particle() {
}

float Particle::GetVelocity() const {
	return velocity;
}

void Particle::SetVelocity(float velocity) {
	this->velocity = velocity;
}

void Particle::SetIsVisible(bool visible) {
	isVisible = visible;
}

bool Particle::GetIsVisible() const {
	return isVisible;
}

void Particle::Render(sf::RenderTarget &) const {

}

sf::Vector2f Particle::GetDirection() const {
	sf::Vector2f direction;

	direction.x = cos(GetRotation() * M_PI / 180);
	direction.y = -sin(GetRotation() * M_PI / 180);

	return direction;
}

bool Particle::IsAlive() {
	return TTL > 0;
}

int Particle::GetTTL() const {
	return TTL;
}

void Particle::DecrementTTL(int num) {
	TTL -= num;
}

void Particle::SetTTL(int TTL) {
	this->TTL = TTL;
}


