/*
 * FadeOutAffector.h
 *
 *  Created on: 2011-02-21
 *      Author: zapo
 */

#ifndef FADEOUTAFFECTOR_H_
#define FADEOUTAFFECTOR_H_

#include "Affector.h"
#include "Types.h"

class FadeOutAffector: public Affector {
public:
	FadeOutAffector();
	virtual ~FadeOutAffector();
	virtual void Update(ParticlePtr &, float);
};

#endif /* FADEOUTAFFECTOR_H_ */
