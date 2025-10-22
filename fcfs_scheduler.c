#include "fcfs_scheduler.h"
#include "process.h"
#include <stdio.h>

void fcfs_scheduler (struct Process *processes, int n) {
	for (int i = 0; i < n-1; i++) {
		for(int j = i + 1; j < n; j++) {
			if(processes[i].arrival_time > processes[j].arrival_time) {
				struct Process temp = processes[i];
				processes[i] = processes[j];
				processes[j] = temp;
			}
		}
	}

	int cur_time = 0;
	float total_tat = 0, total_wt = 0, total_rt = 0;

	printf("=== First Come First Served (FCFS) ===\n");
	printf("Gantt Chart: ");

	for(int i = 0; i < n; ++i){
		printf("| P%d ", processes[i].pid);

		if(cur_time < processes[i].arrival_time) {
			cur_time = processes[i].arrival_time;	
		}

		processes[i].waiting_time = cur_time - processes[i].arrival_time;
		processes[i].response_time = processes[i].waiting_time;
		cur_time += processes[i].burst_time;
		processes[i].turnaround_time = cur_time - processes[i].arrival_time;

		total_tat += processes[i].turnaround_time;	
		total_wt += processes[i].waiting_time;
		total_rt += processes[i].response_time;
	}
	printf("|\n");

	printf("PID     AT	BT	WT	TAT	RT\n");
	for (int i = 0; i < n; i++) {
        	printf("%d	%d	%d	%d	%d	%d\n",
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
