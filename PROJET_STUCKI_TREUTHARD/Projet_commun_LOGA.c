// 
// Projet groupe Treuthardt - Stucki
//
//


#include <stdio.h>

// type structure fourni
typedef struct {
	float NoteTe1;
	float NoteTe2;
	float NoteTe3;
} S_TroisNotes ;

typedef struct {
	S_TroisNotes EleveA;
	S_TroisNotes EleveB;
	S_TroisNotes EleveC;
} S_AllNotes ;

// definition du type S_AllMoyennes



// Fonction CalculAllMoyennes



// Fonction CalculAllMoyTestB



// Programme principal
int main (void)
{
	char UserAnswer;
	// Variables pour test A
	S_AllNotes ValA = {
		{5.5, 5.0, 5.0},
		{4.0, 4.5, 5.0},
		{3.5, 4.0, 4.0} };
	

	// Variables pour test B
	
	// Modification de la note 1 de l'élève B à 4.5

	// A adapter !!!
	printf("Ex13B Prenom NOM \n");

	do {
		printf("Test A ou B, Q pour Quitter \n");
		scanf_s("%c%*c", &UserAnswer, 2);
		
		switch (UserAnswer) {
			case 'A':
			case 'a':
				printf("TestA:  \n");
				// Appel de CalculAllMoyennes

				// Affichage des moyennes


			break;

			case 'B':
			case 'b':
				printf("TestB:  \n");
				// Appel de CalculAllMoyTestB
				
				// Affichage des moyennes
				
			break;

		} // end switch
	
	} while (!(UserAnswer == 'Q' || UserAnswer == 'q'));

	return (0);
}