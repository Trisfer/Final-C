#include <stdio.h>

void afficherMenu();
void ajouterPokemon();
void afficherPokemon();
void modifierPokemon();
void supprimerPokemon();
void afficherListePokemon();
void rechercherPokemon();
void trierPokemon();
void afficherTypePokemon();
void quitter();

typedef struct {
    char nom[20];
    int niveau;
    char type[20];
} Pokemon;

Pokemon listePokemon[15];
int nombrePokemon = 0;

int main() {
    int choix;

    do {
        afficherMenu();
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterPokemon();
                break;
            case 2:
                afficherPokemon();
                break;
            case 3:
                modifierPokemon();
                break;
            case 4:
                supprimerPokemon();
                break;
            case 5:
                afficherListePokemon();
                break;
            case 6:
                rechercherPokemon();
                break;
            case 7:
                trierPokemon();
                break;
            case 8:
                afficherTypePokemon();
                break;
            case 9:
                quitter();
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }
    } while (choix != 9);

    return 0;
}

void afficherMenu() {
    printf("----- Menu -----\n");
    printf("1. Ajouter un Pokemon\n");
    printf("2. Afficher un Pokemon\n");
    printf("3. Modifier un Pokemon\n");
    printf("4. Supprimer un Pokémon\n");
    printf("5. Afficher la liste des Pokemon\n");
    printf("6. Rechercher un Pokemon\n");
    printf("7. Trier les Pokemon\n");
    printf("8. Afficher les Pokemon par type\n");
    printf("9. Quitter\n");
    printf("Votre choix : ");
}

void ajouterPokemon() {
    if (nombrePokemon >= 151) {
        printf("La liste des Pokemon est pleine. Impossible d'ajouter un nouveau Pokemon.\n");
        return;
    }

    Pokemon nouveauPokemon;

    printf("Nom du Pokemon : ");
    scanf("%s", nouveauPokemon.nom);

    printf("Niveau du Pokemon : ");
    scanf("%d", &nouveauPokemon.niveau);

    printf("Type du Pokemon : ");
    scanf("%s", nouveauPokemon.type);

    listePokemon[nombrePokemon] = nouveauPokemon;
    nombrePokemon++;

    printf("Le Pokemon a ete ajoute avec succes.\n");
}

void afficherPokemon() {
    if (nombrePokemon == 0) {
        printf("Aucun Pokemon dans la liste.\n");
        return;
    }

    int index;
    printf("Indice du Pokemon à afficher (entre 0 et %d) : ", nombrePokemon - 1);
    scanf("%d", &index);

    if (index < 0 || index >= nombrePokemon) {
        printf("Indice invalide.\n");
        return;
    }

    Pokemon pokemon = listePokemon[index];

    printf("Nom : %s\n", pokemon.nom);
    printf("Niveau : %d\n", pokemon.niveau);
    printf("Type : %s\n", pokemon.type);
}

void modifierPokemon() {
    if (nombrePokemon == 0) {
        printf("Aucun Pokemon dans la liste.\n");
        return;
    }

    int index;
    printf("Indice du Pokemon à modifier (entre 0 et %d) : ", nombrePokemon - 1);
    scanf("%d", &index);

    if (index < 0 || index >= nombrePokemon) {
        printf("Indice invalide.\n");
        return;
    }

    Pokemon* pokemon = &listePokemon[index];

    printf("Nouveau nom du Pokemon : ");
    scanf("%s", pokemon->nom);

    printf("Nouveau niveau du Pokemon : ");
    scanf("%d", &pokemon->niveau);

    printf("Nouveau type du Pokemon : ");
    scanf("%s", pokemon->type);

    printf("Le Pokemon a ete modifie avec succes.\n");
}

void supprimerPokemon() {
    if (nombrePokemon == 0) {
        printf("Aucun Pokemon dans la liste.\n");
        return;
    }

    int index;
    printf("Indice du Pokemon a supprimer (entre 0 et %d) : ", nombrePokemon - 1);
    scanf("%d", &index);

    if (index < 0 || index >= nombrePokemon) {
        printf("Indice invalide.\n");
        return;
    }

    for (int i = index; i < nombrePokemon - 1; i++) {
        listePokemon[i] = listePokemon[i + 1];
    }

    nombrePokemon--;

    printf("Le Pokemon à ete supprime avec succes.\n");
}

void afficherListePokemon() {
    if (nombrePokemon == 0) {
        printf("Aucun Pokemon dans la liste.\n");
        return;
    }

    printf("----- Liste des Pokemon -----\n");

    for (int i = 0; i < nombrePokemon; i++) {
        Pokemon pokemon = listePokemon[i];

        printf("Indice : %d\n", i);
        printf("Nom : %s\n", pokemon.nom);
        printf("Niveau : %d\n", pokemon.niveau);
        printf("Type : %s\n", pokemon.type);
        printf("-----------------------------\n");
    }
}

void rechercherPokemon() {
    if (nombrePokemon == 0) {
        printf("Aucun Pokemon dans la liste.\n");
        return;
    }

    char nomRecherche[20];
    printf("Nom du Pokemon à rechercher : ");
    scanf("%s", nomRecherche);

    int trouve = 0;

    for (int i = 0; i < nombrePokemon; i++) {
        Pokemon pokemon = listePokemon[i];

        if (strcmp(pokemon.nom, nomRecherche) == 0) {
            printf("Pokemon trouve :\n");
            printf("Indice : %d\n", i);
            printf("Nom : %s\n", pokemon.nom);
            printf("Niveau : %d\n", pokemon.niveau);
            printf("Type : %s\n", pokemon.type);
            printf("-----------------------------\n");

            trouve = 1;
            break;
        }
    }

    if (!trouve) {
        printf("Aucun Pokemon trouve avec ce nom.\n");
    }
}

void trierPokemon() {
    if (nombrePokemon == 0) {
        printf("Aucun Pokemon dans la liste.\n");
        return;
    }

    // Tri des Pokémon par niveau (ordre croissant)
    for (int i = 0; i < nombrePokemon - 1; i++) {
        for (int j = 0; j < nombrePokemon - i - 1; j++) {
            if (listePokemon[j].niveau > listePokemon[j + 1].niveau) {
                Pokemon temp = listePokemon[j];
                listePokemon[j] = listePokemon[j + 1];
                listePokemon[j + 1] = temp;
            }
        }
    }

    printf("La liste des Pokemon a ete triee par niveau.\n");
}

void afficherTypePokemon() {
    if (nombrePokemon == 0) {
        printf("Aucun Pokemon dans la liste.\n");
        return;
    }

    char typeRecherche[20];
    printf("Type de Pokemon à afficher : ");
    scanf("%s", typeRecherche);

    printf("----- Pokemon de type %s -----\n", typeRecherche);

    int trouve = 0;

    for (int i = 0; i < nombrePokemon; i++) {
        Pokemon pokemon = listePokemon[i];

        if (strcmp(pokemon.type, typeRecherche) == 0) {
            printf("Indice : %d\n", i);
            printf("Nom : %s\n", pokemon.nom);
            printf("Niveau : %d\n", pokemon.niveau);
            printf("-----------------------------\n");

            trouve = 1;
        }
    }

    if (!trouve) {
        printf("Aucun Pokemon de ce type trouve.\n");
    }
}

void quitter() {
    printf("Au revoir !\n");
}
