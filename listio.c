#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "struct.h"
#include "modele.h"
#include "vue.h"
/* Retourne la tête d'une liste chainée représentant les personnes stockées dans le fichier
  *nomFichier : nom du fichier dans lequel lire. Si Null lit dans rep1.bin
*/
NOEUD * readRepertoire(char * nomFichier){
  /* Contrôle de l'argument */
  if(nomFichier == NULL || strcmp(nomFichier,"") == 0)
    nomFichier = "rep1.bin";

  FILE * rep = NULL;
  rep = fopen(nomFichier,"rb");
  if(rep == NULL){
    printf("Repertoire \"%s\" non trouvé, veuillez à ce qu'il se trouve dans le même repertoire que l'executable\n", nomFichier);
    return NULL;
  }

  PERSONNE * buffer = malloc(sizeof(PERSONNE));
  PERSONNE * p;
  NOEUD * tete = NULL; NOEUD * courant = NULL;

  while(fread(buffer, sizeof(PERSONNE), 1, rep) > 0){
    p = malloc(sizeof(PERSONNE));
    *p = *buffer;
    courant = creerNoeud(p,NULL);
    if(courant == NULL){printf("erreur lors de la lecture du fichier");return NULL;}
    tete = ajoutPersonneParNom(tete,courant);
  }
  fclose(rep);

  return tete;
}

/* Ecrit toute la liste chainée dans le fichier
  *nomFichier : nom du fichier dans lequel ecrire
  *tete : tete de la liste chainée à écrire
*/
void writeRepertoire(char * nomFichier, NOEUD * tete){
  /* Contrôle de l'argument */
  if(nomFichier == NULL || strcmp(nomFichier,"") == 0)
    nomFichier = "rep1.bin";

  if(tete != NULL && tete->courant != NULL){
    FILE * rep = NULL;
    rep = fopen(nomFichier,"wb");
    if(rep == NULL) return;

    NOEUD * courant = tete; size_t test;

    while(courant != NULL){
      test = fwrite(courant->courant, sizeof(PERSONNE), 1, rep);
      if(test == 0) return;
      courant = courant->suiv;
    }
    fclose(rep);
  }
}


// int main(void) {
//
//   /* Ajout en dur de 3 personnes */
//   PERSONNE * premier = NULL;
//   premier = malloc(sizeof(PERSONNE));
//   if(premier == NULL) return -1;
//
//   strcpy(premier->nom,"Greck");
//   strcpy(premier->prenom,"Lucas");
//   strcpy(premier->tel,"0123456789");
//
//   NOEUD * n1 = NULL;
//   n1 = malloc(sizeof(NOEUD));
//   if(n1 == NULL) return -1;
//   n1->courant = premier;
//
//   PERSONNE * deuxieme = NULL;
//   deuxieme = malloc(sizeof(PERSONNE));
//   if(deuxieme == NULL) return -1;
//
//   strcpy(deuxieme->nom,"Gonckel");
//   strcpy(deuxieme->prenom,"Laury");
//   strcpy(deuxieme->tel,"0658536831");
//
//   NOEUD * n2 = NULL;
//   n2 = malloc(sizeof(NOEUD));
//   if(n2 == NULL) return -1;
//   n2->courant = deuxieme;
//
//   PERSONNE * troisieme = NULL;
//   troisieme = malloc(sizeof(PERSONNE));
//   if(troisieme == NULL) return -1;
//
//   strcpy(troisieme->nom,"Robin");
//   strcpy(troisieme->prenom,"Tangui");
//   strcpy(troisieme->tel,"0761986318");
//
//   NOEUD * n3 = NULL;
//   n3 = malloc(sizeof(NOEUD));
//   if(n3 == NULL) return -1;
//   n3->courant = troisieme;
//
//   n1->suiv = n2;
//   n2->suiv = n3;
//   n3->suiv = NULL;
//
//   writeRepertoire(NULL,n1);
//
//   affichePersonnes(readRepertoire(NULL));
//
//   return 0;
// }
