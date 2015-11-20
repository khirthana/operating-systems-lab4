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
    printf("No file name provided! Please provide a file to read the process list from.\n");
    return EXIT_SUCCESS;
  }

<<<<<<< HEAD
  // ==================== YOUR CODE HERE ==================== //
  // Load the dispatch list from the file
  node_t *dispatch_queue;
  load_dispatch(argv[1], dispatch_queue);

    // ==================== YOUR CODE HERE ==================== //

    // Load the dispatch list from the file

  // Add each process structure instance to the job dispatch list queue

  // Iterate through each item in the job dispatch list, add each process
  // to the appropriate queues

  // Allocate the resources for each process before it's executed

  // Execute the process binary using fork and exec

  // Perform the appropriate signal handling / resource allocation and de-alloaction

  // Repeat until all processes have been executed, all queues are empty
=======
  FILE fp = argv [1];

  // Load the dispatch list from the file
  // Add each process structure instance to the job dispatch list queue
  load_dispatch(fp, queue);


  // Iterate through each item in the job dispatch list, add each process
  // to the appropriate queues
  //Execute the ​process​ binary using fork and exec
  node_t *current = queue;

  while (current != NULL) {

    if(current­>process.priority==0){
      push(real_time_queue,process);

          pid_t pid;

//execute process until their runtime is completed


           if (pid == 0){
           // set function calls
           signal(SIGINT, SIG_DFL);
           signal(SIGCONT, SIG_DFL);
           signal(SIGTSTP, SIG_DFL);
           execvp (args[0], args);
           }
           else{
            sleep(5);
            kill(pid,SIGINT);
            sleep(10);
            kill(pid,SIGCONT);
            sleep(10);
            printf("\nPARENT: sending SIGTSTP\n\n");
            kill(pid,SIGTSTP);
            waitpid(pid, 0, 0);   // wait for child to exit
          }
    }
    else if(current­>process.priority==1){

      push(priority_1_queue,process);
            pid_t pid;
            pop(priority_1_queue);

//execute process for 1 sec


              //after a process has been run for ​1 second​ it is removed from the queue and added to the next lower priority queue
              push(priority_2_queue,process);

              if (pid == 0){
              // set function calls
              signal(SIGINT, SIG_DFL);
              signal(SIGCONT, SIG_DFL);
              signal(SIGTSTP, SIG_DFL);
              execvp (args[0], args);
              }
              else{
               sleep(5);
               kill(pid,SIGINT);
               sleep(10);
               kill(pid,SIGCONT);
               sleep(10);
               printf("\nPARENT: sending SIGTSTP\n\n");
               kill(pid,SIGTSTP);
               waitpid(pid, 0, 0);   // wait for child to exit
             }
    }
    else if(current­>process.priority==2){

      push(priority_2_queue,process);
          pid_t pid;
          pop(priority_2_queue);

//execute process for 1 sec


          //after a process has been run for ​1 second​ it is removed from the queue and added to the next lower priority queue
          push(priority_3_queue,process);

          if (pid == 0){
          // set function calls
          signal(SIGINT, SIG_DFL);
          signal(SIGCONT, SIG_DFL);
          signal(SIGTSTP, SIG_DFL);
          execvp (args[0], args);
          }
          else{
           sleep(5);
           kill(pid,SIGINT);
           sleep(10);
           kill(pid,SIGCONT);
           sleep(10);
           printf("\nPARENT: sending SIGTSTP\n\n");
           kill(pid,SIGTSTP);
           waitpid(pid, 0, 0);   // wait for child to exit
         }
    }
    else{

      push(priority_3_queue,process);
          pid_t pid;
          pop(priority_3_queue);

//execute process for 1 sec


          //after a process has been run for ​1 second​ it is removed from the queue and added back to priority 3 queue
          push(priority_3_queue,process);

          if (pid == 0){
          // set function calls
          signal(SIGINT, SIG_DFL);
          signal(SIGCONT, SIG_DFL);
          signal(SIGTSTP, SIG_DFL);
          execvp (args[0], args);
          }
          else{
           sleep(5);
           kill(pid,SIGINT);
           sleep(10);
           kill(pid,SIGCONT);
           sleep(10);
           printf("\nPARENT: sending SIGTSTP\n\n");
           kill(pid,SIGTSTP);
           waitpid(pid, 0, 0);   // wait for child to exit
         }
    }
    current = current­>next;
  }

>>>>>>> ab199b794cc1f5da44293663bcd80f1abf22f732

    return EXIT_SUCCESS;
}
