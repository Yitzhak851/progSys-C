#include <stdio.h>
#define BITS_PER_ASI_BLOCK 6

int  charToASI(char ch);
char ASItoChar(int ASIval);
int  getASIblock(int newWord, int ind);
int  isWordFull(int newWord);
int  newWordType(int newWord);
int  appendWordChar(int newWord, char ch);
void printNewWord(int newWord);

int charToASI(char ch) {
    if (ch == '.') {
        return 1;
    } else if (ch >= 'A' && ch <= 'Z') {
        return ch - 'A' + 2;
    } else if (ch >= 'a' && ch <= 'z') {
        return ch - 'a' + 28;
    } else if (ch >= '0' && ch <= '9') {
        return ch - '0' + 54;
    }
    return -1;
}

char ASItoChar(int ASIval) {
    int a, b;
    if (ASIval < 1 || ASIval > 63) return '!'; // If ASIval is out of bounds, return '!'
    a = ((ASIval == 1) ? 0 : (ASIval >= 2 && ASIval <= 27) ? 1 : (ASIval >= 28 && ASIval <= 53) ? 2 : 3);
    b = ((a == 0) ? 0 : (a == 1) ? ASIval - 2 : (a == 2) ? ASIval - 28 : ASIval - 54);
    switch (a) {
        case (0): // case 1 (".")
            return '.';
        case (1): // ASI:[2-27] (A-Z) ASCII:[65-90]
            return a + 'A';
        case (2): // ASI:[28-53] (a-z) ASCII:[97-122]
            return b + 'a';
        case (3): // ASI:[54-63] (0-9) ASCII:[48-57]
            return b + '0';
        default:
            break;
    } // end of switch
    return '!';
}

int getASIblock(int newWord, int ind) {
    return (newWord>>ind*BITS_PER_ASI_BLOCK)%(1<<BITS_PER_ASI_BLOCK);
}

int isWordFull(int newWord) {
    return !!(getASIblock(newWord,((8*(sizeof(int))/BITS_PER_ASI_BLOCK)-1)));
}

int newWordType(int newWord) {
    int ASIval=0, ind=0, type=ASIval;
    for(ind=0; ind*BITS_PER_ASI_BLOCK<8*sizeof(int); ind++) {
        ASIval = getASIblock(newWord, ind);
        if (ASIval == 0) {
            break;
        } else if (ASIval == 1) {
            continue; // ignore period characters
        }
        // isLetters
        if (ASIval >= 2 && ASIval <= 53) {
            if (type == 2 || type == 3) {
                type = 3; // isLetters && isDigits
            } else {
                type = 1; // isLetters
            }
        // isDigits
        } else if (ASIval >= 54 && ASIval <= 63) {
            if (type == 1 || type == 3) {
                type = 3; // isLetters && isDigits
            } else {
                type = 2; // isDigits
            }
        }
    } // end of for
    return type;
}

int appendWordChar(int newWord, char ch) {
    int ASIval = charToASI(ch);
    if (ASIval == -1) {
        return newWord; // Invalid character
    }
    int ind = 0;
    while (getASIblock(newWord, ind) != 0 && ind * BITS_PER_ASI_BLOCK < 8 * sizeof(int)) {
        ind++;
    }
    if (ind * BITS_PER_ASI_BLOCK >= 8 * sizeof(int)) {
        return newWord; // Word is full
    }
    // Check if it's trying to append a non-period character to the final block
    if (ind * BITS_PER_ASI_BLOCK + BITS_PER_ASI_BLOCK >= 8 * sizeof(int) && ASIval != 1) {
        return newWord; // Only allow periods in the final block
    }
    return newWord | (ASIval << (ind * BITS_PER_ASI_BLOCK));
}

void printNewWord(int newWord) {
    int ASIval = 0, ind = 0;
    char ch;
    int lastCharPeriod = 0;
    for (ind = 0; ind * BITS_PER_ASI_BLOCK < 8 * sizeof(int); ind++) {
        ASIval = getASIblock(newWord, ind);
        if (ASIval == 0) {
            break;
        }
        ch = ASItoChar(ASIval);
        printf("%c", ch);
        if (ch == '.') {
            lastCharPeriod = 1;
        } else {
            lastCharPeriod = 0;
        }
    }
    if (lastCharPeriod) {
        printf("\n");
    } else {
        printf(" ");
    }
    return;
}



    int main() {
    char ch;
    int newWord = 0;
    int numLetters = 0;
    int numDigit = 0;
    int numMixed = 0;

    while (1) {
        scanf("%c", &ch);
        if (getASIblock(newWord, 0) != 0) {
            newWord = appendWordChar(newWord, ch);
            if (isWordFull(newWord)) {
                printNewWord(newWord);
                int type = newWordType(newWord);
                if (type == 1) {
                    printf("\nNumber of numType1 is:%d \n", numLetters);
                    numLetters++;
                } else if (type == 2) {
                    printf("\nNumber of numType1 is:%d \n", numDigit);
                    numDigit++;
                } else {
                    printf("\nNumber of numType1 is:%d \n", numMixed);
                    numMixed++;
                }
                newWord = 0;
            }
        } else if (ch == '$') {
            // Print the last word if any
            if (newWord != 0) {
                printNewWord(newWord);
                int type = newWordType(newWord);
                if (type == 1) {
                    printf("\nNumber of numType1 is:%d \n", numLetters);
                    numLetters++;
                } else if (type == 2) {
                    printf("\nNumber of numType1 is:%d \n", numDigit);
                    numDigit++;
                } else {
                    printf("\nNumber of numType1 is:%d \n", numMixed);
                    numMixed++;
                }
            }
            printf("Number of words is %d\n", numLetters);
            printf("Number of numbers is %d\n", numDigit);
            printf("Number of mixed words is %d\n", numMixed);
            break;
        }
    }
    return 0;
}

// int main() {
//         int newWord = 0;  // newWord
//         int numType1 = 0; // num wordsWithOnlyLetters (and periods)
//         int numType2 = 0; // num wordsWithOnlyDigits (and periods)
//         int numType3 = 0; // num mixedWords (letters and digits)
//         int wordType;     // 1 or 2 or 3
//         char ch;          // input from scanf
//         int tmpWord = 0; //tempWord
//         do {
//                 scanf("%c", &ch);
//                 tmpWord = appendWordChar(newWord, ch);
//                 if (newWord != tmpWord) {
//                         newWord = tmpWord;
//                 } else {
//                         wordType = newWordType(newWord);
//                         if (wordType == 1) {
//                                 numType1++;
//                                 printf("\nNumber of numType1 is:%d \n", numType1);
//                         } else if (wordType == 2) {
//                                 numType2++;
//                                 printf("\nNumber of numType2 is:%d \n", numType2);
//                         } else if (wordType == 3) {
//                                 numType3++;
//                                 printf("\nNumber of numType3 is:%d \n", numType3);
//                         }
//                         if(newWord != 0){
//                                 printNewWord(newWord);
//                                 newWord = appendWordChar(0, ch);
//                         }
//                 }
//                 if(ch == '$'){
//                         printf("\nNumber of words is %d\n", numType1);
//                         printf("Number of numbers is %d\n", numType2);
//                         printf("Number of mixed words is %d\n", numType3);
//                 }
//         } while(ch != '$');
//         return 0;
// } //end main method


