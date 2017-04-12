// $Id: inssort.h,v 1.1 2015-03-09 16:50:02-07 - - $
// Author: Kevin Cai (kcai2@ucsc.edu) & Ahmadullah Tokhi (atokhi)

#ifndef __INSSORT_H__
#define __INSSORT_H__

#include <stdbool.h>

void inssort (void* base, size_t nelem, size_t size,
              int (*compar) (const void*, const void*));

#endif
