#ifndef PROCESS_H
#define PROCESS_H

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
};

#endif
