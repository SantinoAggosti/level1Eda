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
*    MAIN                                            *
*													 *
******************************************************
*/

#include "orbitalSim.h"
#include "orbitalSimView.h"


#define SECONDS_PER_DAY 86400.0F

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "EDA Orbital Simulation");

    Camera3D camera;

    camera.position = {10.0f, 10.0f, 10.0f};

    camera.target = {0.0f, 0.0f, 0.0f};

    camera.up = {0.0f, 1.0f, 0.0f};

    camera.fovy = 45.0f;

    camera.projection = CAMERA_PERSPECTIVE;

    SetCameraMode(camera, CAMERA_FREE);

    SetCameraPanControl(MOUSE_BUTTON_LEFT);

    float fps = 60;							  
    float timeMultiplier = 65 * SECONDS_PER_DAY; 
    float timeStep = timeMultiplier / fps;

    OrbitalSim *simulation = makeOrbitalSim(timeStep);

    while (!WindowShouldClose())
    {
        updateOrbitalSim(simulation);   

        UpdateCamera(&camera);   

        BeginDrawing();    

        ClearBackground(BLACK);

        DrawText(getISODate(simulation->time_total), 10, 40, 30, WHITE);

        DrawFPS(10,10);

        BeginMode3D(camera);     
        
        DrawGrid(10, 10.0f);

        renderSimulation(simulation);
        
        EndMode3D();             

        EndDrawing();            
    }

    CloseWindow();              

    freeOrbitalSim(simulation);        

    return 0;
}
    