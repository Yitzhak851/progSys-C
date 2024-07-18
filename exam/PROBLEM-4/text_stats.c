#include <stdio.h>
#include <string.h>


struct text_stats {
    char* title;
    int numLines;
    int numWords;
    int numLetters;
};
typedef struct text_stats* TextStats;


// (8-points)  4.1- Implement the function newTextStats that creates a new TextStats object and initializes its fields.
TextStats newTextStats(char* title, int numLines, int numWords, int numLetters) {
    TextStats newTextStats = malloc(sizeof(struct text_stats));
    if (newTextStats == NULL) {
        return NULL;
    }
    newTextStats->title = malloc(strlen(title) + 1);
    if (newTextStats->title == NULL) {
        free(newTextStats);
        return NULL;
    }
    strcpy(newTextStats->title, title);
    newTextStats->numLines = 0;
    newTextStats->numWords = 0;
    newTextStats->numLetters = 0;
    return newTextStats;
}

// (4-points)  4.2- Implement the function freeTextStats that frees the memory allocated for a TextStats object.
void freeTextStats(TextStats textStats) {
    
    // my code here
    // TextStats textPointer = textStats;
    // if (textPointer != NULL) {
    //     free(textPointer->title); == isMissing
    //     free(textPointer);
    // }

    // correct code here
    free(textStats->title);
    free(textStats);
}
