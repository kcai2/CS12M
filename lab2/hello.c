// $Id: hello.c,v 1.2 2015-01-22 10:32:10-08 - - $

//
// NAME
//    hello - print the "Hello, World!" message.
//
// SYNOPSIS
//    hello
//
// DESCRIPTION
//    Prints the "Hello, World!" message if no operands are
//    present.  Errors out with a Usage message otherwise.
//

#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
   int exit_status = EXIT_SUCCESS;
   if (argc == 0) {
      printf ("Hello, World!\n");   
      exit_status = EXIT_SUCCESS;
   } else {
      fprintf(stderr, "Usage: %s\n", basename(argv[0]));
      exit_status = EXIT_FAILURE;
   }
   return exit_status;
}

