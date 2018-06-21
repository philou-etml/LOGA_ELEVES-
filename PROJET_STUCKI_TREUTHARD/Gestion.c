#include "Gestion.h"
#include <stdlib.h>
#include <stdio.h>

/*typedef struct
{
	char nom_Eleve[10];
	char prenom_Eleve[10];
	int id_Eleve;
} strEleve;*/
int taille_classe = 0;
strEleve* CreationClasse(char nb_Eleves)
{
	strEleve *nombre;
	//strEleve taille;
	nombre = calloc(nb_Eleves, taille_classe);
	if (nombre == NULL)
	{
		printf("Erreur allocation");
		exit(0);
	}
	
	//free(nombre);
	return (nombre);
}


void AjouterEleves(strEleve Eleve, strEleve *nombre)
{
//	char test[10];
	char var = 0;
	nombre = realloc(nombre, taille_classe++);
	if (taille_classe > 0)
	{
		for (int i = 0; i < taille_classe; i++)
		{
			
			printf("Prenom de l'eleve %d ?\n", i+1);
			scanf_s("%s", Eleve.prenom_Eleve, 10);

			printf("Nom de l'eleve %d ?\n", i+1 );
			scanf_s("%s", Eleve.nom_Eleve, 10);

			printf("ID de l'eleve %d ?\n", i + 1);
			scanf_s("%d", Eleve.id_Eleve);
			
			
			printf("Prenom = %s, Nom = %s, ID = %d \n", Eleve.prenom_Eleve, Eleve.nom_Eleve, Eleve.id_Eleve);
		}
	}
}

void SupprimerEleves(strEleve Eleve, strEleve *nombre)
{
	nombre = realloc(nombre, taille_classe --);
	free(nombre);
}
