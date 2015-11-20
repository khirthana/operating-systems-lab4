/*
 * Host Dispatcher Shell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// Define your FIFO queue functions here, these will most likely be the
// push and pop functions that you declared in your header file

node_t *push(node_t *head, proc process){

  // push the process into the queue
  if(head == NULL){
    head = malloc(sizeof(node_t));
    head->p = process;
    head->next = NULL;
  } else {  // Else go to the end of the list and add a new node there
    // Add a new node to the end
    node_t *current = head;
    // Get to the end of the list
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = malloc(sizeof(node_t));
    current->next->p = process;
    current->next->next = NULL;
  }

}

node_t *pop(node_t *head){
  // pop a process from the queue
  node_t return_node = head;
  node_t *temp_node = head->next;
  free(head);
  head = temp_node;
  return return_node;
}
