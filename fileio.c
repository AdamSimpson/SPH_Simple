////////////////////////////////////////////////
// File input/output functions
////////////////////////////////////////////////

#include <stdio.h>
#include "fileio.h"
#include "fluid.h"

// Write fluid particle data to file
void writeFile(fluid_particle *particles, int fileNum, param *params)
{
    fluid_particle *p;
    FILE *fp ;
    int i;
    char name[64];
    char* user;
    user = getenv ("USER");
    sprintf(name, "/tmp/work/%s/sim-%d.csv", user, fileNum);
    fp = fopen (name,"w");
    if (!fp) {
        printf("ERROR: error opening file\n");
        exit(1);
    }
    for(i=0; i<params->number_fluid_particles; i++) {
        p = &particles[i];
        fprintf(fp,"%f,%f,%f\n",p->pos.x,p->pos.y,p->pos.z);
    }
    fclose(fp);
    printf("wrote file: %s\n", name);
}

// Write boundary particle data to file
void writeBoundaryFile(boundary_particle *boundary, param *params)
{
    boundary_particle *k;
    FILE *fp ;
    int i;
    char* user;
    user = getenv ("USER");
    char name[64];
    sprintf(name, "/tmp/work/%s/boundary.csv", user);
    fp = fopen ( name,"w" );
    if (!fp) {
        printf("ERROR: error opening file\n");
        exit(1);
    }
    for(i=0; i<params->number_boundary_particles; i++) {
        k = &boundary[i];
        fprintf(fp,"%f,%f,%f\n",k->pos.x,k->pos.y,k->pos.z);
    }
    fclose(fp);
    printf("wrote file: %s\n", name);
}
