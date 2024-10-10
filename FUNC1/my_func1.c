#include <stdlib.h>
#include <string.h>

// Calculates the length of a null-terminated string.
// Calcule la longueur d'une chaîne de caractères terminée par un caractère nul.

size_t strlen(const char *str) {
    size_t len = 0; // Initialize length counter to zero
    // Initialise le compteur de longueur à zéro

    // Iterate through the string until the null terminator is reached.
    // Parcourir la chaîne jusqu'à atteindre le caractère nul.
    while (str[len] != '\0') {
        len++; // Increment the length counter for each character
        // Incrémenter le compteur de longueur pour chaque caractère
    }

    return len; // Return the calculated length
    // Renvoyer la longueur calculée
}

// Creates a copy of the source string and returns it.
// Crée une copie de la chaîne source et la retourne.

// Parameters:
//   src: A pointer to the string to be copied.
//   src: Un pointeur vers la chaîne à copier.

// Returns:
//   A pointer to the newly allocated duplicate string, or NULL if memory allocation fails.
//   Un pointeur vers la nouvelle chaîne copiée, ou NULL en cas d'échec de l'allocation mémoire.
char *my_strdup(char const *src) {
    if (src == NULL) { // Check for null input
        // Vérifier si l'entrée est nulle
        return NULL; // Return NULL if the input string is null
        // Renvoyer NULL si la chaîne d'entrée est nulle
    }

    size_t len = strlen(src) + 1; // Calculate the length of the source string, including the null terminator
    // Calculer la longueur de la chaîne source, y compris le caractère nul

    char *dest = malloc(len); // Allocate memory for the duplicate string
    // Allouer de la mémoire pour la chaîne dupliquée

    if (dest == NULL) { // Check for memory allocation failure
        // Vérifier l'échec de l'allocation de mémoire
        return NULL; // Return NULL if memory allocation fails
        // Renvoyer NULL en cas d'échec d'allocation de mémoire
    }

    strcpy(dest, src); // Copy the source string to the destination string
    // Copier la chaîne source dans la chaîne de destination

    return dest; // Return a pointer to the newly created duplicate string
    // Renvoyer un pointeur vers la chaîne dupliquée nouvellement créée
}