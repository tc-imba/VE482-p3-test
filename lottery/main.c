//
// Created by liu on 17-12-9.
//

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

const int SIZE = 8;
const int tickets[] = {0, 0, 0, 0, 2, 4, 6, 8};

int ticket = 1;
int exitflag = 0;
pid_t pid = 0;
size_t counter = 0;

void sigint_cb(int signal)
{
    exitflag = 1;
    if (!pid)
    {
        printf("pid:%d\tticket:%d\tcounter:%lu\n", getpid(), ticket, counter);
    }
}

int main(int argc, char *argv[])
{

    for (int i = 0; i < SIZE; i++)
    {
        pid = fork();
        if (!pid)
        {
            sleep(10);
            if (tickets[i] > 0)
            {
                nice(ticket = tickets[i]);
            }
            break;
        }
    }

    signal(SIGINT, sigint_cb);

    while (!exitflag)
    {
        if (!pid) counter++;
    }


}