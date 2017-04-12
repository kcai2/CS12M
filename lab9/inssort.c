// $Id: inssort.c,v 1.1 2015-03-09 16:49:40-07 - - $
// Author: Kevin Cai (kcai2@ucsc.edu) & Ahmadullah Tokhi (atokhi)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inssort.h"
void inssort (void* base, size_t nelem, size_t size,
              int (*compar) (const void*, const void*)) {
   size_t index;
   for (index  = 1; index < nelem; index++) {
      size_t slot = index;
      void *array_slot = base + slot*size;
      void *copy = malloc(size);
      memcpy(copy, array_slot, size);
      for (; array_slot > base; array_slot -= size) {
         int cmp = compar(copy, array_slot - size);
         if (cmp > 0) break;
         memcpy (array_slot, array_slot-size, size); 
      }
      memcpy(array_slot, copy, size);
      free(copy);
   }
}
