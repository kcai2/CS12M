// $Id: environ.c,v 1.8 2015-02-11 13:21:49-08 - - $
// Author: Kevin Cai (kcai2@ucsc.edu)

#include <stdlib.h>
#include <stdio.h>


int main (int argc, char **argv) {
   extern char **environ;

   for (int i = 0; environ[i] != NULL; i++) {
      printf("%s\n", environ[i]);
   }

}
