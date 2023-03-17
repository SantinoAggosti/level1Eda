/*
 * Orbital simulation view
 *
 * 25.03 EDA
 * Copyright (C) 2023 Marc S. Ressl
 */

#include <time.h>
#include "orbitalSimView.h"
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


void renderOrbitalSim3D(OrbitalSim *sim, int index)
{
    
    DrawSphere(Vector3Scale(sim->ptoOrbList[index].pos, 0.00000000001), sim->ptoOrbList[index].radius, sim->ptoOrbList[index].color);
    
}

void renderOrbitalSim2D(OrbitalSim *sim, int index)
{
        DrawPoint3D(Vector3Scale(sim->ptoOrbList[index].pos, 0.00000000001), sim->ptoOrbList[index].color);
    }

void renderSimulation(OrbitalSim *sim) {
    for (int i = 0; i < sim->bodys; i++)
    {
        renderOrbitalSim2D(sim, i);
        renderOrbitalSim3D(sim, i);
    }
}

