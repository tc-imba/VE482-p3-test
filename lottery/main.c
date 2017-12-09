//
// Created by liu on 17-12-9.
//

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>

long fibonacci(unsigned n) {
    if (n < 2) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(int argc, char *argv[]) {
    int priority = -1;
    if (argc > 1) {
        priority = strtol(argv[1], NULL, 10);
        nice(priority);
    }
    long start = clock();
    printf("f(42) = %ld\n", fibonacci(42));
    long end = clock();
    printf("pid: %d\n", getpid());
    printf("priority: %d\n", priority);
    printf("elapsed time: %lfs\n", (double)(end - start) / CLOCKS_PER_SEC);
}