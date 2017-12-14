//
// Created by liu on 17-12-9.
//

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

int ticket = 1;
int exitflag = 0;
pid_t pid = 0;
size_t counter = 0;

void sigint_cb(int signal)
{
    exitflag = 1;
    printf("pid:%d\tticket:%d\tcounter:%lu\n", getpid(), ticket, counter);
}

int main(int argc, char *argv[])
{

    pid = fork();
    if (!pid)
    {
        nice(ticket = 10);
    }

    signal(SIGINT, sigint_cb);

    while (!exitflag)
    {
        counter++;
    }


}