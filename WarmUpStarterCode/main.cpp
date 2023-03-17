/*
 * Orbital simulation
 *
 * 25.03 EDA
 * Copyright (C) 2023 Marc S. Ressl
 *
 * Main module
 */

#include "orbitalSim.h"
#include "orbitalSimView.h"

#define SECONDS_PER_DAY 86400.0F

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "EDA Orbital Simulation");

    // Camera
    Camera3D camera;
    camera.position = {10.0f, 10.0f, 10.0f};
    camera.target = {0.0f, 0.0f, 0.0f};
    camera.up = {0.0f, 1.0f, 0.0f};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    SetCameraMode(camera, CAMERA_FREE);

    SetCameraPanControl(MOUSE_BUTTON_LEFT);

    // Orbital simulation
    float fps = 60;							  // frames per second
    float timeMultiplier = 5 * SECONDS_PER_DAY; // Simulation speed: 100 days per real second
    float timeStep = timeMultiplier / fps;

    OrbitalSim *simulation = makeOrbitalSim(timeStep);




    // Game loop
    while (!WindowShouldClose())
    {
        // Update simulation
        updateOrbitalSim(simulation);   //Nuestro

        // Camera
        UpdateCamera(&camera);   //Biblioteca

        // Render
        BeginDrawing();          //Biblioteca
        ClearBackground(BLACK);  //Biblioteca

        BeginMode3D(camera);     //Biblioteca
        //renderOrbitalSim3D(sim); //Nuestro
        
        DrawGrid(10, 10.0f);

        renderSimulation(simulation);
        

        EndMode3D();             //Biblioteca

        EndDrawing();            //Biblioteca
    }

    CloseWindow();              //Biblioteca

    freeOrbitalSim(simulation);        //Nuestro

    return 0;
}
    