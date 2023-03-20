/*
 * Orbital simulation view
 *
 * 25.03 EDA
 * Copyright (C) 2023 Marc S. Ressl
 */

#ifndef ORBITALSIMVIEW_H
#define ORBITALSIMVIEW_H

#include "orbitalSim.h"

void SaveScaledPositions(Vector3* list, OrbitalSim* sim);
void renderOrbitalSim3D(OrbitalSim *sim,int index, Vector3 pos);
void renderOrbitalSim2D(OrbitalSim *sim, int index, Vector3 pos);
void renderSimulation(OrbitalSim* sim);
const char* getISODate(float currentTime);

#endif
