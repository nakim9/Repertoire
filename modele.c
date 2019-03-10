#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "struct.h"

PERSONNE * ajoutPersonne(PERSONNE * tete, PERSONNE * p){
  if(p == NULL){
    p = tete;
  }

  if(tete != NULL){
    p->suiv = tete;
  }

  return p;
}

PERSONNE * ajoutPersonneFin(PERSONNE * tete, PERSONNE * p){
  if(tete == NULL){
    tete = p;
  }
  else{
    PERSONNE * courant = tete;
    while(courant->suiv != NULL){
      courant = courant->suiv;
    }
    courant->suiv = p;
  }
  return tete;
}

PERSONNE * ajoutPersonneParNom(PERSONNE * tete, PERSONNE * p){
  if(tete == NULL){
    tete = p;
  }
  else{
    PERSONNE * precedant = tete;
    PERSONNE * courant = tete->suiv;

    if(courant == NULL){ //true quand il n'y a qu'un element dans la liste tete
      if(strcmp(precedant->nom,p->nom)<0){
        tete = ajoutPersonneFin(precedant,p);
      }
      else{
        tete = ajoutPersonne(precedant,p);
      }
    }

    else{//cas où il y a 2 elem ou plus
      while(courant->suiv != NULL && strcmp(courant->nom,p->nom) < 0){
        precedant = courant;
        courant = courant->suiv;
      }

      if(strcmp(precedant->nom,p->nom)>0){
        tete = ajoutPersonne(precedant,p);//Cas où la personne à ajouter est avant la première personne de la liste
      }
      else{
        if(courant->suiv == NULL){
          courant = ajoutPersonneFin(courant,p); //ajout à la toute fin de liste
        }
        else{
          precedant->suiv = p;
          p->suiv = courant; //cas nominal insertion en milieu de liste
        }
      }
    }
  }
  return tete;
}

PERSONNE * saisirPersonne(PERSONNE * tete){
  PERSONNE * p = malloc(sizeof(PERSONNE));
  printf("  Rentrez les informations de la personne\nNom : ");
  scanf("%s", p->nom);
  printf("  Prénom : ");
  scanf("%s", p->prenom);
  printf("  teléro (0xxxxxxxxx) : ");
  scanf("%s", p->tel);

  p->suiv = NULL;

  return p;
}

PERSONNE * recherchePersonne(PERSONNE * tete, unsigned char mode, char * critere){
  PERSONNE * courant = tete;
  PERSONNE * ret = NULL;

  if(tete != NULL && critere != NULL && strcmp(critere,"") != 0){
    switch(mode){
      case '1': //Recherche par nom
        while(courant->suiv != NULL && strcmp(courant->nom,critere) != 0){
          courant = courant->suiv;
        }
        if(strcmp(courant->nom,critere) == 0){
          ret = courant;
        }
        else{
          printf("%s n'a pas été trouvé\n", critere);
        }
      break;

      case '2': //Recherche par prenom
        while(courant->suiv != NULL && strcmp(courant->prenom,critere) != 0){
          courant = courant->suiv;
        }
        if(strcmp(courant->prenom,critere) == 0){
          ret = courant;
        }
        else{
          printf("%s n'a pas été trouvé\n", critere);
        }
      break;

      case '3': //Recherche par numero de telephone
        while(courant->suiv != NULL && strcmp(courant->tel,critere) != 0){
          courant = courant->suiv;
        }
        if(strcmp(courant->tel,critere) == 0){
          ret = courant;
        }
        else{
          printf("Le numéro %s n'a pas été trouvé\n", critere);
        }
      break;

      default :
        printf("Une erreur est survenue lors de l'execution du programme.\n");
        ret = NULL;
        break;
    }
  }
  else{
    printf("Une erreur est survenue lors de l'execution du programme.\n");
    ret = NULL;
  }
  return ret; //SI retun NULL : un erreur est survenue ; Sinon retour la personne cherchée
}

PERSONNE * supprimePersonne(PERSONNE * tete, PERSONNE * p){
  if(tete == NULL){return NULL;}
  if(p==NULL){return NULL;}
  PERSONNE * precedant = tete;
  PERSONNE * courant = precedant->suiv;

  if(precedant == p){
    //suppression du premier
    tete = courant;
    free(precedant);
    return tete;
  }
  else{

    while(courant->suiv != NULL && courant != p){
      precedant = courant;
      courant = courant->suiv;
    }

    if(courant->suiv == NULL){
      if(courant == p){
        //suppression du dernier
        precedant->suiv = NULL;
        free(courant);
      }

      else{
        //introuvable
        printf("La personne n'est pas trouvée dans le dictionnaire.\n");
      }
    }

    else if(courant == p){
      //cas nominal
      precedant->suiv = courant->suiv;
      free(courant);
    }
    else{
      printf("Une erreur est survenue lors de l'execution du programme.\n");
    }
  }
  return tete;
}
