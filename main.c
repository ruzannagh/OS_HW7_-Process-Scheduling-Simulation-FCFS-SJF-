#include <stdio.h>
#include <stdlib.h>
#include "fcfs_scheduler.h"
#include "sjf_scheduler.h"

int main() {
	int n;
	printf("Enter the number of processes:");
	scanf("%d", &n);

	struct Process *processes = malloc(n * sizeof(struct Process));

	if (processes == NULL) {
		printf("malloc failed");
		return 1;
	}

	for (int i = 0; i < n; ++i) {
		processes[i].pid = i + 1;
		printf("Enter the arrival time and burst time for process %d: ", i + 1);
		scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
	}
	printf("\n");

	fcfs_scheduler(processes, n);
	sjf_scheduler(processes, n);

	free(processes);
	processes = NULL;

	return 0;
}
