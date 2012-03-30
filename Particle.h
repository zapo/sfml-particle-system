/*
 * Particle.h
 *
 *  Created on: 2011-02-17
 *      Author: zapo
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <SFML/Graphics.hpp>

class Particle : public sf::Drawable {
public:


	Particle();
	virtual ~Particle();

	float GetVelocity() const;
	void SetVelocity(float);

	void SetIsVisible(bool);
	bool GetIsVisible() const;

	bool IsAlive();
	void DecrementTTL(int num = 1);
	int GetTTL() const;
	void SetTTL(int);

	sf::Vector2f GetDirection() const;

	void Render(sf::RenderTarget &) const;

private:

	bool isVisible;
	float alpha;

	float velocity;
	int TTL;

};

#endif /* PARTICLE_H_ */
