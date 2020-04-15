//
// Created by ariki on 4/15/2020.
//
#define _GNU_SOURCE
#include <sched.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

//helloFrom function
void helloFrom(const char *from)
{
    for(int i = 0; i < 30; i++)
    {
        printf("Hello From %s\n", from);
        usleep(1000000);
    }
}

int main()
{
    __pid_t pid = fork();

    if(pid == 0)
    {
        __pid_t pid = fork();
        if(pid == 0 )
        {
            helloFrom("GrandChild");
        }
        else
        {
            helloFrom("Child");
        }
    }
    else
    {
        helloFrom("Parent");
    }
    return 0;
}
