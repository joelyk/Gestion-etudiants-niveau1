// Auteur : Mr Joel YK
// Site web : PandaCodeur.com
// WhatsApp : +237 652027193
// Enoncé :
// Pour l’enregistrement des étudiants du niveau 1 Informatique, l’autorité administrative décide de faire appel à vous en tant qu’informaticien pour le stockage de ces étudiants.
// Les opérations souhaitées pour le moment sont la consultation, l’enregistrement des étudiants, et leur gestion dans un fichier binaire.
// Pour une simulation de ce projet, il vous est demandé de prendre un échantillon de 500 étudiants.
// Ce programme permet de réaliser les tâches suivantes :
// - Consultation des étudiants
// - Enregistrement des étudiants
// - Gestion dans un fichier binaire

#include <stdio.h> // Inclusion de la bibliothèque standard pour les entrées/sorties
#include <stdlib.h> // Inclusion de la bibliothèque standard pour la gestion de la mémoire
#include <string.h> // Inclusion de la bibliothèque pour la manipulation des chaînes de caractères

#define MAX_ETUDIANTS 500 // Définition de la taille maximale des étudiants

// Définition de la structure pour un étudiant
typedef struct {
    char matricule[20]; // Matricule de l'étudiant (chaîne de 20 caractères)
    char nom[20]; // Nom de l'étudiant (chaîne de 20 caractères)
    char prenom[20]; // Prénom de l'étudiant (chaîne de 20 caractères)
    int age; // Âge de l'étudiant
    char filiere[20]; // Filière de l'étudiant (chaîne de 20 caractères)
    int niveau; // Niveau de l'étudiant
} Etudiant;

// Définition de la structure pour la liste des étudiants
typedef struct {
    Etudiant etudiants[MAX_ETUDIANTS]; // Tableau des étudiants
    int taille; // Taille actuelle de la liste des étudiants
} ListeEtud;

// Fonction pour rechercher un étudiant par matricule
// Retourne l'index de l'étudiant ou -1 si non trouvé
int rechercherEtudiant(ListeEtud* t, const char* mat) {
    for (int i = 0; i < t->taille; i++) { // Parcourir tous les étudiants
        if (strcmp(t->etudiants[i].matricule, mat) == 0) { // Comparer les matricules
            return i; // Retourne l'index si trouvé
        }
    }
    return -1; // Retourne -1 si non trouvé
}

// Procédure pour afficher les informations des étudiants
void afficherEtudiants(ListeEtud* t) {
    for (int i = 0; i < t->taille; i++) { // Parcourir tous les étudiants
        Etudiant* e = &t->etudiants[i]; // Récupérer un étudiant
        printf("Matricule : %s\n", e->matricule); // Afficher le matricule
        printf("Nom : %s\n", e->nom); // Afficher le nom
        printf("Prénom : %s\n", e->prenom); // Afficher le prénom
        printf("Âge : %d\n", e->age); // Afficher l'âge
        printf("Filière : %s\n", e->filiere); // Afficher la filière
        printf("Niveau : %d\n", e->niveau); // Afficher le niveau
        printf("-----------------------------\n"); // Séparateur entre les étudiants
    }
}

// Fonction pour sauvegarder les étudiants dans un fichier binaire
// Retourne 0 en cas de succès, -1 en cas d'échec
int sauvegarderEtudiantsBinaire(ListeEtud* t, const char* nomFichier) {
    FILE* fichier = fopen(nomFichier, "wb"); // Ouvrir le fichier en mode écriture binaire
    if (!fichier) { // Vérifier si le fichier s'ouvre correctement
        perror("Erreur lors de l'ouverture du fichier");
        return -1; // Retourne -1 en cas d'échec
    }

    if (fwrite(t, sizeof(ListeEtud), 1, fichier) != 1) { // Écrire la structure dans le fichier
        perror("Erreur lors de l'écriture dans le fichier");
        fclose(fichier); // Fermer le fichier
        return -1; // Retourne -1 en cas d'échec
    }

    fclose(fichier); // Fermer le fichier après écriture
    return 0; // Retourne 0 en cas de succès
}

// Fonction pour charger les étudiants depuis un fichier binaire
// Retourne 0 en cas de succès, -1 en cas d'échec
int chargerEtudiantsBinaire(ListeEtud* t, const char* nomFichier) {
    FILE* fichier = fopen(nomFichier, "rb"); // Ouvrir le fichier en mode lecture binaire
    if (!fichier) { // Vérifier si le fichier s'ouvre correctement
        perror("Erreur lors de l'ouverture du fichier");
        return -1; // Retourne -1 en cas d'échec
    }

    if (fread(t, sizeof(ListeEtud), 1, fichier) != 1) { // Lire la structure depuis le fichier
        perror("Erreur lors de la lecture du fichier");
        fclose(fichier); // Fermer le fichier
        return -1; // Retourne -1 en cas d'échec
    }

    fclose(fichier); // Fermer le fichier après lecture
    return 0; // Retourne 0 en cas de succès
}

// Fonction principale pour tester les fonctionnalités
int main() {
    ListeEtud liste; // Déclaration de la liste des étudiants
    liste.taille = 0; // Initialisation de la taille à 0

    // Ajout d'étudiants pour test
    strcpy(liste.etudiants[0].matricule, "20230001"); // Matricule du 1er étudiant
    strcpy(liste.etudiants[0].nom, "Yankam"); // Nom du 1er étudiant
    strcpy(liste.etudiants[0].prenom, "Joel"); // Prénom du 1er étudiant
    liste.etudiants[0].age = 20; // Âge du 1er étudiant
    strcpy(liste.etudiants[0].filiere, "Informatique"); // Filière du 1er étudiant
    liste.etudiants[0].niveau = 1; // Niveau du 1er étudiant
    liste.taille++; // Incrémenter la taille

    strcpy(liste.etudiants[1].matricule, "20230002"); // Matricule du 2ème étudiant
    strcpy(liste.etudiants[1].nom, "Takam"); // Nom du 2ème étudiant
    strcpy(liste.etudiants[1].prenom, "Anne"); // Prénom du 2ème étudiant
    liste.etudiants[1].age = 21; // Âge du 2ème étudiant
    strcpy(liste.etudiants[1].filiere, "Informatique"); // Filière du 2ème étudiant
    liste.etudiants[1].niveau = 1; // Niveau du 2ème étudiant
    liste.taille++; // Incrémenter la taille

    // Affichage des étudiants
    printf("Affichage des étudiants :\n");
    afficherEtudiants(&liste);

    // Sauvegarde dans un fichier binaire
    const char* nomFichier = "etudiants.dat"; // Nom du fichier de sauvegarde
    if (sauvegarderEtudiantsBinaire(&liste, nomFichier) == 0) {
        printf("Sauvegarde réussie dans %s\n", nomFichier); // Message de succès
    }

    // Chargement depuis le fichier binaire
    ListeEtud listeChargee; // Nouvelle liste pour le chargement
    if (chargerEtudiantsBinaire(&listeChargee, nomFichier) == 0) {
        printf("Chargement réussi depuis %s\n", nomFichier); // Message de succès
        afficherEtudiants(&listeChargee); // Afficher les étudiants chargés
    }

    return 0; // Fin du programme
}
