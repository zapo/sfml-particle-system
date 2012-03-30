/*
 * RandomColorAffector.h
 *
 *  Created on: 2011-02-23
 *      Author: zapo
 */

#ifndef RANDOMCOLORAFFECTOR_H_
#define RANDOMCOLORAFFECTOR_H_

#include "Types.h"
#include "Affector.h"

class RandomColorAffector : public Affector {
public:
	RandomColorAffector();
	virtual ~RandomColorAffector();
	virtual void Update(ParticlePtr &, float);
};

#endif /* RANDOMCOLORAFFECTOR_H_ */
