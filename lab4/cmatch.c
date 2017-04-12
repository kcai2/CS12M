//$Id: cmatch.c,v 1.1 2015-02-09 15:44:02-08 - - $
//Author: Kevin Cai (kcai2@ucsc.edu)

#define _GNU_SOURCE
#define STDIN_NAME "-"
#include <errno.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stddef.h>

char *program_name = NULL;
int exit_status = EXIT_SUCCESS;

typedef struct options {
   bool ignore_case;
   bool filenames_only;
   bool number_lines;
} options;

void scan_options(int argc, char **argv, options *opts) {
   opts->ignore_case = false;
   opts->filenames_only = false;
   opts->number_lines = false;
   opterr = false;
   for (;;) {
      int opt = getopt (argc, argv, "iln");
      if (opt == EOF) break;
      switch (opt) {
         case 'i': 
            opts->ignore_case = true; break;
         case 'l':
            opts->filenames_only = true; break;
         case 'n':
            opts->number_lines = true; break;
         default: 
            exit_status = EXIT_FAILURE;
            fflush (NULL);
            fprintf(stderr, "%s: -%c: invalid option\n", 
                        program_name, optopt);
            break;
      }
   }
} //end scan_options

int main (int argc, char **argv) {
   program_name = basename (argv[0]);
   options opts;
   scan_options(argc, argv, &opts);
   int argCount = 1;
   if (opts.ignore_case == true || opts.filenames_only == true || opts.number_lines == true)
      argCount = 2;
      char *theword = argv[argCount];
   if (argc == 1) {
      fflush(NULL);
      fprintf(stderr, "Usage: %s [-iln] string [filename...]\n", basename (argv[0]));
      exit(1);
      fflush(NULL);
   }
   for (int argi = argCount+1; argi < argc; ++argi) {
      char *filename = argv[argi];
      if (strcmp (filename, STDIN_NAME) == 0) {
         catbyline(stdin, STDIN_NAME);
      } else {
         FILE *input = fopen (filename, "r");
         if (input != NULL) {
            catbyline (input, theword, filename, opts);
            fclose (input);
         } else {
            exit_status = EXIT_FAILURE;
            fflush (NULL);
            fprintf (stderr, "%s: %s: %s\n", program_name,
                     filename, strerror (errno));
            fflush (NULL);
         }
      }
   }
   return exit_status;
} //end main

void catbyline (FILE *input, char *theword, char *filename, options opts) {
   char buffer[1024];
   char *word = NULL;
   if (opts.filenames_only==true)
      printf("%s\n", filename);
   for (int linenr = 1;; ++linenr) {
      char *buf = fgets (buffer, sizeof buffer, input);
      if (buf == NULL) break;
      if (opts.ignore_case)  word = strcasestr(buf, theword);
                           else  word = strstr(buf, theword);
      if (opts.number_lines && word != NULL) printf("%d:", linenr);
      if (word != NULL && opts.filenames_only == false) {
         printf("%s", buf);
      }
   }
} //end catbyline function
