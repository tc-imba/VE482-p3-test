//
// Created by liu on 17-12-9.
//

#include <stdlib.h>
#include <unistd.h>
#include <chrono>
#include <iostream>

using namespace std;

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
    int count = 0;
    chrono::time_point<chrono::system_clock> start, end;
    start = chrono::system_clock::now();
    cout << "f(42) = " << fibonacci(42) << '\n';
    end = chrono::system_clock::now();

    chrono::duration<double> elapsed_seconds = end - start;
    time_t end_time = chrono::system_clock::to_time_t(end);
    cout << "pid: " << getpid() << endl;
    cout << "priority: " << (priority < 0 ? "default" : to_string(priority)) << endl;
    cout << "finished computation at " << ctime(&end_time)
         << "elapsed time: " << elapsed_seconds.count() << "s\n";
}