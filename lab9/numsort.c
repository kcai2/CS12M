// $Id: numsort.c,v 1.2 2015-03-11 22:02:59-07 - - $
// Author: Kevin Cai (kcai2@ucsc.edu) & Ahmadullah Tokhi (atokhi)

#include <stdio.h>
#include <stdlib.h>

#include "inssort.h"

int compar(const void *left, const void *right) {
   if (*(double*)left <= *(double*)right) return 0;
   else return 1;
}

int main() {
   double number;
   double array[0x1000];
   int nelem = 0;
   int index;
   for (;;) {
      int num = scanf("%lg", &number);
      if (num != 1 || num==EOF || nelem >= 4096) break;
      array[nelem]=number;
      nelem++;
   }

   inssort(array, nelem, sizeof(double), *compar);
   for (index = 0; index < nelem; index++) {
      printf("%20.15lg\n", array[index]);
   }
   return EXIT_SUCCESS;
}
