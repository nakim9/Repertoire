/* ajoute au repertoire une personne p dans la liste tete */
PERSONNE * ajoutPersonne(PERSONNE * tete, PERSONNE * p);

/* ajoute la personne p à la fin de la liste chainée */
PERSONNE * ajoutPersonneFin(PERSONNE * tete, PERSONNE * p);

/* ajoute au repertoire la personne p par ordre de nom alphabétique*/
PERSONNE * ajoutPersonneParNom(PERSONNE * tete, PERSONNE * p);


/* Demande à l'utilisateur d'ajouter une personne au repertoire et l'ajoute*/
PERSONNE * saisirPersonne(PERSONNE * tete);

/**
  *Permet de chercher parmis la liste chainée designée par tete selon le mode
  *Mode possible :
  *   1 : Recherche par nom
  *   2 : Recherche par prenom
  *   3 : Recherche par numero de téléphone
  *critere est ce que l'on cherche
*/
PERSONNE * recherchePersonne(PERSONNE * tete, unsigned char mode, char * critere);

/* Supprime l'element de la liste */
PERSONNE * supprimePersonne(PERSONNE * tete, PERSONNE * p);
