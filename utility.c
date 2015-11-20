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


int alloc_mem(resources res, int size){

}

void free_mem(resources res, int index, int size){

}

void load_dispatch(char *dispatch_file, node_t *queue){

  char process_data[BUFFER_LEN] = { 0 };
  // The 2D Array that will hold the tokens from the file read
  char * tokens[BUFFER_LEN] = { 0 };
  FILE *fp = fopen(dispatch_file);

  // Read the file here and load it into the queue
  if (fp != NULL){
    while(fgets(process_data, BUFFER_LEN, fp) != NULL){
      tokenize(process, tokens);
      proc process;
      process.arrival_time = tokens[0];
      process.processor_time = tokens[1];
      process.priority = tokens[2];
      process.mbytes = tokens[3];
      process.printers = tokens[4];
      process.scanners = tokens[5];
      process.modems = tokens[6];
      process.cds = tokens[7];

      // Push the process into the queue
      push(queue, process);

    }
  }

  fclose(fp);
}

void tokenize(char *input, char **tokens){

  char delim[2] = ",";
  int i = 0;
  char *token = { 0 };
  // Get rid of any newline characters
  char *newline = strchr( input, '\n' );
  while ( newline ){
    *newline = 0;
    newline = strchr( input, '\n' );
  }
  // get tokens
  token = strtok(input, delim); // Get the first token
  while (token != NULL) {
    tokens[i] = token;
    token = strtok(NULL, delim); // Get next token
    i++;
  }
}
