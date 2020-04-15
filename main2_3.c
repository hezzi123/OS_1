//
// Created by ariki on 4/15/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <syslog.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        //Child
        //Current directory
        chdir("/");

        //Move to another session
        setsid();

        printf("The daemon is starting\n");

        close(stdin); //close input
        close(stdout); //close output
        close(stderr); //close errors

        //Log open and updates
        openlog("newDaemon", LOG_PID, LOG_DAEMON);
        syslog(LOG_NOTICE, "Daemon is starting");
        usleep(3000000);
        syslog(LOG_NOTICE, "Working on it");
        usleep(3000000);
        syslog(LOG_NOTICE, "Daemon finished");
        usleep(3000000);
    }
    else
    {
        printf("daemon PID %d\n" , pid);
    }
    return 0;
}
