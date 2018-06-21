#include <stdio.h>	// pour fopen, fprintf
#include <math.h>
//#include "fonction.h"

//Déclaration des constantes 
#define M_PI       3.14159265358979323846   // pi

int affichage(void)
{
	char UserAnswer;
	float Angle_Degre = 0; 
	float Angle_Radian = 0;

	float Valeur_Degre = 0; 
	float Valeur_Radian = 0; 

// -------------------------- PROGRAMME PRINCIPAL --------------------------
	do {
		printf("Test A ou B, Q pour Quitter \n");
		printf("Test A - Conversion de degre en radian\n");
		printf("Test B - Conversion de radian en degre\n");
		scanf_s("%c%*c", &UserAnswer, 2);

		switch (UserAnswer)
		{
		//------------------- Conversion de degré en radian ------------------- 
		case 'A':
		case 'a':
			printf("****** Conversion en radian ****** \n");
			printf("Entrez un angle en degre\n");
			scanf_s("%f", &Angle_Degre);
			// Si la valeur renvoyé par la fonction est différente du code erreur, alors on affiche
			// la conversion 
			if (ConvDegRad(Angle_Degre, &Valeur_Radian) != 11)
			{
				printf("%f en degre correspond a %f en radian\n", Angle_Degre, Valeur_Radian);
			}
			// Si la valeur renvoyé vaut 11, alors la conversion n'est pas possible et on affiche
			//le code erreur
			else
			{
				printf("CODE ERROR 11\n"); 
			}
			break;

			//------------------- Conversion de radian en degré //-------------------
			case 'B' :
			case 'b' :
				printf("****** Conversion en degre ******\n");
				printf("Entrez un angle en radian\n");
				scanf_s("%f", &Angle_Radian);
				// Si la valeur renvoyée par la fonction  est différente du code erreur, alors on affiche 
				// la conversion
				if (ConvRadDeg(Angle_Radian, &Valeur_Degre) != 12)
				{
					printf("%f en radian correspond a %f en degre\n", Angle_Radian, Valeur_Degre);
				}
				// Si la valeur renvoyé vaut 12, alors la conversion n'est pas possible et on affiche
				// le code erreur
				else
				{
					printf("CODE ERROR 12\n");
				}
				break; 
		}
		while (UserAnswer != '\n' && UserAnswer != EOF)
		{
			UserAnswer = getchar();
		}
	} while (!(UserAnswer == 'Q' || UserAnswer == 'q'));

	return (0);
}

//-------------------------------- FONCTIONS --------------------------------
// Fonction qui reçoit une valeur d'angle en degré et la convertit en radian 
float ConvDegRad(float Angle_D, float *pt_AngleRadian)
{
	float Angle_R = 0;
	// Angle en degré comprit entre 0° et 360°
	if (Angle_D >= 0 && Angle_D <= 360)
		// On exécute la conversion
	{
		Angle_R = (Angle_D * M_PI) / 180;
		*pt_AngleRadian = Angle_R; 
		return(1); 
	}
	//Angle pas comprit entre 0° et 360°, on retourne la valeur 11 pour indiquer une erreur
	else
	{
		return(11);
	}	
}

// Fonction qui reçoit une valeur d'angle en radian et la convertit en degré 
float ConvRadDeg(float Angle_R, float *pt_Angledegre)
{
	float angle_D = 0;
	//Angle en radian comprit entre 0 et 2PI
	if (Angle_R >= 0 && Angle_R <= 2*M_PI)
	{
		//On exécute la conversion
		angle_D = (Angle_R *180) / M_PI;
		*pt_Angledegre = angle_D ;
		return(1); 
	}
	// Angle pas comprit entre 0 et 2PI, on retourne la valeur 12 pour indiquer une erreur
	else
	{
		return(12);
	}
}
//-------------------------------- STRUCTURE --------------------------------
/*int CalculTrigo(S_InfoTriangle infoTriangle,float *pt_structure)
{
	int fhyp = 0;

	if (infoTriangle.hyp != 0)
	{
		hyp = infoTriangle.hyp;
		fhyp = 1;
	}
	if (infoTriangle.adj != 0)
	{
		adj = infoTriangle.hyp;
		fadj = 1;
	}
	if (infoTriangle.opp != 0)
	{
		opp = infoTriangle.hyp;
		fopp = 1;
	}
	if (infoTriangle.cos != 0)
	{
		cos = infoTriangle.hyp;
		fcos = 1;
	}
	if (infoTriangle.sin != 0)
	{
		sin = infoTriangle.hyp;
		fsin = 1;
	}
	if (infoTriangle.tan != 0)
	{
		tan = infoTriangle.hyp;
		ftan = 1;
	}
	if (fcos + fsin + ftan
}*/
