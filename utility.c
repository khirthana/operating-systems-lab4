/*
 * Host Dispatcher Shell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include "queue.h"
#include "hostd.h"
#include "utility.h"


// Define your utility functions here, you will likely need to add more...


void tokenize (char *input, char **tokens){
  const char delim[2] = ",";
  int i = 0;
  char *token = {0};

  char *newline = strchr (input, '\n');

  while (newline){
    *newline = 0;
    token = strtok(input,delim);
    newline = strchr(input, '\n');
  }

  while(token != NULL){
    tokens [i] = token;
    token = strtok (NULL, delim);
    i++;
  }
}


int alloc_mem(resources res, int size){

}

void free_mem(resources res, int index, int size){

}

void load_dispatch(char *dispatch_file, node_t *queue){

    FILE *fp = fopen (dispatch_file,"r");
    char *tokens[BUFFER_LEN];
    char buffer[BUFFER_LEN];

    while(fgets(buffer, BUFFER_LEN, fp)!= NULL){
      tokenize(buffer, tokens);
      proc process;
      process.arrival_time = atoi(tokens[0]);
      process.priority = atoi(tokens[1]);
      process.processor_time = atoi(tokens[2]);
      process.mbytes = atoi(tokens[3]);
      process.printers = atoi(tokens[4]);
      process.scanners = atoi(tokens[5]);
      process.modems = atoi(tokens[6]);
      process.cds = atoi(tokens[7]);

      push(process);
    }

  // Read from the file provided by user
  // Load each process into the queue
}
