// $Id: mstat.c,v 1.2 2015-03-04 20:23:28-08 - - $i
// Author: Kevin Cai (kcai2@ucsc.edu)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <sys/time.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <assert.h>
#include <limits.h>
#include <libgen.h>


#define Days180 15552000

char *pname = NULL;
int exit_status = EXIT_SUCCESS;

void printname (char *filename) {
   struct stat buf;
   struct tm tm;
   int files = lstat(filename, &buf);
   if (files != 0) {
      fflush(NULL);
      fprintf(stderr, "%s: %s: %s\n", pname, filename, strerror(errno));
      fflush(NULL);
      exit_status = EXIT_FAILURE;
   } else {
      mode_t mode = buf.st_mode;
      int size = buf.st_size;
      printf("%06lo %9d ", (unsigned long) mode, size);
      
      time_t timeNow = time(NULL);
      time_t fTime = buf.st_mtime;
      int timeDiff = timeNow - fTime; 
      localtime_r (&fTime, &tm);
      char buffer[64];
      if (timeDiff > Days180) {
         strftime(buffer, sizeof buffer, "%b %e %Y", &tm);
         printf("%s %s\n", buffer, filename);
      } else {
         strftime(buffer, sizeof buffer, "%b %e %R", &tm);
         printf("%s %s\n", buffer, filename);
      }
   }
}

int main(int argc, char **argv) {
   pname = argv[0];
   if (argc == 1) {
	printname(".");
   } else {
      for(int argi = 1; argi < argc; argi++){
         char *file = argv[argi];
         printname(file);
         char linkname[PATH_MAX + 1];
         int retval = readlink (file, linkname, sizeof linkname);
         if (retval >= 0) {
            linkname[retval < PATH_MAX + 1 ? retval : PATH_MAX] = '\0';
            printf ("-> \"%s\"\n", linkname);
         }
      }
   return exit_status;
   }
}
