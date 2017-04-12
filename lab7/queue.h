// $Id: queue.h,v 1.7 2015-02-23 20:02:25-08 - - $
// Author: Kevin Cai (kcai2@ucsc.edu)

#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdbool.h>

typedef struct queue queue;
typedef char *queue_item_t;

queue *new_queue (void);

void free_queue (queue*);

void insert_queue (queue*, queue_item_t);

queue_item_t remove_queue (queue*);

bool isempty_queue (queue*);

#endif

