typedef struct{
  char nom[32];
  char prenom[32];
  char tel[10];
}PERSONNE;

typedef struct noeud{
  PERSONNE * courant;
  struct noeud * suiv;
}NOEUD;
