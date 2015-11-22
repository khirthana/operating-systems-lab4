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

  resources res;
  for(int i=0;i<MEMORY;i++){

    res.mbytes[i]=0;
  }
  res.printers=2;
  res.scanners=1;
  res.modems=1;
  res.cds=2;


  if(argc < 2){
    printf("No file name provided! Please provide a file to read the process list from.\n");
    return EXIT_SUCCESS;
  }

  // Load the dispatch list from the file
  node_t *dispatch_queue;

  load_dispatch(argv[1], dispatch_queue);


  node_t *current = dispatch_queue;
  node_t *current_real_time=real_time_queue;
  node_t *current_1=priority_1_queue;
  node_t *current_2=priority_2_queue;
  node_t *current_3=priority_3_queue;

  int dispatch_time=0;
  int index;
  char *args[256] = { 0 };
  args[0] = "./process";


  //loop through dispatch_queue
  while (current != NULL) {

    //if process has arrived, push into appropriate queue
    if((current->p).arrival_time==dispatch_time){
      if((current->p).priority==0){
        push(real_time_queue,current->p);
      }
      if((current->p).priority==1){
          push(priority_1_queue,current->p);
      }
      if((current->p).priority==2){
          push(priority_2_queue,current->p);
      }
      if((current->p).priority==3){
          push(priority_3_queue,current->p);
      }
      dispatch_time++;
    }

    //loop until all queues are empty
    while (current != NULL||current != NULL ||current != NULL) {

      //execute the ​process​ binary in real_time_queue using fork and exec
      if(current_real_time!=NULL){
//if enough resource for process in queue then it is executed

        index=alloc_mem(res,(current_real_time->p).mbytes);

        pid_t pid=fork();

         if (pid == 0){
         execvp (args[0], args);
         }
         else{
          waitpid(pid, 0, 0);   // wait for child to exit
        }

        free_mem(res,index,(current_real_time->p).mbytes);
      }

      //execute the ​process​ binary in priority_2_queue using fork and exec
      while(current_1!=NULL){

//if enough resource for process in queue then it is executed


        index=alloc_mem(res,(current_1->p).mbytes);

        //execute process for 1 sec

        pid_t pid=fork();
        pop(priority_1_queue);

        if (pid == 0){
        // set function calls
        signal(SIGINT, SIG_DFL);
        signal(SIGCONT, SIG_DFL);
        signal(SIGTSTP, SIG_DFL);
        execvp (args[0], args);
        }
        else{
         kill(pid,SIGINT);
         kill(pid,SIGCONT);
         kill(pid,SIGTSTP);
         waitpid(pid, 0, 0);   // wait for child to exit
       }
         //after a process has been run for ​1 second​ it is removed from the queue and added to the next lower priority queue
         push(priority_2_queue,current_1->p);

         free_mem(res,index,(current_1->p).mbytes);

         //runtime of process is decreased of 1 second
         (current_1->p).processor_time--;

        current_1 = current_1->next;
      }

      //execute the ​process​ binary in priority_2_queue using fork and exec
      while(current_2!=NULL){

//if enough resource for process in queue then it is executed

        index=alloc_mem(res,(current_2->p).mbytes);

        //execute process for 1 sec

        pid_t pid=fork();
        pop(priority_2_queue);

        if (pid == 0){
        // set function calls
        signal(SIGINT, SIG_DFL);
        signal(SIGCONT, SIG_DFL);
        signal(SIGTSTP, SIG_DFL);
        execvp (args[0], args);
        }
        else{
         kill(pid,SIGINT);
         kill(pid,SIGCONT);
         kill(pid,SIGTSTP);
         waitpid(pid, 0, 0);   // wait for child to exit
       }

       //after a process has been run for ​1 second​ it is removed from the queue and added to the next lower priority queue
       push(priority_3_queue,current_2->p);

        free_mem(res,index,(current_2->p).mbytes);

        //runtime of process is decreased of 1 second
        (current_2->p).processor_time--;

        current_2 = current_2->next;
      }

      //execute the ​process​ binary in priority_3_queue using fork and exec
      while(current_3!=NULL){

//if enough resource for process in queue then it is executed

        index=alloc_mem(res,(current_3->p).mbytes);

        //execute process for 1 sec

        pid_t pid=fork();
        pop(priority_3_queue);

        if (pid == 0){
        // set function calls
        signal(SIGINT, SIG_DFL);
        signal(SIGCONT, SIG_DFL);
        signal(SIGTSTP, SIG_DFL);
        execvp (args[0], args);
        }
        else{
         kill(pid,SIGINT);
         kill(pid,SIGCONT);
         kill(pid,SIGTSTP);
         waitpid(pid, 0, 0);   // wait for child to exit
       }

       //after a process has been run for ​1 second​ it is removed from the queue and added back to priority 3 queue
       push(priority_3_queue,current_3->p);

        free_mem(res,index,(current_3->p).mbytes);

        //runtime of process is decreased of 1 second
        (current_3->p).processor_time--;

        current_3 = current_3->next;
      }
    }

  current = current->next;
  current_real_time= current_real_time->next;
  }



    return EXIT_SUCCESS;
}
