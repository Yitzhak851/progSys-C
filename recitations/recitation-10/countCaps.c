#include <stdio.h>
#include <stdlib.h>
/****************************
* program prints table cof counting capital
* letters in a given file.
* Used in File I/O guide
****************************/

int main (int argc, char *argv[]) {
   int   c, i, letterCount[26] = {0};
   FILE *ifp, *ofp;

   if (argc != 3) {
      fprintf (stderr,
         "\nUsage: %s infile outfile\n\n", argv[0]);
      fprintf (stderr,
         "   Counts uppercase letters in infile.\n");
      fprintf (stderr,
         "   Writes the results to outfile.\n\n");
      return 1;
   }

   ifp = fopen (argv[1], "r");
   if(!ifp) {
      fprintf(stderr,              "File %s could not be open for reading", argv[1]);
      return 1;
   }
   ofp = fopen (argv[2], "w");
   if(!ofp) {
      fprintf(stderr,              "File %s could not be open for writing", argv[2]);
      fclose(ifp);
      return 1;
   }

   while ((c = fgetc (ifp)) != EOF) {
      if (c >= 'A' && c <= 'Z') {
         letterCount[c - 'A']++;
      }
   }

   for (i = 0; i < 26; i++) {
      if (i % 6 == 0)
         fputc ('\n', ofp);
      fprintf (ofp, "%c:%4d| ", 'A' + i, letterCount[i]);
   }

   fputc ('\n', ofp);

   fclose (ifp);
   fclose (ofp);

   return 0;
}

