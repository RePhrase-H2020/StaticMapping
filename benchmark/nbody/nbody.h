/*
 * nbody.h
 *
 *  Created on: 19 May 2015
 *      Author: vladimirjanjic
 */

#ifndef NBODY_NBODY_H_
#define NBODY_NBODY_H_

typedef struct {
	particle_t *data;
	unsigned int nr_particles;
	particle_t *all_particles;
	float dt;
} task_t;

typedef struct {
	float x;
	float y;
	float z;
	float m;
	float vx;
	float vy;
	float vz;
} particle_t;


#endif /* NBODY_NBODY_H_ */
