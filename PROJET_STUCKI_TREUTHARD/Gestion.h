#ifndef GESTION_H
#define GESTION_H
typedef struct
{
	char nom_Eleve[10];
	char prenom_Eleve[10];
	int id_Eleve;
} strEleve;


strEleve* CreationClasse(char nb_Eleves);
void AjouterEleves(strEleve Eleve, strEleve *nombre);
void SupprimerEleves(strEleve Eleve, strEleve *nombre);


#endif // !FORME_H


