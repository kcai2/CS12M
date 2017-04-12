// $Id: nsort.c,v 1.1 2015-02-19 17:06:43-08 - - $
// Author: Kevin Cai (kcai2@ucsc.edu)

#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <assert.h>

typedef struct node node;
struct node {
   double item;
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
      double number;
      int scanCounter = scanf ("%lg", &number);

      if (scanCounter == EOF) {
         printf ("%s: EOF\n", progname);
         break;
      }else if (scanCounter == 1) {
      node *prev = NULL;
      node *curr = head;
      while(curr != NULL) {
         if (curr->item > number) break;
         prev = curr;
         curr = curr->link;
      }
      
      node *tmp = malloc (sizeof (struct node));
      assert (tmp != NULL);
      tmp->item = number;
      tmp->link = curr;
      if (prev == NULL) head = tmp;
      else prev->link=tmp;
      printf ("%s: number = %.15g\n", progname, number);
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
   }
  else if (argc==1){
      for (node *curr = head; curr != NULL; curr = curr->link) {
         printf ("%.15g\n",curr->item);
      }
   }
   while (head != NULL) {
      node *old = head;
      head = head->link;
      free (old);
   }

   return EXIT_SUCCESS;
}
