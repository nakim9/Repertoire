/* ajoute au repertoire une personne p dans la liste tete */
NOEUD * ajoutPersonne(NOEUD * tete, NOEUD * p);

/* ajoute la personne p à la fin de la liste chainée */
NOEUD * ajoutPersonneFin(NOEUD * tete, NOEUD * p);

/* ajoute au repertoire la personne p par ordre de nom alphabétique*/
NOEUD * ajoutPersonneParNom(NOEUD * tete, NOEUD * p);

/* Demande à l'utilisateur de saisir une personne à ajouter au repertoire */
PERSONNE * saisirPersonne(void);
/*  Permet de créer un noeud
  *personne : personne associé au noeud
  *suivant : noeud suivant, peut être null
  * /!\ Methode unsafe : merci de verifier le retour de la fonction
*/
NOEUD * creerNoeud(PERSONNE * personne, NOEUD * suivant);

/**
  *Permet de chercher parmis la liste chainée designée par tete selon le mode
  *Mode possible :
  *   1 : Recherche par nom
  *   2 : Recherche par prenom
  *   3 : Recherche par numero de téléphone
  *critere est ce que l'on cherche
*/
NOEUD * recherchePersonne(NOEUD * tete, unsigned char mode, char * critere);

/* Supprime l'element de la liste */
NOEUD * supprimePersonne(NOEUD * tete, NOEUD * p);
