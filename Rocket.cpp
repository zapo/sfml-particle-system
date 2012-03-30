/*
 * Rocket.cpp
 *
 *  Created on: 2011-02-20
 *      Author: zapo
 */

#include "Rocket.h"
#include "SmokeEmitter.h"
#include "FadeOutAffector.h"
#include <iostream>


Rocket::Rocket() {
	shape = sf::Shape(sf::Shape::Line(sf::Vector2f(0, 0), sf::Vector2f(50, 0), 3, sf::Color(255, 0, 0)));

}

Rocket::~Rocket() {
	// TODO Auto-generated destructor stub
}

void Rocket::Render(sf::RenderTarget & target) const {
	target.Draw(shape);
}

sf::Vector2f Rocket::GetDirection() {

	sf::Vector2f direction;

	direction.x = cos(GetRotation() * M_PI / 180);
	direction.y = - sin(GetRotation() * M_PI / 180);

	return direction;

}
