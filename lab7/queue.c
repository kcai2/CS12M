// $Id: queue.c,v 1.21 2015-02-23 19:53:26-08 - - $
// Author: Kevin Cai (kcai2@ucsc.edu)

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

#define STUBPRINTF(...) fprintf (stderr, __VA_ARGS__);

typedef struct queue_node queue_node;
struct queue_node {
   queue_item_t item;
   queue_node *link;
};

struct queue {
   queue_node *head;
   queue_node *tail;
};

queue *new_queue (void) {
   queue *this = malloc(sizeof(queue));
   assert (this != NULL);
   //STUBPRINTF ("return NULL\n");
   return this;
}

void free_queue (queue *this) {
   assert (isempty_queue (this));
   free (this);
}

void insert_queue (queue *this, queue_item_t item) {
   queue_node* node = malloc(sizeof(queue));
   node->item = item;
   node->link = NULL;

   if (this->head == NULL) {
      this->head = node;
   } else {
      this->tail->link = node;
   }
   this->tail = node;
   //STUBPRINTF ("item = \"%s\"\n", item);
}

queue_item_t remove_queue (queue *this) {
   queue_item_t thing = this->head->item;
   this->head = this->head->link;
   //assert (! isempty_queue (this));
   //STUBPRINTF ("return NULL\n");
   return thing;
}

bool isempty_queue (queue *this) {
   return this->head == NULL;
}

