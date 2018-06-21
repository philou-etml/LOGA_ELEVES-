#pragma once
#ifndef FONCTION_H
#define FONCTION_H   

// Déclarations des fonctions 
float ConvDegRad(float Angle_D, float *pt_AngleRadian); 
float ConvRadDeg(float Angle_R, float *pt_Angledegre);

// Déclaration des structures 
typedef struct
{
	float hyp;
	float adj;
	float opp;
	float cos;
	float sin;
	float tan;
}S_InfoTriangle;


#endif

