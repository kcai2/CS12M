// $Id: lsort.c,v 1.1 2015-02-19 17:06:46-08 - - $
// Author: Kevin Cai (kcai2@ucsc.edu)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <libgen.h>

typedef struct node node;
struct node {
   char item[82];
   node *link;
};

int main (int argc, char **argv) {
   (void) argc;
   char *progname = basename (argv[0]);
   node *head = NULL;
   char err_buffer [256];
   char err_buf_fmt[16];
   sprintf (err_buf_fmt, "%%%lds", sizeof err_buffer - 1);
   printf ("err_buf_fmt = \"%s\"\n", err_buf_fmt);

   for (;;) {
      char buffer[82];
      int *scanCounter = scanf ("%s", &buffer);

      if (scanCounter == EOF) {
         printf ("%s: EOF\n", progname);
         break;
      } else if (scanCounter == 1) {
      node *prev = NULL;
      node *curr = head;
        while(curr != NULL) {
      printf("strcmp: %d\n", strcmp(curr->item, buffer));
      if (strcmp(curr->item, buffer)>0) break;
         prev = curr;
         curr = curr->link;
      }
      node *tmp = malloc (sizeof (struct node));
      assert (tmp != NULL);
      strcpy(tmp->item, buffer);
      tmp->link = curr;
      if (prev == NULL) head = tmp;
      else prev->link=tmp;
      printf ("%s: word = %.15s\n", progname, buffer);

      } else {
         scanCounter = scanf (err_buf_fmt, err_buffer);
         assert (scanCounter == 1);
         printf ("%s: bad number \"%s\"\n", progname, err_buffer);
      };
   };

   if (argc==2 && strcmp(argv[1], "-d")==0) {
        for (node *curr = head; curr != NULL; curr = curr->link) {
                printf ("%p\n",curr);
        }
   } else if (argc==1) {
         for (node *curr = head; curr != NULL; curr = curr->link) {
         printf ("%.15s\n",curr);
      }
   }
   
   while (head != NULL) {
      node *old = head;
      head = head->link;
      free (old);
   }

   return EXIT_SUCCESS;

}