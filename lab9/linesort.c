// $Id: linesort.c,v 1.2 2015-03-11 22:03:04-07 - - $
// Author: Kevin Cai (kcai2@ucsc.edu) & Ahmadullah Tokhi (atokhi)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inssort.h"

int compar (const void *left, const void *right) {
   return  strcmp(*(char**)left, *(char**)right);
}

int main() {
   char *array[0x1000];
   int nelem = 0;
   int index;
   
   for (index = 0; index < sizeof(array); index++) {
      char buffer[0x1000];
      int num = scanf("%s", buffer);
      if (num != 1 || num == EOF || nelem >= 4096) break;
      array[index] = strdup(buffer);
      nelem++;
   }
   printf("\n");
   
   inssort(array, nelem, sizeof(char*), compar);
   for (index = 0; index < nelem; index++) {
      printf("%s\n", array[index]);
      free(array[index]);
   }
   return EXIT_SUCCESS;
}
