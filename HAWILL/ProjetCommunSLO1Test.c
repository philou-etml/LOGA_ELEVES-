//-----------------------------------------------------------------------------------//
// Nom du projet 		: ProjetCommunSLO1
// Nom du fichier 		: ProjetCommunSLO1Test
// Date de cr�ation 	: 31.05.2018
// Date de modification : xx.xx.2018
//
// Auteur 				: Pierre Hawil
//
// Version				: 0.0
//
// Description          : Canevas pour test 1 -> voir donn�e
//
//
// Remarques			:            
//----------------------------------------------------------------------------------//

#include <stdio.h>
#include <stdint.h>
#include "trigo.c"

int main(void)
{

	//Variables
	int ValDegre;
	int ValRad;
	int ValFactorielle;
	int ValFibonacci;
	char TestChoisi;
	int ValSaisie;

	do {
		printf("Test  T pour Trigo, C pour Crypto, R pour Recursif, A pour Alea, G pour Gestion, L pour Log, S pour strModule ou Q pour Quitter \n");
		scanf("%c%*c", &TestChoisi);

		switch (TestChoisi){
			case 'T':
			case 't':
				printf("Vous avez choisi de tester les fonctions de trigonom�trie \n");

				//fonction ConvDegRad (fonction qui re�oit en param�tre une valeur en degr� d'un angle et qui permet la conversion en radian)
				printf("Commencer par entrer une valeur d'angle en degres: ");
				scanf("%d%*c", &ValSaisie);
				printf("La valeur d'angle entr�e en degr� vaut %d en radians \n", ValSaisie);

				//fonction ConvRadDeg (fonction qui re�oit en param�tre une valeur en radian d'un angle et qui permet la conversion en degr�)
				printf("Entrez maintenant une valeur d'angle en radians: ");
				scanf("%d%*c", &ValSaisie);
				printf("La valeur d'angle entr�e en radian vaut %d en degres \n", ValSaisie);

				//fonction CalculTrigo ()
			break;
			
			case 'C':
			case 'c':
				printf("Vous avez choisi de tester les fonctions de crypthographie \n");
			//Liste et test des diff�rentes fonctions de la librairie Crypto
			//fonction MotCrypto (fonction ne recevant aucun param�tre mais retourne un mot cryt�)
			//fonction MotDecrypto (fonction recevant en param�tre un mot cryt� mais ne retournant rien)
			break;

			case 'R':
			case 'r':
				printf("Vous avez choisi de tester les fonctions r�cursives \n");
			//Liste et test des diff�rentes fonction de la libraire Recursif
			//fonction FctFactorielle (fonction qui re�oit en param�tre un nombre entre 1 et 100 puis qui retourne la factorielle de ce nombre)
		
				printf("Entrez un nombre pour le calcul de factorielle: ");
				scanf("%d%*c", &ValSaisie);
				printf("La factorielle du nombre vaut: ");
				printf("Entrez un nombre qui correspond � une position dans la suite de Fibonacci");
				scanf("%d%*c", &ValSaisie);
				printf("Le nombre de la suite de Fibonacci vaut ");

			
			//fonction FctFibonacci (fonction qui re�oit en param�tre un nombre entre 1 et 50 puis qui retourne la position du nombre de la suite de Fibonnacci)
			//do {
				printf("Entrez un nombre qui correspond � une position dans la suite de Fibonacci");
				scanf("%d%*c", &ValSaisie);
				printf("Le nombre de la suite de Fibonacci vaut ");
				//printf("Entrez un nombre de Fibonacci: ");
				//scanf_s("%d%*c", &ValSaisie);
				//ValFibonacci = FctFibonacci(ValSaisie);
				//printf("La valeur de la position %d de la suite de nombres de Fibonacci vaut %d", ValSaisie, ValFibonacci);
			//} while (ValSaisie < ValMinArretLibRecursif);
			break;

			case 'A':
			case 'a':
			//Liste et test des diff�rentes fonction de la libraire Alea
			//fonction RandomCustomEntier
			//fonction RandomCustomFloat
			break;

			case 'G':
			case 'g':
			//Liste et test des fonctions de la librairie Gestion
			//fonction CreationClasse
			//fonction AjouterEleves
			//fonction SupprimerEleves
			break;
			
			case 'L':
			case 'l':
			//Liste et test des fonctions de la librairie Log
			//fonction EnregistrerLog
			//fonction VisualiserLog
			break;
			
			case 'S':
			case 's':
			//Liste et test des fonctions de la structure strModule
			//fonction AjoutNotes (fonction recevant en param�tre le tableau de type strClasse, ainsi que l'ID de l'�l�ve)
			//fonction DisplayMoyenne (fonction recevant en param�tre le tableau de type strClasse, ainsi que l'ID de l'�l�ve)
			break;

			default:
				break;



				
		}


	} while (!(TestChoisi == 'Q' || TestChoisi == 'q'));
	return 0;
}