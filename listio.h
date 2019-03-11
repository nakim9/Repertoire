/* Retourne la tête d'une liste chainée représentant les personnes stockées dans le fichier
  *nomFichier : nom du fichier dans lequel lire. Si Null lit dans rep1.txt
*/
NOEUD * readRepertoire(char * nomFichier);

/* Ecrit toute la liste chainée dans le fichier
  *nomFichier : nom du fichier dans lequel ecrire
  *tete : tete de la liste chainée à écrire
*/
void writeRepertoire(char * nomFichier, NOEUD * tete);
