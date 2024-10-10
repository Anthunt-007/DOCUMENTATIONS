#include <stdlib.h> // Inclusion pour les fonctions d'allocation de mémoire (malloc, free)
#include <unistd.h> // Inclusion pour la fonction write
#include <stdio.h>  // Inclusion pour la fonction printf

// Fonction personnalisée pour vérifier si un caractère est alphabétique
int my_str_isalpha(char c) {
    // Vérifie si le caractère est entre 'A' et 'Z' ou 'a' et 'z'
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

// Fonction personnalisée pour vérifier si un caractère est numérique
int my_str_isnum(char c) {
    // Vérifie si le caractère est entre '0' et '9'
    return (c >= '0' && c <= '9');
}

// Fonction personnalisée pour vérifier si un caractère est alphanumérique
int is_alnum_char(char c) {
    // Un caractère est alphanumérique s'il est soit alphabétique soit numérique
    return my_str_isalpha(c) || my_str_isnum(c);
}

// Fonction strncpy personnalisée qui retourne un pointeur de caractère
char *my_strncpy(char *dest, const char *src, int n) {
    int i; // Déclare le compteur de boucle

    // Copie les caractères de src vers dest
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i]; // Copie caractère par caractère de src vers dest
    }

    // Remplit l'espace restant dans dest avec des caractères nuls
    for (; i < n; i++) {
        dest[i] = '\0'; // S'assure que la destination est terminée par un caractère nul
    }
    return dest; // Retourne le pointeur de destination
}

// Fonction d'assistance pour allouer de la mémoire et copier un mot
char *copy_word(const char *start, int len) {
    // Alloue de la mémoire pour le nouveau mot (len + 1 pour le terminateur nul)
    char *word = (char *)malloc((len + 1) * sizeof(char));
    if (!word) return NULL; // Retourne NULL si l'allocation de mémoire échoue

    // Utilise la fonction strncpy personnalisée pour copier les caractères de start vers word
    my_strncpy(word, start, len);
    word[len] = '\0'; // Termine la chaîne par un caractère nul
    return word; // Retourne le mot nouvellement créé
}

// Fonction pour compter le nombre de mots dans une chaîne
int count_words(const char *str) {
    int count = 0; // Initialise le compteur de mots
    int in_word = 0; // Indicateur pour savoir si nous sommes actuellement dans un mot

    // Itère à travers chaque caractère de la chaîne
    while (*str != '\0') {
        // Vérifie si le caractère est alphanumérique
        if (is_alnum_char(*str)) {
            if (!in_word) { // Si nous n'étions pas dans un mot, nous en avons trouvé un
                in_word = 1; // Définit le drapeau in_word à vrai
                count++; // Incrémente le compteur de mots
            }
        } else {
            in_word = 0; // Si nous rencontrons un caractère non alphanumérique, réinitialise le drapeau in_word
        }
        str++; // Passe au caractère suivant de la chaîne
    }
    return count; // Retourne le nombre total de mots trouvés
}

// Fonction pour diviser la chaîne en un tableau de mots
char **my_str_to_word_array(const char *str) {
    int words_count = count_words(str); // Compte combien de mots sont dans la chaîne

    // Alloue de la mémoire pour le tableau de pointeurs de mots (plus un pour le terminateur NULL)
    char **word_array = (char **)malloc((words_count + 1) * sizeof(char *));
    if (!word_array) return NULL; // Retourne NULL si l'allocation de mémoire échoue

    int i = 0; // Initialise l'index pour word_array
    int in_word = 0; // Indicateur pour suivre si nous sommes actuellement dans un mot
    const char *word_start = NULL; // Pointeur pour marquer le début d'un mot
    int word_length = 0; // Variable pour suivre la longueur du mot actuel

    // Itère à nouveau à travers la chaîne pour extraire les mots
    while (*str != '\0') {
        if (is_alnum_char(*str)) { // Si le caractère est alphanumérique
            if (!in_word) { // Si nous n'étions pas dans un mot
                in_word = 1; // Nous avons trouvé un nouveau mot
                word_start = str; // Marque le début du mot
                word_length = 1; // Initialise la longueur du mot à 1
            } else {
                word_length++; // Incrémente la longueur du mot actuel
            }
        } else {
            if (in_word) { // Si nous étions dans un mot et maintenant nous rencontrons un séparateur
                word_array[i] = copy_word(word_start, word_length); // Copie le mot dans le tableau
                if (!word_array[i]) return NULL; // Gère l'échec de l'allocation de mémoire
                i++; // Passe à l'index suivant dans word_array
            }
            in_word = 0; // Réinitialise le drapeau in_word
        }
        str++; // Passe au caractère suivant de la chaîne
    }

    // Gère le cas où le dernier caractère fait partie d'un mot
    if (in_word) {
        word_array[i] = copy_word(word_start, word_length); // Copie le dernier mot dans le tableau
        if (!word_array[i]) return NULL; // Gère l'échec de l'allocation de mémoire
        i++; // Incrémente l'index
    }
    word_array[i] = NULL; // Termine le tableau de mots par NULL
    return word_array; // Retourne le tableau de mots
}

// Exemple de scénario:
// Pour l'entrée "Hello, world!", la fonction fonctionne comme suit:
// - Initialement, count = 0, in_word = 0
// - Premier caractère 'H': est alphanumérique, count passe à 1, in_word = 1
// - Caractères 'e', 'l', 'l', 'o': restent dans le mot, count reste à 1
// - Caractère ',': pas alphanumérique, in_word = 0
// - Caractère ' ': pas alphanumérique, in_word reste à 0
// - Caractère 'w': est alphanumérique, count passe à 2, in_word = 1
// - Caractères 'o', 'r', 'l', 'd': restent dans le mot, count reste à 2
// - Caractère '!': pas alphanumérique, in_word = 0
// Compteur total de mots = 2 (mots: "Hello" et "world")
// Imprime chaque mot et libère la mémoire allouée

// Fonction principale pour tester la fonction de division des mots
int main() {
    char input[] = "Hello, world! This is a test."; // Chaîne d'entrée pour le test
    char **words = my_str_to_word_array(input); // Divise la chaîne en mots

    // Vérifie si le tableau de mots a été créé avec succès
    if (words) {
        // Itère à travers le tableau et imprime chaque mot
        for (int i = 0; words[i] != NULL; i++) {
            printf("Word %d: %s\n", i + 1, words[i]); // Imprime le mot
            free(words[i]); // Libère chaque mot alloué
        }
        free(words); // Libère le tableau de pointeurs de mots
    }
    return 0; // Retourne le succès
}
