/*
 * Orbital simulation
 *
 * 25.03 EDA
 * Copyright (C) 2023 Marc S. Ressl
 */


#ifndef ORBITALSIM_H
#define ORBITALSIM_H

#include "C:\dev\vcpkg\packages\raylib_x64-windows\include\raylib.h"
#include "C:\dev\vcpkg\packages\raylib_x64-windows\include\raymath.h"

struct OrbitalBody
{
    const char *name; // Nombre
    float mass;		  // Masa en Kg
    float radius;	  // radio en metros
    Color color;	  // Color
    Vector3 pos;      // Posición (x,y,z) en metros
    Vector3 vel;      // Velocidad (Vx,Vy,Vz) en metros por segundo
    Vector3 force;    // Fuerza ejercida sobre el cuerpo
    Vector3 acc;      // Aceleración actual del cuerpo

};

struct OrbitalSim
{
   float time_step ;
   float time_total;
   int bodys;
   OrbitalBody * ptoOrbList; 

};

OrbitalSim *makeOrbitalSim(float timeStep);
void updateOrbitalSim(OrbitalSim *sim);
void freeOrbitalSim(OrbitalSim *sim);
void placeAsteroid(OrbitalBody* body, float centerMass);
int searchIndex (OrbitalBody** list);

void fillOrbBodiesList(OrbitalSim* sim, OrbitalBody* ephList, int nEphemerides);
float getMostMassiveBody(OrbitalSim* sim, int nEphemerides);
float scaleRadius(float radius);

//Vectorial Calculations
void calcAcc(OrbitalSim* sim);
Vector3 calcAij(OrbitalBody body_1, OrbitalBody body_2);
void calcVel(OrbitalSim* sim);
void calcPosition(OrbitalSim* sim);

#endif
