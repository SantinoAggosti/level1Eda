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
*    TEST                                            *
*													 *
******************************************************
*/

#include <iostream>

#include "orbitalSim.h"

#define SECONDS_PER_DAY 86400.0F

using namespace std;

int main()
{
    float fps = 60.0F;                            
    float timeMultiplier = 100 * SECONDS_PER_DAY; 
    float timeStep = timeMultiplier / fps;

    OrbitalSim *sim = makeOrbitalSim(timeStep);

    updateOrbitalSim(sim);

    return 0;
}
