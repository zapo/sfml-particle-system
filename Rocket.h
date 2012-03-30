/*
 * Rocket.h
 *
 *  Created on: 2011-02-20
 *      Author: zapo
 */

#ifndef ROCKET_H_
#define ROCKET_H_

#include <SFML/Graphics.hpp>
#include "ParticleSystem.h"
#include "Types.h"

class Rocket : public sf::Drawable {
public:

	Rocket();
	virtual ~Rocket();

	sf::Vector2f GetDirection();

private:

	sf::Shape shape;
	virtual void Render(sf::RenderTarget &) const;

};

#endif /* ROCKET_H_ */
