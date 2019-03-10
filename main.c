#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <gtk/gtk.h>

#include "struct.h"
#include "modele.h"
#include "vue.h"




// int main(int argc, char **argv)
//
// {
//
//     /* Initialisation de GTK+ */
//
//     gtk_init(&argc, &argv);
//
//     return EXIT_SUCCESS;
//
// }


void menu();
PERSONNE * seekAndDestroy(PERSONNE * tete);

int main(void){

  printf("Bonjour,\nBienvenue dans la selection annuaires.\n");
  printf("-> ");

  menu();

  return 0;
}

void menu(){
  int choixMenu;
  PERSONNE * tete = NULL;

  /* Ajout en dur de 3 personnes */
  PERSONNE * premier = malloc(sizeof(PERSONNE));
  strcpy(premier->nom,"Greck");
  strcpy(premier->prenom,"Lucas");
  strcpy(premier->tel,"0123456789");
  premier->suiv = NULL;

  PERSONNE * deuxieme = malloc(sizeof(PERSONNE));
  strcpy(deuxieme->nom,"Gonckel");
  strcpy(deuxieme->prenom,"Laury");
  strcpy(deuxieme->tel,"0658536831");
  deuxieme->suiv = NULL;

  PERSONNE * troisieme = malloc(sizeof(PERSONNE));
  strcpy(troisieme->nom,"Robin");
  strcpy(troisieme->prenom,"Tangui");
  strcpy(troisieme->tel,"0761986318");
  troisieme->suiv = NULL;

  tete = ajoutPersonneParNom(tete,premier);
  tete = ajoutPersonneParNom(tete,deuxieme);
  tete = ajoutPersonneParNom(tete,troisieme);


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
    PERSONNE * nouveau = NULL;
    switch (choixMenu) {
      case 1:
      affichePersonnes(tete);
      break;

      case 2:
      nouveau = saisirPersonne(tete);
      tete = ajoutPersonne(tete,nouveau);
      break;

      case 3:
      nouveau = saisirPersonne(tete);
      tete = ajoutPersonneFin(tete,nouveau);
      break;

      case 4:
      nouveau = saisirPersonne(tete);
      tete = ajoutPersonneParNom(tete,nouveau);
      break;

      case 5:
      tete = seekAndDestroy(tete);
      break;
    }
  }while(choixMenu != 0);

  while (tete != NULL) {
    tete = supprimePersonne(tete,tete);
  }
}

PERSONNE * seekAndDestroy(PERSONNE * tete){
  PERSONNE * pRecherche = NULL;
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
    affichePersonne(pRecherche);

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
