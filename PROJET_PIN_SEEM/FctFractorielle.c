//**************************************************************************************
// Titre          : librairie :	une fonction de calcul de produit factoriel			   *
//								une fonction de calcul d'une valeur de fibonacci	   *
// Source         : main.c							                                   * 
// Auteur         : GPN - TSM                                                          *
// Lieu           : ETML-ES calsse des SLO1			                                   *
// Création       : 31.05.2018                                                         *
// Révision       : -                                                                  *
// Description    : ...                                                                *
//                                                                                     *
//                                                                                     *
//**************************************************************************************

//======================================================================================

//Appel du header pour la fonction FctFactorielle
#include "FctFractorielle.h"
#include <stdlib.h>
#include <stdio.h>

double FctFactorielle(uint8 *byV_ValFrac)
{
	//Variable locale
	static double ValCalculee = 1;
	//Test si on a atteint la fin du calcul

	//Test si on a atteint la valeur max
	if ((*byV_ValFrac > 20) || (*byV_ValFrac < 1))
	{
		return -1;
	}

	if (*byV_ValFrac != 0)
	{
		//Calcul de la valeur actuel 
		ValCalculee *= *byV_ValFrac;
		//Enlever 1 au nombre d'opération encore nécessaire
		*byV_ValFrac -= 1;
		//Appel de la fonction factorielle suivante
		FctFactorielle(byV_ValFrac);
	}
	else
	{

	}
	return ValCalculee;
}


//initialisation de la fonction Fibonacci
int fib(int n)
{
	//Test si on a atteint la valeur max
	if ((n > 40) || (n < 0))
	{
		return -1;
	}

	if (n < 2)
	{
		return n;
	}
	else
	{
		return fib(n - 1) + fib(n - 2);
	}

}