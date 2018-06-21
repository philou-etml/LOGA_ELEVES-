//-----------------------------------------------------------------------------------//
// Nom du projet 		: ProjectLOGA_S2
// Nom du fichier 		: Groupe_5.c
// Date de création 	: 31.05.2018
// Date de modification : --.--.----
//
// Auteur 				: H.Fluckiger C.Isoz
//
// Description          : Voir données du project  
//
//
// Remarques :            
//----------------------------------------------------------------------------------//

//--- déclaration de librairie ---// 
#include <stdio.h>		// pour les entrées sorties système (console - clavier) 
#include <stdlib.h>		
#include <string.h>		// pour la gestion de châine de caractère 
#include <stdint.h>		// standart entier 
//-- déclaration de structure --//
typedef struct
{
	struct//partie a prendre chez Greglin 
	{
		char TBPrenom[20];
		char TBNom[20];
		short Age;
		int IDEleves;
	}strEleve;

	struct//3 notes + nbr pour s'assurer que pas plein - valeurs devront etre initialisée ailleurs
	{
		float TBNoteLoga[10];
		int NBNoteLoga;
		float TBNotePolo[10];
		int NBNotePolo;
		float TBNoteEmsy[10];
		int NBNoteEmsy;
		int IDEleves;
	}strModule;
	
	int annee;
}strClasse;



void AjoutNote(strClasse*Id)//Permet d'écrire dans un des trois tableau de notes
{
	float Note;
	char branche;

	while (branche != 'Q' || branche != 'q')// On utilise q pour sortir
	{
		printf("branche pour l'inscripsion des note 1,2 ou 3 \n(1 = Loga 2 = Polo 3 = Emsy)\n");
		scanf_s("%c%*c", &branche, 2);
		switch (branche)
		{
		case '1': //POUR LES NOTES DE LOGA
			if( Id->strModule.NBNoteLoga <=9)	//SI TABLEAU PAS PLEIN
			{
				printf("Entrez la note de l'eleve\n");
				scanf_s("%d", &Note);
				if ((Note <= 1) && (Note <= 6))//VALEUR NOTE OK
				{
					Id->strModule.TBNoteLoga[Id->strModule.NBNoteLoga] = Note; //ECRITURE NOTE
				}
				else//NOTE INCORRECTE 
				{
					printf("Erreur-60");
					return 0;
				}
				Id->strModule.NBNoteLoga ++;
			}
			else// TABLEAU PLEIN
			{
				printf("-50");
				return 0;
			}
			break;
		case '2':
			if (Id->strModule.NBNotePolo <= 9)
			{
				printf("Entrez la note de l'eleve\n");
				scanf_s("%d", &Note);
				if ((Note <= 1) && (Note <= 6))
				{
					Id->strModule.TBNotePolo[Id->strModule.NBNotePolo] = Note;
				}
				else
				{
					printf("Erreur-60");
					return 0;
				}
				Id->strModule.NBNotePolo++;
			}
			else
			{
				printf("-50");
				return 0;
			}
			break;
		case '3':
			if (Id->strModule.NBNoteEmsy <= 9)
			{
				printf("Entrez la note de l'eleve\n");
				scanf_s("%d", &Note);
				if ((Note <= 1) && (Note <= 6))
				{
					Id->strModule.TBNoteEmsy[Id->strModule.NBNoteEmsy] = Note;
				}
				else
				{
					printf("Erreur-60");
					return 0;
				}
				Id->strModule.NBNoteEmsy++;
			}
			else
			{
				printf("-50");
				return 0;
			}
		default :
				break;

		}
	}

}

int main(void)
{

	//Dans la création des élèves il faut ajouter l'initialisation des variables ainsi que des tableaux
	
	
	strClasse test[10]; //on cree test de type structure classe
	//test.IDEleves = test.strEleve.IDEleves;

	int index = 0; 

	test[index].strEleve.IDEleves = index;
	test[index].strModule.IDEleves = test[index].strEleve.IDEleves;

	if(test[index].strModule.IDEleves == 0)




	test

	test.strEleve.Age = 20; 
}