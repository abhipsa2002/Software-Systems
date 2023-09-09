/*
============================================================================
Name : 29.c
Author : Abhipsa Panda
Description: Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
Date: 8th Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<sched.h> 
#include<sys/types.h> 
#include<unistd.h> 
#include<stdio.h>  
#include<sys/time.h>
#include<sys/resource.h>

int main()
{
 pid_t pid = getpid();
 unsigned int cur_policy = sched_getscheduler(pid);
 int cur_priority = getpriority(PRIO_PROCESS,pid);
 printf("Current priority is %d\n",cur_priority);
  struct sched_param p;
 p.sched_priority=15;
 switch(cur_policy)
 {
    case SCHED_FIFO:
 	printf("Current policy is FIFO \n");
        sched_setscheduler(pid,SCHED_RR,&p);
        cur_policy = sched_getscheduler(pid);
        printf("Current policy is %d\n",cur_policy);
        cur_priority = getpriority(PRIO_PROCESS,pid);
        printf("After change, the priority is %d\n", cur_priority);
        break;
    case SCHED_RR:
        printf("Current policy is Round Robin \n");
        sched_setscheduler(pid,SCHED_FIFO,&p);
        cur_policy = sched_getscheduler(pid);
        printf("Current policy is %d\n",cur_policy);
        cur_priority = getpriority(PRIO_PROCESS,pid);
        printf("After change, the priority is %d\n",cur_priority);
        break;
    case SCHED_OTHER:
        printf("Current policy is OTHER \n");
        sched_setscheduler(pid,SCHED_RR,&p);
        cur_policy = sched_getscheduler(pid);
        printf("Current policy is %d\n",cur_policy);
        cur_priority = getpriority(PRIO_PROCESS,pid);
        printf("After change, the priority is %d\n",cur_priority);
        break;
     default:
     	perror("error in changing the scheduling policy \n");
 }
 return 0;
 }
 
 //run this program using sudo ./a.out to change the process scheduling policy
