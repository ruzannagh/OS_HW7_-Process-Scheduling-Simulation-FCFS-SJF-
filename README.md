# Process Scheduling Simulation (FCFS & SJF)

## Description
This program simulates two CPU scheduling algorithms:
- First Come First Served (FCFS)
- Shortest Job First (SJF) - Non-preemptive

It calculates for each process:
- Waiting Time (WT)
- Turnaround Time (TAT)
- Response Time (RT)

The program also prints a Gantt chart and average metrics for both algorithms.

---

## Compilation

Compile all files together using GCC:

```bash
gcc main.c fcfs_scheduler.c sjf_scheduler.c -o scheduler
```

Run the program:

```bash
./scheduler
```
