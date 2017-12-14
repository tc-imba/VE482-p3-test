//
// Created by liu on 17-12-9.
//

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>

int ticket = 1;
int exitflag = 0;
pid_t pid = 0;
unsigned long counter = 0;
clock_t start;

void sigint_cb(int signal)
{
    exitflag = 1;
    printf("pid:%d\tticket:%d\ttime:%lu\n", getpid(), ticket, clock() - start);
}

int main(int argc, char *argv[])
{
    start = clock();
    pid = fork();
    if (pid)
    {
        nice(ticket = 2);
    }

    signal(SIGINT, sigint_cb);

    while (!exitflag)
    {
        counter++;
    }


}