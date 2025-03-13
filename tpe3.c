#include <stdio.h>
#include <stdlib.h>

void affiche_grille(char tab[6][7]);
int insertion(char tab[6][7], char joueur, int colonne);
int fin_jeu(char tab[6][7]);
void efface();

int main()
{

    char tab[6][7];
    int i, j, res, compteur;
    char c;
    compteur = 0;
    char joueur;
    int colonne;

    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 7; j++)
        {
            tab[i][j] = '-'; // initiallisena
        }
    }
    while (1)
    {
        efface();
        menu();

        if (compteur % 2 == 0)
        {
            joueur = 'x';

            printf("c'est au tour du joueur 1");
            printf("\n");
        }
        else
        {

            joueur = 'o';

            printf("c'est au tour du joueur 2");
            printf("\n");
        }
        affiche_grille(tab); // grille misy mis a jour
        printf("choix du colonne?");
        scanf("%d", &colonne);
        colonne = colonne - 1;

        res = insertion(tab, joueur, colonne); // mi inserer amzay

        if (res == 1)
        {
            efface();
            menu();
            printf("Pion inséré avec succès\n");
        }

        else if (res == 2)
        {
            printf("Colonne pleine !");
            continue; // Recommencer le tour si la colonne est pleine
        }

        affiche_grille(tab);
        if (fin_jeu(tab) == 1)
        {
            printf(" BRAVO !!!le joueur %c a gagne....\n", joueur);
            break;
        }
        compteur++;
        printf("Appuyez sur Entrée pour continuer...\n");
        c = getchar();
    }
    return 0;
}

/*affiche_grille(tab);
    res = insertion(tab, 'x', 4);
    if (res == 1)
    {
        printf("au joueur suivant");
        printf("\n");
    }
    else
    {
        printf("colonne pleine");
        printf("\n");
    }

    affiche_grille(tab);
    res = insertion(tab, 'o', 2); // Joueur 2 joue sur la colonne 3

    if (res == 1)
    {
        printf("au joueur suivant\n");
    }
    else
    {
        printf("colonne pleine");
    }
    affiche_grille(tab);

    res = insertion(tab, 'x', 4);
    if (res == 1)
    {
        printf("au joueur suivant");
        printf("\n");
    }
    else
    {
        printf("colonne pleine");
        printf("\n");
    }
    return 0;
}*/

void affiche_grille(char tab[6][7])
{
    int i, j;
    printf(" 1  2  3  4  5  6  7\n"); // Affiche les indices des colonnes
    for (j = 0; j < 6; j++)
    {
        for (i = 0; i < 7; i++)
        {
            printf("|%c|", tab[j][i]);
        }
        printf("\n");
    }
}
int insertion(char tab[6][7], char joueur, int colonne)
{
    int i;
    {

        if (tab[0][colonne] == 'x' || tab[0][colonne] == 'o') // mi verifier

            return -1; //  feno le colonne
    }
    for (i = 5; i >= 0; i--) // ligne ambamy de miakatra
    {
        if (tab[i][colonne] == '-')
        {
            tab[i][colonne] = joueur;
            return 1; // vita le insertion
        }
    }
    return -1; // feno
}
int fin_jeu(char tab[6][7])
{
    int i, j;
    for (i = 0; i < 6; i++) // mitsivalana
    {
        for (j = 0; j < 4; j++)
        {
            if (tab[i][j] != '-' && tab[i][j] == tab[i][j + 1] && tab[i][j] == tab[i][j + 2] && tab[i][j] == tab[i][j + 3])
            {
                return 1; // mandresy
            }
        }
    }
    for (i = 0; i < 3; i++) // midina
    {
        for (j = 0; j < 4; j++)
        {
            if (tab[i][j] != '-' && tab[i][j] == tab[i + 1][j + 1] && tab[i][j] == tab[i + 2][j + 2] && tab[i][j] == tab[i + 3][j + 3])
            {
                return 1; // Un joueur a gagné
            }
        }
    }
    for (j = 0; j < 7; j++) // mitsangana
    {
        for (i = 0; i < 3; i++) // verif sequence de 4 pions
        {
            if (tab[i][j] != '-' && tab[i][j] == tab[i + 1][j] && tab[i][j] == tab[i + 2][j] && tab[i][j] == tab[i + 3][j])
            {
                return 1; // Un joueur a gagné
            }
        }
    }

    for (i = 3; i < 6; i++) // miakatra
    {
        for (j = 0; j < 4; j++)
        {
            if (tab[i][j] != '-' && tab[i][j] == tab[i - 1][j + 1] && tab[i][j] == tab[i - 2][j + 2] && tab[i][j] == tab[i - 3][j + 3])
            {
                return 1; // Un joueur a gagné
            }
        }
    }

    return 0; // tsisy nanresy
}
void efface()
{
    system("clear");
}

void menu()
{
    printf("***************************\n");
    printf("******JEU PUISSANCE 4******\n");
    printf("***************************\n");
    printf("\n");
    printf("\n");
}