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
*    principalmente se encuentran las funciones      *
*	 necesarias para dibujar los objetos	         *
*                                                    *
******************************************************
*/
#include <time.h>
#include "orbitalSimView.h"



void SaveScaledPositions(Vector3* list,OrbitalSim * sim) {
    for (int i = 0; i < sim->bodys; i++)
    {
        list[i] = Vector3Scale(sim->ptoOrbList[i].pos, 1E-11);
    }
}

const char* getISODate(float currentTime) {
    // Epoch: 2022-01-01
    struct tm epoch_tm = { 0, 0, 0, 1, 0, 122 };
    time_t epoch = mktime(&epoch_tm);

    // Convert epoch time to local time
    time_t local_time = epoch + (time_t)currentTime;

    // Print ISO date for local time
    struct tm* local_tm = localtime(&local_time);
    return TextFormat("Date: %04d-%02d-%02d", 1900 + local_tm->tm_year, local_tm->tm_mon + 1, local_tm->tm_mday);
}



void renderOrbitalSim3D(OrbitalSim *sim, int index, Vector3 scaledPos)
{

    DrawSphere(scaledPos, sim->ptoOrbList[index].radius, sim->ptoOrbList[index].color);
    
}

void renderOrbitalSim2D(OrbitalSim *sim, int index, Vector3 scaledPos)
{
        DrawPoint3D(scaledPos, sim->ptoOrbList[index].color);
}


void renderSimulation(OrbitalSim* sim) {
    Vector3 scaledPosition;
    for (int i = 0; i < NBODIES; i++)
    {
        scaledPosition = Vector3Scale(sim->ptoOrbList[i].pos, 1E-11);
        renderOrbitalSim2D(sim, i, scaledPosition);
        renderOrbitalSim3D(sim, i, scaledPosition);
    }
}

//CON ESTE CORRE A 40 FPS LOS 1000 BODIES, PERO LOS ASTEROIDES SON SOLO PUNTOS.
/*
void renderSimulation(OrbitalSim *sim) {
    Vector3 scaledPosition;
    for (int i = 0; i < sim->nEphemirides; i++)
    {
        scaledPosition = Vector3Scale(sim->ptoOrbList[i].pos, 1E-11);
        renderOrbitalSim2D(sim, i, scaledPosition);
        renderOrbitalSim3D(sim, i, scaledPosition);

    } for (int j = sim->nEphemirides; j < NBODIES; j++)
    {
        scaledPosition = Vector3Scale(sim->ptoOrbList[j].pos, 1E-11);
        renderOrbitalSim2D(sim, j, scaledPosition);
    }
}*/


