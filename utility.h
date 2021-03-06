/*
 * Host Dispatcher Shell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#ifndef UTILITY_H_
#define UTILITY_H_

#include "queue.h"
// The amount of available memory
#define MEMORY 1024
#define BUFFER_LEN 256

// Process structure that contains all info related to the process
typedef struct{
   int arrival_time;
   int priority;
   int processor_time;
   int printers;
   int scanners;
   int modems;
   int cds;
   int mbytes;
} proc;

// Resources structure containing integers for each resource constraint and an
// array of 1024 for the memory
typedef struct {
  int mbytes[MEMORY];
  int printers;
  int scanners;
  int modems;
  int cds;
} resources;


// Include your relevant functions declarations here they must start with the
// extern keyword such as in the following examples:

// Function to allocate a contiguous chunk of memory in your resources structure
// memory array, always make sure you leave the last 64 values (64 MB) free, should
// return the index where the memory was allocated at
extern int alloc_mem(resources res, int size);

// Function to free the allocated contiguous chunk of memory in your resources
// structure memory array, should take the resource struct, start index, and
// size (amount of memory allocated) as arguments
extern void free_mem(resources res, int index, int size);

// Function to parse the file and initialize each process structure and add
// it to your job dispatch list queue (linked list)
extern void load_dispatch(char *dispatch_file, node_t *queue);


#endif /* UTILITY_H_ */
