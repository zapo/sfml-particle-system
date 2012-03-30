/*
 * SmokeEmitter.h
 *
 *  Created on: 2011-02-22
 *      Author: zapo
 */

#ifndef SMOKEEMITTER_H_
#define SMOKEEMITTER_H_

#include "Emitter.h"
#include "Types.h"

class SmokeEmitter: public Emitter {
public:
	SmokeEmitter(int, int);
	virtual ~SmokeEmitter();

	void UpdateParticle(ParticlePtr &, float) const ;
	void InitParticle(ParticlePtr &) const ;

	void SetParticleColor(const sf::Color &);
	void SetTTLRange(int, int);
private:
	sf::Color particleColor;
	int maxTTL;
	int minTTL;
};

#endif /* SMOKEEMITTER_H_ */
