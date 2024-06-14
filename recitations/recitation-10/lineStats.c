#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*** buffer size - max line length + newline + '\0' ***/
#define BUFFER_SIZE 202

int main(int argc, char** argv) {
   /*** buffer for holding line from file ***/
   char line[BUFFER_SIZE];

   int nLines=0, nChars, c;
   FILE* inFile;

   if(argc!=2) {
    fprintf(stderr,"Usage: %s <file>\n",argv[0]);
    return 1;
   }
   inFile=fopen(argv[1],"r");
   if(!inFile) {
    fprintf(stderr,"Cannot open file %s for reading\n",argv[1]);
    return 1;
   }

   /*** THIS IS A VERY LONG COMMENT LINE TO ILLUSTRATE TRUNCATION OF LONG LINES BY THE lineStats PROGRAM ---------------------------------------------------------------------------------------------------------------------------------   ***/
   /*** main loop - read file from stdin line by line ***/
   while(fgets(line,BUFFER_SIZE,inFile)) {
    nLines++;
    nChars=strlen(line);

    /*** print line with stats ***/
    printf("%3d (%3d chars): %s", nLines, nChars, line);

    /*** if line exceeds LINE_LEN, then indicate truncation ... ***/
    if(line[strlen(line)-1] != '\n') {
     c=0;
     while(c!=EOF && c!='\n') {
      c=fgetc(inFile);
     }
     printf("|trunc at %d\n", BUFFER_SIZE-1);
    }
   } // end of while(fgets)

   /*** close file and return ***/
   fclose(inFile);
   return 0;
}


