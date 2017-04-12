// $Id: list4.c,v 1.22 2015-02-11 13:25:54-08 - - $
// Author: Kevin Cai (kcai2@ucsc.edu)

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef struct node node;
struct node {
   char *word;
   node *link;
};

int main (int argc, char **argv) {
   node *head = NULL;
   for (int argi = 0; argi < 5; ++argi) {
      node *node = malloc (sizeof (struct node));
      assert (node != NULL);
      node->word = argv[argi];
      node->link = head;
      head = node;
   }

   for (node *curr = head; curr != NULL;) {
      node *temp = curr;
      printf ("%p->node {word=%p->[%s], link=%p}\n",
              curr, curr->word, curr->word, curr->link);
      curr = curr->link;
      free(temp);
   }
   return EXIT_SUCCESS;
}
