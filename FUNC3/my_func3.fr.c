#include <unistd.h>

// Affiche un seul caractère sur la sortie standard.
void my_putchar(char c) {
    write(1, &c, 1);
}

// Affiche le contenu d'un tableau de mots, un mot par ligne.
int my_show_word_array(char *const *tab) {
    int i = 0;

    // Parcourt le tableau jusqu'à ce qu'un pointeur nul soit rencontré, indiquant la fin du tableau.
    while (tab[i] != NULL) {
        // Écrit chaque caractère du mot courant sur la sortie standard en utilisant my_putchar.
        for (int j = 0; tab[i][j] != '\0'; j++) {
            my_putchar(tab[i][j]);
            // Alors que tab[i] indique le mot, puisque my_putchar affiche uniquement des caractères, nous devons afficher tous les caractères du mot sélectionné (tab[i]). C'est là qu'intervient j.
            // Il contient les caractères du mot sélectionné qui sont imprimés. Après une itération de la boucle,
            // il est incrémenté, ce qui signifie qu'il prend le caractère suivant du mot jusqu'à ce qu'il n'y ait plus de caractère dans le mot. Ensuite, la première boucle for passe à un autre mot et le processus est le même.
        }

        // Écrit un caractère de nouvelle ligne sur la sortie standard.
        my_putchar('\n');

        // Incrémente l'index pour passer au mot suivant.
        i++;
    }

    // Renvoie 0 pour indiquer l'exécution réussie.
    return 0;
}