typedef struct personne {
  char nom[32];
  char prenom[32];
  char tel[10];
  struct personne * suiv;
} PERSONNE;
