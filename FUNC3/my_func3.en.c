#include <unistd.h>

// Displays a single character to standard output.
void my_putchar(char c) {
    write(1, &c, 1);
}

// Displays the content of an array of words, one word per line.
int my_show_word_array(char *const *tab) {
    int i = 0;

    // Iterates through the array until a null pointer is encountered, indicating the end of the array.
    while (tab[i] != NULL) {
        // Writes each character of the current word to standard output using my_putchar.
        for (int j = 0; tab[i][j] != '\0'; j++) {
            my_putchar(tab[i][j]);
            // While tab[i] indicates the word, as my putchar only displays characters, we have to displays 
            //all the character of the selected word (tab[i]). That's where the j comes in.
            // it holds characters of the selected word which is printed. After one iteration of the loop,
            // it is incremented, meaning that it takes the following character of the word until there are 
            // no more character in the word. Then the first for loop moves to an other word and the process is the same.
        }

        // Writes a newline character to standard output.
        my_putchar('\n');

        // Increments the index to the next word.
        i++;
    }

    // Returns 0 to indicate successful execution.
    return 0;
}