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
*    Realiza los calculos necesarios y los reemplaza *
*	 en cada estructura								 *
*                                                    *
******************************************************

*************************************************************************
* Respuesta a "Pasos Siguientes: Ítem 3":                               *
*                                                                       *
*    Por un lado decidimos dibujar a los asteroides como puntos en      *
*  lugar de hacerlo como esferas, ya que compurtacionalmente esta forma *
*  es más barato. Por otro lado mejoramos el cálculo de la aceleración: *
*  simplificamos el cáculo de la aceleración del cuerpo i con respecto  *
*  a las fuerzas del cuerpo i,                                          *
*                                                                       *
*   La complejidad de la simulación es O ( n^2 )                        *
*                                                                       *
*************************************************************************
*/

#define _USE_MATH_DEFINES

#include <stdlib.h>
#include <math.h>

#include "orbitalSim.h"
#include <stdio.h>


OrbitalBody solSystem[] = {
    {
        1988500E24F,
        695700E3F,
        GOLD,
        {-1.283674643550172E+09F, 2.589397504295033E+07F, 5.007104996950605E+08F},
        {-5.809369653802155E-00F, 2.513455442031695E-01F, -1.461959576560110E+01F},
        0
    },
    {
        0.3302E24F,
        2440E3F,
        GRAY,
        {5.242617205495467E+10F, -5.398976570474024E+09F, -5.596063357617276E+09F},
        {-3.931719860392732E+03F, 4.493726800433638E+03F, 5.056613955108243E+04F},
        0
    },
    {
        4.8685E24F,
        6051.84E3F,
        BEIGE,
        {-1.143612889654620E+10F, 2.081921801192194E+09F, 1.076180391552140E+11F},
        {-3.498958532524220E+04F, 1.971012081662609E+03F, -3.509011592387367E+03F},
        0
    },
    {
        5.97219E24F,
        6371.01E3F,
        BLUE,
        {-2.741147560901964E+10F, 1.907499306293577E+07F, 1.452697499646169E+11F},
        {-2.981801522121922E+04F, 1.781036907294364E00F, -5.415519940416356E+03F},
        0
    },
    {
        0.64171E24F,
        3389.92E3F,
        RED,
        {-1.309510737126251E+11F, -7.714450109843910E+08F, -1.893127398896606E+11F},
        {2.090994471204196E+04F, -7.557181497936503E02F, -1.160503586188451E+04F},
        0
    },
    {
        1898.18722E24F,
        69911E3F,
        BEIGE,
        {6.955554713494443E+11F, -1.444959769995748E+10F, -2.679620040967891E+11F},
        {4.539612624165795E+03F, -1.547160200183022E+02F, 1.280513202430234E+04F},
        0
    },
    {
        568.34E24F,
        58232E3F,
        LIGHTGRAY,
        {1.039929189378534E+12F, -2.303100000185490E+10F, -1.056650101932204E+12F},
        {6.345150006906061E+03F, -3.704447055166629E+02F, 6.756117358248296E+03F},
        0
    },
    {
        86.813E24F,
        25362E3F,
        SKYBLUE,
        {2.152570437700128E+12F, -2.039611192913723E+10F, 2.016888245555490E+12F},
        {-4.705853565766252E+03F, 7.821724397220797E+01F, 4.652144641704226E+03F},
        0
    },
    {
        102.409E24F,
        24624E3F,
        DARKBLUE,
        {4.431790029686977E+12F, -8.954348456482631E+10F, -6.114486878028781E+11F},
        {7.066237951457524E+02F, -1.271365751559108E+02F, 5.417076605926207E+03F},
        0
    },
};

OrbitalBody alphCentauriSystem[] = {
    {
        2167000E24F,
        834840.F,
        YELLOW,
        {7.76412948E+11F, 0, 0},
        {0, 0, 7.120E+03F},
    },
    {
        1789000E24F,
        626130.F,
        GOLD,
        {-9.20026904E+11F, 0, 0},
        {0, 0, -8.430E03F},
    },
};

float getRandomFloat(float min, float max)
{
    return min + (max - min) * rand() / (float)RAND_MAX;
}

OrbitalSim* makeOrbitalSim(float timeStep)      //Recibe el valor del timestep y devuelve la inicialización de la simulación
{

    OrbitalSim* sim; 

    sim = ( OrbitalSim* ) malloc( sizeof ( OrbitalSim ));
    sim->time_total = 0;                         
    sim->time_step = timeStep;                   
    sim->bodys = NBODIES;                        //Setea la cantidad de cuerpos totales (Incluyendo Asteroides)
    sim->nEphemirides = SOLARSYSTEM_BODYNUM;     

    OrbitalBody * list;
    list = (OrbitalBody*)malloc(NBODIES * sizeof(OrbitalBody)); 
    sim->ptoOrbList = list;

    fillOrbBodiesList(sim, solSystem);

    return sim;
}

void fillOrbBodiesList(OrbitalSim *sim, OrbitalBody * ephList) {  //Llena la lista de los Orbitals Bodys en la simulación
    for (int i = 0; i < sim->nEphemirides; i++)      //Setea los planetas
    {
        sim->ptoOrbList[i] = ephList[i];
        sim->ptoOrbList[i].radius = scaleRadius(sim->ptoOrbList[i].radius);

    }
    float maxMass = getMostMassiveBody(sim);  

    for (int i = sim->nEphemirides; i < NBODIES; i++)    //Setea los asteroides
    {
        placeAsteroid(&(sim->ptoOrbList[i]), maxMass);
        sim->ptoOrbList[i].radius = scaleRadius(sim->ptoOrbList[i].radius);
    }
}

// Esta Funcion asume que el cuerpo mas pesado se encontrara dentro de los cuerpos de ephemirides y no 
// Entre los demas asteroides por ejemplo.
float getMostMassiveBody(OrbitalSim *sim)     
{
    float maxMass = 0;
    for (int i = 0; i < sim->nEphemirides; i++)
    {
        if (sim->ptoOrbList[i].mass > maxMass) {
            maxMass = sim->ptoOrbList[i].mass;
        }
    }
    return maxMass;
}

void placeAsteroid(OrbitalBody* body, float centerMass)
{
    float x = getRandomFloat(0, 1);
    float l = logf(x) - logf(1 - x) + 1;

    // https://mathworld.wolfram.com/DiskPointPicking.html
    float r = ASTEROIDS_MEAN_RADIUS * sqrtf(fabsf(l));
    //float phi = getRandomFloat(0, 2 * M_PI);
    float phi = 0;

    // https://en.wikipedia.org/wiki/Circular_orbit#Velocity
    float v = sqrtf(GRAVITATIONAL_CONSTANT * centerMass / r) * getRandomFloat(0.6F, 1.2F);
    float vy = getRandomFloat(-1E2F, 1E2F);

    
     body->mass = 1E12F;  
     body->radius = scaleRadius(2E3F); 
     body->color = GREEN;
     body->pos = {r * cosf(phi), 0, r * sinf(phi)};
     body->vel = {-v * sinf(phi), vy, v * cosf(phi)};
}


void calcValues(OrbitalSim* sim) {
    Vector3 Aji;
    Vector3 Aij;
    float distance;

    for (int i = 0; i < NBODIES; i++)
    {
        sim->ptoOrbList[i].acc = Vector3Zero();
    }


    for (int i = 0; i < NBODIES; i++)
    {
        if (i < SOLARSYSTEM_BODYNUM) {
            for (int j = i + 1; j < NBODIES; j++)
            {
                distance = Vector3Distance(sim->ptoOrbList[i].pos, sim->ptoOrbList[j].pos);
                Aij = calcAij(sim->ptoOrbList[i], sim->ptoOrbList[j], distance * distance * distance);

                sim->ptoOrbList[i].acc = Vector3Add(sim->ptoOrbList[i].acc, Aij);
                Aji = Vector3Scale(Aij, (sim->ptoOrbList[i].mass / sim->ptoOrbList[j].mass));
                sim->ptoOrbList[j].acc = Vector3Subtract(sim->ptoOrbList[j].acc, Aji);

            }
        }


        calcVel(sim,i);
        calcPosition(sim, i);
    }

}

Vector3 calcAij(OrbitalBody bodyi, OrbitalBody bodyj, float denominador) {
    if (denominador == 0)
    {
        return Vector3Zero();
    }
    else
    {
        float scalarMult = (-GRAVITATIONAL_CONSTANT * bodyj.mass) / (denominador);
        Vector3 vectMult = Vector3Subtract(bodyi.pos, bodyj.pos);
        return Vector3Scale(vectMult, scalarMult);
    }
}

void calcVel(OrbitalSim * sim, int index)
{
    Vector3 newVel;
        newVel = Vector3Add(sim->ptoOrbList[index].vel, (Vector3Scale(sim->ptoOrbList[index].acc, sim->time_step)));
        sim->ptoOrbList[index].vel = newVel;
    
        
}

void calcPosition(OrbitalSim * sim, int index) //Esta funcion asume que v(n+1), es decir, calcVel, ya fue llamada y es utilizada como tal en el calculo de la nueva posicion.
{
Vector3 newPosition = Vector3Zero();
    newPosition = Vector3Add(sim->ptoOrbList[index].pos, Vector3Scale(sim->ptoOrbList[index].vel, sim->time_step));
    sim->ptoOrbList[index].pos = newPosition;
}


// Esta funcion simulate un timestep
void updateOrbitalSim(OrbitalSim* sim)
{

    sim->time_total += sim->time_step;
    calcValues(sim);
}

void freeOrbitalSim(OrbitalSim *sim)
{
    free(sim->ptoOrbList);
}


float scaleRadius(float radius) {
    return  (0.008F * logf(radius));
}