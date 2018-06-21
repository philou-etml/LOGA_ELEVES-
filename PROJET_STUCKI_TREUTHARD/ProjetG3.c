// 
// Projet groupe Treuthardt - Stucki
//
//


#include <stdio.h>
#include "Gestion.h"

typedef struct
{
	char car[10];
	char oui[10];
	int chiffre;
} strtest;

int main()
{
	//int test_for = 4;
	char nbr_glands;
	strEleve *glands;
	strEleve nouvel_eleve = {	"",
								"",
								 };
	/*strtest test = {	"",
						"",
						3
						};*/

	/*for (int i = 0; i < test_for; i++)
	{
		printf("ID de l'eleve %d ?\n", i + 1);
		scanf_s("%d", test.chiffre);

		printf("Prenom de l'eleve %d ?\n", i + 1);
		scanf_s("%s", test.car, 10);
		printf("Nom de l'eleve %d ?\n", i + 1);
		scanf_s("%s", test.oui, 10);


		printf("Prenom = %s, Nom = %s, ID = %s \n", test.car, test.oui, test.chiffre);
	}*/
	//do{

		printf("cb de glands? \n");
		scanf_s("%d", &nbr_glands);
		glands = CreationClasse(nbr_glands);
		AjouterEleves(nouvel_eleve, glands);


	
	//} while (1); 
	
	
	/*while (nbr_glands != '\n' && nbr_glands != EOF)
	{
		nbr_glands = getchar();
	}*/

	return 0;
}