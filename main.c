#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <gtk/gtk.h>

#include "struct.h"
#include "modele.h"
#include "vue.h"
#include "listio.h"

#define UTF8(string) g_locale_to_utf8(string, -1, NULL, NULL, NULL)

int menu();
NOEUD * seekAndDestroy(NOEUD * tete);
NOEUD * ajoutTrio(NOEUD * tete);

int main(void){

  printf("Bonjour,\nBienvenue dans la selection annuaires.\n");
  printf("-> ");

  menu();

  return 0;
}

int menu(){
  int choixMenu;
  NOEUD * tete = NULL;
  tete = readRepertoire(NULL);


  do{
    printf(" Que voulez vous faire ?\n");
    printf(" 1. Afficher repertoire\n");
    printf(" 2. Ajouter une personne au debut du repertoire\n");
    printf(" 3. Ajouter une personne à la fin du repertoire\n");
    printf(" 4. Ajouter par ordre alphabétique\n");
    printf(" 5. Seek and Destroy\n");
    printf(" 0. Sortir\n --> ");
    scanf("%d",&choixMenu);
    while(choixMenu != 0 && choixMenu != 1 && choixMenu != 2 && choixMenu != 3 && choixMenu != 4 && choixMenu != 5){
      printf(" Entrée invalide. Veuillez selectionner une des options proposées\n ->");
      scanf("%d",&choixMenu);
    }
    NOEUD * nouveau = NULL;
    switch (choixMenu) {
      case 1:
      affichePersonnes(tete);
      break;

      case 2:
      nouveau = creerNoeud(saisirPersonne(),NULL);
      tete = ajoutPersonne(tete,nouveau);
      break;

      case 3:
      nouveau = creerNoeud(saisirPersonne(),NULL);
      tete = ajoutPersonneFin(tete,nouveau);
      break;

      case 4:
      nouveau = creerNoeud(saisirPersonne(),NULL);
      tete = ajoutPersonneParNom(tete,nouveau);
      break;

      case 5:
      tete = seekAndDestroy(tete);
      break;

      case 10:
      tete = ajoutTrio(tete);
      break;
    }
  }while(choixMenu != 0);

  writeRepertoire(NULL,tete);

  while (tete != NULL) {
    tete = supprimePersonne(tete,tete);
  }

  return 0;
}

NOEUD * seekAndDestroy(NOEUD * tete){
  NOEUD * pRecherche = NULL;
  unsigned char modeRecherche=0; char recherche[32]; char reponseForm = 'a';
  /* Formulaire pour la recherche */
    /* Mode */
  do{
    printf("    Rechercher par :\n");
    printf("    1. Nom\n");
    printf("    2. Prenom\n");
    printf("    3. Numero de téléphone\n    --> ");
    getchar();
    scanf("%c", &modeRecherche);
  }while(modeRecherche != 1 && modeRecherche != '1'
          && modeRecherche != 2 && modeRecherche != '2'
            && modeRecherche != 3 && modeRecherche != '3');
    /* Critere */
  do{
    printf("    Que cherchez vous ?\n   --> ");
    getchar();//clear buffer
    scanf("%s", recherche);
  }while(recherche == NULL || strcmp(recherche,"") == 0);
  pRecherche = recherchePersonne(tete,modeRecherche,recherche);

  /* Formulaire de suppression */
  if(pRecherche != NULL){
    printf("    Cette personne a été trouvée !\n");
    affichePersonne(pRecherche->courant);

    do{
      printf("    Voulez vous la supprimer ? (o/n)\n   --> ");
      getchar(); //clear buffer
      scanf("%c",&reponseForm); //reponses attendues : n, N, o, O
    }while(reponseForm != 'o' && reponseForm != 'n'
          && reponseForm != 'O' && reponseForm != 'N');

    if(reponseForm == 'o' || reponseForm == 'O'){
      tete = supprimePersonne(tete,pRecherche);
      printf("    Suppression effectuée !\n");
    }

  }

  return tete;
}


NOEUD * ajoutTrio(NOEUD * tete){
  /* Ajout en dur de 3 personnes */
  PERSONNE * premier = NULL;
  premier = malloc(sizeof(PERSONNE));
  if(premier == NULL) return NULL;

  strcpy(premier->nom,"Greck");
  strcpy(premier->prenom,"Lucas");
  strcpy(premier->tel,"0123456789");

  NOEUD * n1 = NULL;
  n1 = malloc(sizeof(NOEUD));
  if(n1 == NULL) return NULL;
  n1->courant = premier;

  PERSONNE * deuxieme = NULL;
  deuxieme = malloc(sizeof(PERSONNE));
  if(deuxieme == NULL) return NULL;

  strcpy(deuxieme->nom,"Gonckel");
  strcpy(deuxieme->prenom,"Laury");
  strcpy(deuxieme->tel,"0658536831");

  NOEUD * n2 = NULL;
  n2 = malloc(sizeof(NOEUD));
  if(n2 == NULL) return NULL;
  n2->courant = deuxieme;

  PERSONNE * troisieme = NULL;
  troisieme = malloc(sizeof(PERSONNE));
  if(troisieme == NULL) return NULL;

  strcpy(troisieme->nom,"Robin");
  strcpy(troisieme->prenom,"Tangui");
  strcpy(troisieme->tel,"0761986318");

  NOEUD * n3 = NULL;
  n3 = malloc(sizeof(NOEUD));
  if(n3 == NULL) return NULL;
  n3->courant = troisieme;

  tete = ajoutPersonneParNom(tete,n1);
  tete = ajoutPersonneParNom(tete,n2);
  tete = ajoutPersonneParNom(tete,n3);

  return tete;
}
