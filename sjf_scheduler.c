#include "sjf_scheduler.h"
#include "process.h"
#include <stdio.h>
#include <limits.h>

void sjf_scheduler(struct Process *processes, int n) {
	int cur_time = 0;
	float total_tat = 0, total_wt = 0, total_rt = 0;
	int completed_count = 0;
	int is_completed[n];
	for (int i = 0; i < n; i++)
		is_completed[i] = 0;

	printf("\n=== Shortest Job First (SJF) ===\n");
	printf("Gantt Chart: ");

	while (completed_count != n) {
		int next_proc_idx = -1;
		int min_burst = INT_MAX;

		for(int i = 0; i < n; ++i) {
			if (!is_completed[i] && processes[i].arrival_time <= cur_time) {
				if (processes[i].burst_time < min_burst || (processes[i].burst_time == min_burst && processes[i].arrival_time < processes[next_proc_idx].arrival_time)) {
					min_burst = processes[i].burst_time;
					next_proc_idx = i;
				}
			}
		}

		if (next_proc_idx != -1) {
			processes[next_proc_idx].waiting_time = cur_time - processes[next_proc_idx].arrival_time;
			processes[next_proc_idx].response_time = processes[next_proc_idx].waiting_time;
			cur_time += processes[next_proc_idx].burst_time;
			processes[next_proc_idx].turnaround_time = cur_time - processes[next_proc_idx].arrival_time;
			is_completed[next_proc_idx] = 1;
			completed_count++;
		
			total_tat += processes[next_proc_idx].turnaround_time;
			total_wt += processes[next_proc_idx].waiting_time;
			total_rt += processes[next_proc_idx].response_time;

			printf("| P%d ", processes[next_proc_idx].pid);
		} else {
			cur_time++;
		}
	}
	
	printf("|\n");

        printf("PID	AT      BT      WT      TAT     RT\n");
        for (int i = 0; i < n; i++) {
                printf("%d	%d      %d      %d      %d      %d\n",
                        processes[i].pid,
                        processes[i].arrival_time,
                        processes[i].burst_time,
                        processes[i].waiting_time,
                        processes[i].turnaround_time,
                        processes[i].response_time);
        }

        printf("\nAverage Waiting Time: %f\n", total_wt/n);
        printf("Average Turnaround Time: %f\n", total_tat/n);
        printf("Average Response Time: %f\n", total_rt/n);
}
