/*
 * Types.h
 *
 *  Created on: 2011-02-22
 *      Author: zapo
 */

#ifndef TYPES_H_
#define TYPES_H_

#include <boost/shared_ptr.hpp>
#include <list>
#include <map>

class Particle;
class Affector;
class Emitter;

typedef boost::shared_ptr<Particle> ParticlePtr;
typedef boost::shared_ptr<Affector> AffectorPtr;
typedef boost::shared_ptr<Emitter> EmitterPtr;

typedef std::list<ParticlePtr> ParticlePtrList;
typedef std::list<AffectorPtr> AffectorPtrList;
typedef std::map<std::string, EmitterPtr> EmitterPtrList;


#endif /* TYPES_H_ */
