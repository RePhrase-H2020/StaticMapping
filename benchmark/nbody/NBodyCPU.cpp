/*
 * NBodyCPU.cpp
 *
 *  Created on: 19 May 2015
 *      Author: vladimirjanjic
 */

#include "nbody.h"
#include "NBodyCPU.h"
#include <math.h>

NBody_CPU::NBody_CPU() {
	// TODO Auto-generated constructor stub

}

NBody_CPU::~NBody_CPU() {
	// TODO Auto-generated destructor stub
}

std::tuple<float, float, float> calculate_acc_vector(particle_t particle, particle_t *particles, unsigned int nr_particles, float dt) {
	float dx, dy, dz, inv, inv2, ax, ay, az;
	for (unsigned int i=0; i<nr_particles; i++) {
		dx = particle.x - particles[i].x;
		dy = particle.y - particles[i].y;
		dz = particle.z - particles[i].z;
		inv = 1 / sqrt(dx*dx+dy*dy+dz*dz+dt);
		inv2 = particle.m*inv*inv*inv;
		ax += dx*inv2;
		ay += dy*inv2;
		az += dz*inv2;
	}
	return std::make_tuple(ax,ay,az);
}
void* NBody_CPU::svc(void* task) {
	task_t *chunk = (task_t *) task;
	int i;
	for (i=0; i<chunk->nr_particles; i++) {
		calculate_acc_vector(chunk->data[i], chunk->all_particles, chunk->nr_particles, chunk->dt);
	}
}
