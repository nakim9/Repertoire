#include "struct.h"
#include <stdio.h>

void affichePersonne(PERSONNE * p){
  if(p == NULL) {//Verification du paramettre en entrée
    printf("Qui ?\n");
  }
  else{
    printf("  %s %s\n  %s\n  __________\n", p->nom, p->prenom, p->tel);
  }
}

void affichePersonnes(PERSONNE * p){
  if(p == NULL) printf("L'annuaire est vide\n"); //Affichage si le paramettre  est vide
  while(p != NULL){
    affichePersonne(p);
    p = p->suiv;
  }
}
