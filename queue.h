/*
 * Host Dispatcher Shell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#ifndef QUEUE_H_
#define QUEUE_H_


#include "utility.h"

typedef struct queue{
  proc p;
  struct queue *next;
} node_t;

// Include your relevant FIFO queue functions declarations here they must start
// with the extern keyword such as in the following examples:

// Add a new process to the queue, returns the address of the next node added
// to the linked list

extern node_t *push(node_t *head, proc process);

extern node_t *pop(node_t *head);


#endif /* QUEUE_H_ */
