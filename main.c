// Auteur : Mr Joel YK
// Site web : PandaCodeur.com
// WhatsApp : +237 652027193
// Enonc� :
// Pour l�enregistrement des �tudiants du niveau 1 Informatique, l�autorit� administrative d�cide de faire appel � vous en tant qu�informaticien pour le stockage de ces �tudiants.
// Les op�rations souhait�es pour le moment sont la consultation, l�enregistrement des �tudiants, et leur gestion dans un fichier binaire.
// Pour une simulation de ce projet, il vous est demand� de prendre un �chantillon de 500 �tudiants.
// Ce programme permet de r�aliser les t�ches suivantes :
// - Consultation des �tudiants
// - Enregistrement des �tudiants
// - Gestion dans un fichier binaire

#include <stdio.h> // Inclusion de la biblioth�que standard pour les entr�es/sorties
#include <stdlib.h> // Inclusion de la biblioth�que standard pour la gestion de la m�moire
#include <string.h> // Inclusion de la biblioth�que pour la manipulation des cha�nes de caract�res

#define MAX_ETUDIANTS 500 // D�finition de la taille maximale des �tudiants

// D�finition de la structure pour un �tudiant
typedef struct {
    char matricule[20]; // Matricule de l'�tudiant (cha�ne de 20 caract�res)
    char nom[20]; // Nom de l'�tudiant (cha�ne de 20 caract�res)
    char prenom[20]; // Pr�nom de l'�tudiant (cha�ne de 20 caract�res)
    int age; // �ge de l'�tudiant
    char filiere[20]; // Fili�re de l'�tudiant (cha�ne de 20 caract�res)
    int niveau; // Niveau de l'�tudiant
} Etudiant;

// D�finition de la structure pour la liste des �tudiants
typedef struct {
    Etudiant etudiants[MAX_ETUDIANTS]; // Tableau des �tudiants
    int taille; // Taille actuelle de la liste des �tudiants
} ListeEtud;

// Fonction pour rechercher un �tudiant par matricule
// Retourne l'index de l'�tudiant ou -1 si non trouv�
int rechercherEtudiant(ListeEtud* t, const char* mat) {
    for (int i = 0; i < t->taille; i++) { // Parcourir tous les �tudiants
        if (strcmp(t->etudiants[i].matricule, mat) == 0) { // Comparer les matricules
            return i; // Retourne l'index si trouv�
        }
    }
    return -1; // Retourne -1 si non trouv�
}

// Proc�dure pour afficher les informations des �tudiants
void afficherEtudiants(ListeEtud* t) {
    for (int i = 0; i < t->taille; i++) { // Parcourir tous les �tudiants
        Etudiant* e = &t->etudiants[i]; // R�cup�rer un �tudiant
        printf("Matricule : %s\n", e->matricule); // Afficher le matricule
        printf("Nom : %s\n", e->nom); // Afficher le nom
        printf("Pr�nom : %s\n", e->prenom); // Afficher le pr�nom
        printf("�ge : %d\n", e->age); // Afficher l'�ge
        printf("Fili�re : %s\n", e->filiere); // Afficher la fili�re
        printf("Niveau : %d\n", e->niveau); // Afficher le niveau
        printf("-----------------------------\n"); // S�parateur entre les �tudiants
    }
}

// Fonction pour sauvegarder les �tudiants dans un fichier binaire
// Retourne 0 en cas de succ�s, -1 en cas d'�chec
int sauvegarderEtudiantsBinaire(ListeEtud* t, const char* nomFichier) {
    FILE* fichier = fopen(nomFichier, "wb"); // Ouvrir le fichier en mode �criture binaire
    if (!fichier) { // V�rifier si le fichier s'ouvre correctement
        perror("Erreur lors de l'ouverture du fichier");
        return -1; // Retourne -1 en cas d'�chec
    }

    if (fwrite(t, sizeof(ListeEtud), 1, fichier) != 1) { // �crire la structure dans le fichier
        perror("Erreur lors de l'�criture dans le fichier");
        fclose(fichier); // Fermer le fichier
        return -1; // Retourne -1 en cas d'�chec
    }

    fclose(fichier); // Fermer le fichier apr�s �criture
    return 0; // Retourne 0 en cas de succ�s
}

// Fonction pour charger les �tudiants depuis un fichier binaire
// Retourne 0 en cas de succ�s, -1 en cas d'�chec
int chargerEtudiantsBinaire(ListeEtud* t, const char* nomFichier) {
    FILE* fichier = fopen(nomFichier, "rb"); // Ouvrir le fichier en mode lecture binaire
    if (!fichier) { // V�rifier si le fichier s'ouvre correctement
        perror("Erreur lors de l'ouverture du fichier");
        return -1; // Retourne -1 en cas d'�chec
    }

    if (fread(t, sizeof(ListeEtud), 1, fichier) != 1) { // Lire la structure depuis le fichier
        perror("Erreur lors de la lecture du fichier");
        fclose(fichier); // Fermer le fichier
        return -1; // Retourne -1 en cas d'�chec
    }

    fclose(fichier); // Fermer le fichier apr�s lecture
    return 0; // Retourne 0 en cas de succ�s
}

// Fonction principale pour tester les fonctionnalit�s
int main() {
    ListeEtud liste; // D�claration de la liste des �tudiants
    liste.taille = 0; // Initialisation de la taille � 0

    // Ajout d'�tudiants pour test
    strcpy(liste.etudiants[0].matricule, "20230001"); // Matricule du 1er �tudiant
    strcpy(liste.etudiants[0].nom, "Yankam"); // Nom du 1er �tudiant
    strcpy(liste.etudiants[0].prenom, "Joel"); // Pr�nom du 1er �tudiant
    liste.etudiants[0].age = 20; // �ge du 1er �tudiant
    strcpy(liste.etudiants[0].filiere, "Informatique"); // Fili�re du 1er �tudiant
    liste.etudiants[0].niveau = 1; // Niveau du 1er �tudiant
    liste.taille++; // Incr�menter la taille

    strcpy(liste.etudiants[1].matricule, "20230002"); // Matricule du 2�me �tudiant
    strcpy(liste.etudiants[1].nom, "Takam"); // Nom du 2�me �tudiant
    strcpy(liste.etudiants[1].prenom, "Anne"); // Pr�nom du 2�me �tudiant
    liste.etudiants[1].age = 21; // �ge du 2�me �tudiant
    strcpy(liste.etudiants[1].filiere, "Informatique"); // Fili�re du 2�me �tudiant
    liste.etudiants[1].niveau = 1; // Niveau du 2�me �tudiant
    liste.taille++; // Incr�menter la taille

    // Affichage des �tudiants
    printf("Affichage des �tudiants :\n");
    afficherEtudiants(&liste);

    // Sauvegarde dans un fichier binaire
    const char* nomFichier = "etudiants.dat"; // Nom du fichier de sauvegarde
    if (sauvegarderEtudiantsBinaire(&liste, nomFichier) == 0) {
        printf("Sauvegarde r�ussie dans %s\n", nomFichier); // Message de succ�s
    }

    // Chargement depuis le fichier binaire
    ListeEtud listeChargee; // Nouvelle liste pour le chargement
    if (chargerEtudiantsBinaire(&listeChargee, nomFichier) == 0) {
        printf("Chargement r�ussi depuis %s\n", nomFichier); // Message de succ�s
        afficherEtudiants(&listeChargee); // Afficher les �tudiants charg�s
    }

    return 0; // Fin du programme
}
