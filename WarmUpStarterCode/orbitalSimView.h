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
*/

#ifndef ORBITALSIMVIEW_H
#define ORBITALSIMVIEW_H

#include "orbitalSim.h"

void renderOrbitalSim3D(OrbitalSim *sim,int index, Vector3 pos);
void renderOrbitalSim2D(OrbitalSim *sim, int index, Vector3 pos);
void renderSimulation(OrbitalSim* sim);
const char* getISODate(float currentTime);

#endif
