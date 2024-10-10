#include <stdlib.h>
#include <unistd.h>

// Affiche une chaîne de caractères sur la sortie standard.
// Prend en entrée un pointeur vers un tableau de caractères (chaîne).
// Parcourt la chaîne caractère par caractère, en écrivant chaque caractère sur la sortie standard à l'aide de l'appel système `write`.
void my_putstr(char *str) {
    // Tant que le caractère courant n'est pas le caractère de fin de chaîne (indicateur de fin de chaîne), continuez la boucle.
    while (*str != '\0') {
        // Écrivez le caractère courant sur la sortie standard (descripteur de fichier 1).
        // L'expression `str++` incrémente le pointeur pour pointer au caractère suivant.
        write(1, str++, 1);
    }
}

// Calcule la longueur d'une chaîne de caractères.
// Prend en entrée un pointeur vers un tableau de caractères constant (chaîne).
// Parcourt la chaîne caractère par caractère jusqu'à ce qu'il rencontre le caractère de fin de chaîne.
// Compte le nombre de caractères rencontrés et renvoie cette valeur en tant que longueur de la chaîne.
int my_strlen(const char *str) {
    int len = 0;

    // Tant que le caractère courant n'est pas le caractère de fin de chaîne :
    while (*str++ != '\0') {
        // Incrémente le compteur de longueur.
        len++;
    }

    return len;
}

// Concatène deux chaînes de caractères.
// Prend en entrée des pointeurs vers deux tableaux de caractères (chaînes).
// Trouve le caractère de fin de chaîne dans la première chaîne (destination) et copie les caractères de la deuxième chaîne (source) à la fin de la première chaîne.
// Ajoute un caractère de fin de chaîne à la fin de la chaîne concaténée.
// Renvoie un pointeur vers la chaîne concaténée, qui est le même que la chaîne de destination originale.
char *my_strcat(char *dest, const char *src) {
    char *ptr = dest;

    // Trouve le caractère de fin de chaîne dans la chaîne de destination.
    while (*ptr != '\0') {
        ptr++;
    }

    // Copie les caractères de la chaîne source dans la chaîne de destination.
    while (*src != '\0') {
        *ptr++ = *src++;
    }

    // Ajoute un caractère de fin de chaîne à la fin de la chaîne concaténée.
    *ptr = '\0';

    return dest;
}

// Concatène tous les arguments de la ligne de commande en une seule chaîne de caractères séparée par des sauts de ligne.
// Prend en entrée le nombre d'arguments de la ligne de commande et un tableau de pointeurs vers les arguments.
// Calcule la longueur totale de la chaîne concaténée, en tenant compte des sauts de ligne.
// Alloue de la mémoire pour la chaîne concaténée.
// Initialise la chaîne concaténée en tant que chaîne vide.
// Parcourt les arguments de la ligne de commande, en concaténant chaque argument et un saut de ligne à la chaîne de résultat.
// Renvoie un pointeur vers la chaîne concaténée.
char *concat_params(int argc, char **argv) {
    int i, total_len = 0;
    char *result;

    // Calcule la longueur totale de la chaîne concaténée, en tenant compte des sauts de ligne.
    for (i = 0; i < argc; i++) {
        total_len += my_strlen(argv[i]) + 1; // Compte le saut de ligne
    }

    // Alloue de la mémoire pour la chaîne concaténée.
    result = (char *)malloc(total_len);
    if (result == NULL) {
        return NULL; // Échec de l'allocation de mémoire
    }

    // Initialise la chaîne concaténée en tant que chaîne vide.
    result[0] = '\0';

    // Concatène chaque argument et un saut de ligne à la chaîne de résultat.
    for (i = 0; i < argc; i++) {
        my_strcat(result, argv[i]);
        my_strcat(result, "\n");
    }

    return result;
}

// La fonction principale est le point d'entrée du programme.
int main(int ac, char **av) {
    // Concatène les arguments de la ligne de commande en une seule chaîne de caractères.
    char *concatenated_string = concat_params(ac, av);

    // Affiche la chaîne concaténée sur la sortie standard.
    my_putstr(concatenated_string);

    return (EXIT_SUCCESS);
}