/*
 * Host Dispatcher Shell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "queue.h"
#include "utility.h"
#include "hostd.h"

// Put macros or constants here using #define
#define MEMORY 1024

// Put global environment variables here
node_t *queue;
proc process;

node_t *real_time_queue;
node_t *priority_1_queue;
node_t *priority_2_queue;
node_t *priority_3_queue;


// Define functions declared in hostd.h here

int main(int argc, char *argv[]) {

   if(argc < 2){
    return 1;
  }

  FILE fp = argv [1];

  // Load the dispatch list from the file
  load_dispatch(fp, queue);


      // Add each process structure instance to the job dispatch list queue

    // Iterate through each item in the job dispatch list, add each process
    // to the appropriate queues
  node_t *current = queue;
  while (current != NULL) {
    if(current­>process.priority==0){
      push(real_time_queue,process);
    }
    else if(current­>process.priority==1){
      push(priority_1_queue,process);
    }
    else if(current­>process.priority==2){
      push(priority_2_queue,process);
    }
    else{
      push(priority_3_queue,process);
    }
    current = current­>next;
  }



    // Allocate the resources for each process before it's executed

    // Execute the process binary using fork and exec


    // Perform the appropriate signal handling / resource allocation and de-alloaction

    // Repeat until all processes have been executed, all queues are empty

    return EXIT_SUCCESS;
}
