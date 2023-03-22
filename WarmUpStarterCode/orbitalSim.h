/*
******************************************************
* Orbital Simulation                          		 *
*                                                    *
* 25.03 EDA                                          *
* Copyrigth (C) 2023 Marc. S Ressl                   *
*                                                    *
******************************************************

******************************************************
* Autores:                                           *
*                                                    *
* 	- Aggosti, Santino.          					 *
* 	- Domínguez, Agustín.                            *
*	- López Franceschini, Santiago	                 *
* 	- Sarmiento, Lourdes							 *
*													 *
* Materia:											 *
*	- Estructura de Datos y Algoritmos				 *
*													 *
******************************************************

******************************************************
* Descripción:                                       *
*                                                    *
*  se definen los planetas y las estructuras con     *
*  datos importantes			                     *
*                                                    *
******************************************************
*/


#ifndef ORBITALSIM_H
#define ORBITALSIM_H

#include "C:\dev\vcpkg\packages\raylib_x64-windows\include\raylib.h"
#include "C:\dev\vcpkg\packages\raylib_x64-windows\include\raymath.h"
#include <stdio.h>

#define GRAVITATIONAL_CONSTANT 6.6743E-11F
#define ASTEROIDS_MEAN_RADIUS 4E11F
#define NBODIES 10000

#define SOLARSYSTEM_BODYNUM (sizeof(solSystem) / sizeof(OrbitalBody))
#define ALPHACENTAURISYSTEM_BODYNUM (sizeof(alphCentauriSystem) / sizeof(OrbitalBody))

struct OrbitalBody
{
    float mass;		  // Masa en Kg
    float radius;	  // radio en metros
    Color color;	  // Color
    Vector3 pos;      // Posición (x,y,z) en metros
    Vector3 vel;      // Velocidad (Vx,Vy,Vz) en metros por segundo
    Vector3 acc;      // Aceleración actual del cuerpo

};

struct OrbitalSim
{
   float time_step;
   float time_total;
   int bodys;
   OrbitalBody * ptoOrbList; 
   char* date;
   int nEphemirides;    //Añadido para simplificacion de codigo
};

OrbitalSim *makeOrbitalSim(float timeStep);
void updateOrbitalSim(OrbitalSim *sim);
void freeOrbitalSim(OrbitalSim *sim);
void placeAsteroid(OrbitalBody* body, float centerMass);

void fillOrbBodiesList(OrbitalSim* sim, OrbitalBody* ephList);
float getMostMassiveBody(OrbitalSim* sim);
float scaleRadius(float radius);

//Vectorial Calculations
void calcValues(OrbitalSim* sim);
Vector3 calcAij(OrbitalBody body_1, OrbitalBody body_2, float distance);
void calcVel(OrbitalSim* sim, int index);
void calcPosition(OrbitalSim* sim, int index);

#endif