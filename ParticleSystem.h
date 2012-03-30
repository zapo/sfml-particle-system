/*
 * ParticleSystem.h
 *
 *  Created on: 2011-02-20
 *      Author: zapo
 */

#ifndef PARTICLESYSTEM_H_
#define PARTICLESYSTEM_H_


#include <SFML/Graphics.hpp>
#include "Types.h"

class Emitter;

class ParticleSystem : public sf::Drawable {
public:

	ParticleSystem();

	void Init();
	virtual ~ParticleSystem();

	EmitterPtrList & GetEmitters();

	void AddEmitter(std::string, EmitterPtr &);
	EmitterPtr & GetEmitter(std::string);

	void Update(float);

	long GetNumLivingParticles() const ;

private:

	void Render(sf::RenderTarget &) const;

	EmitterPtrList emitters;
	EmitterPtrList::iterator eit;

};

#endif /* PARTICLESYSTEM_H_ */
