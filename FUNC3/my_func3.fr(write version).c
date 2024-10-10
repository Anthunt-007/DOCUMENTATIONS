#include <unistd.h>

// Displays the content of an array of words, one word per line.
int my_show_word_array(char *const *tab) {
    int i = 0;

    // Iterates through the array until a null pointer is encountered, indicating the end of the array.
    while (tab[i] != NULL) {
        // Writes the current word to standard output.
        write(1, tab[i], my_strlen(tab[i]));

        // Writes a newline character to standard output.
        write(1, "\n", 1);

        // Increments the index to the next word.
        i++;
    }

    // Returns 0 to indicate successful execution.
    return 0;
}