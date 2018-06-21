#include <stdio.h>	// pour fopen, fprintf
#include <math.h>
#include "fonction.h"

//Déclaration des constantes 
#define M_PI       3.14159265358979323846   // pi

int main(void)
{
	char UserAnswer;
	float Angle_Degre = 0; 
	float Angle_Radian = 0;

	float Valeur_Degre = 0; 
	float Valeur_Radian = 0; 
	
	struct NomDeVotreStructure
	{
		int variable1;
		int variable2;
		int autreVariable;
	} infoTriangle;

	struct NomDeVotreStructure test2; 
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

				//------------------- Structure d'un Triangle //-------------------
			case 'C':
			case 'c':
				printf("****** Structure Triangle ******\n");

				

				CalculTrigo(&infoTriangle);

				
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
int CalculTrigo(S_InfoTriangle *infoTriangle)
{
	float fhyp = 0;
	float fadj = 0;
	float fopp = 0;
	float fcos = 0;
	float fsin = 0;
	float ftan = 0;

	float hyp = 0;
	float adj = 0;
	float opp = 0;
	float cos = 0;
	float sin = 0;
	float tan = 0;

	if (infoTriangle->hyp != 0)
	{
		hyp = infoTriangle->hyp;
		fhyp = 1;
	}
	if (infoTriangle->adj != 0)
	{
		adj = infoTriangle->hyp;
		fadj = 1;
	}
	if (infoTriangle->opp != 0)
	{
		opp = infoTriangle->hyp;
		fopp = 1;
	}
	if (infoTriangle->cos != 0)
	{
		cos = infoTriangle->hyp;
		fcos = 1;
	}
	if (infoTriangle->sin != 0)
	{
		sin = infoTriangle->hyp;
		fsin = 1;
	}
	if (infoTriangle->tan != 0)
	{
		tan = infoTriangle->hyp;
		ftan = 1;
	}
	// Situations interdites, car aucune possibilité de calcul 
	if ((fhyp + fadj + fopp) == 0)
	{
		return (1);
	}
	if ((fhyp + ftan) == 2 && (fsin + fcos + fopp + fadj) == 0)
	{
		return (1);
	}
	if ((fopp + fcos) == 2 && (fsin + ftan + fhyp + fadj) == 0)
	{
		return (1);
	}
	if ((fadj + fsin) == 2 && (ftan + fcos + fopp + fhyp) == 0)
	{
		return (1);
	}
	// Calcul pour les angles 

	//  Calcul pour le Sinus 
	if (fopp + fhyp == 2)
	{
		sin = asinf(opp / hyp);
	}
	//  Calcul pour la Tangante 
	if (fopp + fadj == 2)
	{
		tan = atanf(opp / adj);
	}
	// Calcul pour le Cosinus
	if (fadj + fhyp == 2)
	{
		cos = acosf(adj / hyp);
	}

	// Calcul pour le côté opposé 
	if (fsin + fhyp == 2)
	{
		opp = sinf (sin) * hyp;
	}
	if (ftan + fadj == 2)
	{
		opp = tanf(tan) * adj;
	}
	// Calcul pour le côté adjacent
	if (ftan + fopp == 2)
	{
		adj = opp / (tanf(tan));
	}
	if (fcos + fhyp == 2)
	{
		adj = cosf(cos) * hyp;
	}
	// Calcul pour le côté hypoténuse
	if (fsin + fopp == 2)
	{
		hyp = opp / (sinf(sin));
	}
	if (fadj + fcos == 2)
	{
		hyp = adj / (cosf(cos));
	}
	// Calcul pour les côtés
	if (fhyp + fopp == 2)
	{
		adj = sqrtf(powf(hyp, 2)- powf(opp, 2));
	}
	if (fhyp + fadj == 2)
	{
		opp = sqrtf(powf(hyp, 2) - powf(adj, 2));
	}
	if (fopp + fadj == 2)
	{
		hyp = sqrtf(powf(adj, 2) + powf(opp, 2));
	}
}
