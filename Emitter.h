/*
 * Emitter.h
 *
 *  Created on: 2011-02-20
 *      Author: zapo
 */

#ifndef EMITTER_H_
#define EMITTER_H_

#include <SFML/Graphics.hpp>
#include "Types.h"


class Emitter : public sf::Shape {
public:

	Emitter(const Emitter & emitter);
	Emitter(const sf::Shape &);
	virtual ~Emitter();

	void AddAffector(const AffectorPtr &);
	void RemoveAffector(AffectorPtr &);

	void Update(float );

	void SetTexture(const sf::Image &);
	const sf::Image & GetTexture();

	void SetMaxParticles(int);
	sf::Vector2f GetDirection();

	void SetAngle(float );

	void SetEmissionRate(int);

	void Init();

	virtual void UpdateParticle(ParticlePtr &, float) const = 0;
	virtual void InitParticle(ParticlePtr &) const = 0;

	void Play();
	void Stop();

	void SetEmissionPoint(const sf::Vector2f &);

	ParticlePtrList GetLivingParticles() const;

protected :

	void Render(sf::RenderTarget &) const;

	float angle;
	sf::Vector2f emissionPoint;
	int emissionRate;

	ParticlePtrList particles;
	ParticlePtrList emittedParticles;
	AffectorPtrList affectors;

	const sf::Image * texture;



	long maxParticles;

};

#endif /* EMITTER_H_ */
