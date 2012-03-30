/*
 * Affector.h
 *
 *  Created on: 2011-02-20
 *      Author: zapo
 */

#ifndef AFFECTOR_H_
#define AFFECTOR_H_

#include <list>
#include <boost/shared_ptr.hpp>
#include "Types.h"

class Affector {
public:
	Affector();
	virtual ~Affector();

	virtual void Update(ParticlePtr &, float) = 0;

};

#endif /* AFFECTOR_H_ */
