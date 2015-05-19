/*
 * NBodyCPU.h
 *
 *  Created on: 19 May 2015
 *      Author: vladimirjanjic
 */

#ifndef NBODY_NBODYCPU_H_
#define NBODY_NBODYCPU_H_

#include<node.hpp>;

using namespace ff;

class NBody_CPU: public ff_node {
public:
	NBody_CPU();
	virtual ~NBody_CPU();
	void *svc(void*);
};

#endif /* NBODY_NBODYCPU_H_ */
