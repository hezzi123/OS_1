//
// Created by ariki on 4/15/2020.
//
#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include <stdbool.h>

void (*hello_message)(const char *);

bool init()
{
    void *hdl = dlopen("./hello_ariel.so", RTLD_LAZY);
    if (hdl == NULL)
        return false;
    hello_message = (void(*)(const char *))dlsym(hdl , "helloFunction");
    if (hello_message == NULL)
        return false;
    return true;
}

int main()
{
    if (init())
        hello_message();
    else
        printf ("Library was not loaded \n");
    return 0;
}
