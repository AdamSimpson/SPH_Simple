#ifndef fluid_fluid_h
#define fluid_fluid_h

typedef struct DOUBLE3 double3;
typedef struct BOUNDARY_PARTICLE boundary_particle;
typedef struct FLUID_PARTICLE fluid_particle;
typedef struct NEIGHBOR neighbor;
typedef struct PARAM param;

#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "fileio.h"
#include "geometry.h"

////////////////////////////////////////////////
// Structures
////////////////////////////////////////////////

struct DOUBLE3 {
    double x;
    double y;
    double z;
};

struct BOUNDARY_PARTICLE {
    double3 pos; // position
    double3 n;   // position
};

struct FLUID_PARTICLE {
    double density;
    double pressure;
    double3 pos;     // position
    double3 v;       // velocity
    double3 v_half;  // half step velocity
    double3 a;       // acceleration
};

struct PARAM {
    double rest_density;
    double mass_particle;
    double spacing_particle;
    double smoothing_radius;
    double g;
    double time_step;
    double alpha;
    double surface_tension;
    double speed_sound;
    int number_particles;
    int number_fluid_particles;
    int number_boundary_particles;
    int number_steps;
}; // Simulation paramaters

////////////////////////////////////////////////
// Function prototypes
////////////////////////////////////////////////

//double W(fluid_particle *p, fluid_particle *q, double h);
//double del_W(fluid_particle *p, fluid_particle *q, double h);
//double computePressure(fluid_particle *p, param *params);
//void updatePressures(fluid_particle *fluid_particles, param *params);
//void computeAcceleration(fluid_particle *p, fluid_particle *q, param *params);
//void computeBoundaryAcceleration(fluid_particle *p, boundary_particle *q, param *params);
//void updateParticle(fluid_particle *p, param *params);
//void updatePositions(fluid_particle *fluid_particles, param *params);
void updatePositions(fluid_particle *fluid_particles, param *params);
void updatePressures(fluid_particle *fluid_particles, param *params);
void updateAccelerations(fluid_particle *fluid_particles, boundary_particle *boundary_particles, param *params);
double computeDensity(double3 p_pos, double3 p_v, double3 q_pos, double3 q_v, param *params);
void eulerStart(fluid_particle* fluid_particles, boundary_particle *boundary_particles, param *params);
void initParticles(fluid_particle* fluid_particles, boundary_particle* boundary_particles, AABB* water, AABB* boundary, param* params);

#endif
