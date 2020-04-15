//
// Created by ariki on 4/15/2020.
//
#define _GNU_SOURCE
#include <sched.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10000
#define CYCLES 30

char child_stack[ STACK_SIZE + 1 ];

//helloFrom function
void helloFrom(const char *from)
{
    for(int i = 0; i < CYCLES; i++)
    {
        printf("Hello From %s\n", from);
        usleep(1000000);
    }
}

int childFunc()
{
    helloFrom("Child \n");
}

int grandChildFunc()
{
    helloFrom("GrandChild \n");
}

int main()
{
    int firstResult = clone(childFunc , child_stack + STACK_SIZE , CLONE_PARENT , 0);
    int secondResult = clone(grandChildFunc , child_stack + STACK_SIZE , CLONE_PARENT , 0);

    printf("Clone first result = %d\n", firstResult);
    printf("Clone second result = %d\n", secondResult);

    helloFrom("Parent");

    return 0;
}
