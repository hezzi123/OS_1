//
// Created by ariki on 4/15/2020.
//
#define _GNU_SOURCE
#include <sched.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10000
char child_stack[STACK_SIZE+1];

// Run main2_1
int main1()
{
    char * args[2] = {"./main2_1" , NULL};
    execvp(args[0] , args);
    return 0;
}

// Run main2_2
int main2()
{
    char * args[2] = {"./main2_2" , NULL};
    execvp(args[0] , args);
    return 0;
}

// Run main2_3
int main3()
{
    char * args[2] = {"./main2_3" , NULL};
    execvp(args[0], args);
    return 0;
}

int main()
{
    printf("ID 1 = %d\n", clone(main1 , child_stack + STACK_SIZE , CLONE_PARENT , 0));
    printf("ID 2 = %d\n", clone(main2 , child_stack + STACK_SIZE , CLONE_PARENT , 0));
    printf("ID 3 = %d\n", clone(main3 , child_stack + STACK_SIZE , CLONE_PARENT , 0));
    printf("Parent id %d\n", getpid());
    sleep(15);
}
