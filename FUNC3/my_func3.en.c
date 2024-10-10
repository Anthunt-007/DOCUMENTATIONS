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
            // While tab[i] indicates the word, as my putchar only displays characters, we have to display
            // all the characters of the selected word (tab[i]). That's where the j comes in.
            // It holds characters of the selected word which is printed. After one iteration of the loop,
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

// Main function
int main() {
    // Array of words to display
    char * test_word_array [] = {"The", " Answer ", "to", "the", " Great ", " Question ...", "Of",
                                "Life ,", "the", " Universe ", " and", " Everything ...", "Is ...", "Forty -two ,", 0};

    // Displays the content of the word array
    my_show_word_array(test_word_array);

    return 0;
}