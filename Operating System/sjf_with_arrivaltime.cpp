
#include <iostream>
#include <climits> // for INT_MAX
using namespace std;

// Function to find the waiting time for all processes
void findWaitingTime(int processes[], int n, int burst_time[], int arrival_time[], int waiting_time[]) {
    int remaining_time[n];  // Remaining burst time for each process
    for (int i = 0; i < n; i++) {
        remaining_time[i] = burst_time[i];
    }

    int complete = 0, t = 0, minm = INT_MAX, shortest = 0, finish_time;
    bool check = false;

    // Process until all processes are complete
    while (complete != n) {
        // Find process with minimum remaining time among the processes that arrive till the current time
        for (int j = 0; j < n; j++) {
            if (arrival_time[j] <= t && remaining_time[j] < minm && remaining_time[j] > 0) {
                minm = remaining_time[j];
                shortest = j;
                check = true;
            }
        }

        if (!check) {
            t++;  // Increment time if no process is ready
            continue;
        }

        // Reduce remaining time of the shortest process
        remaining_time[shortest]--;

        // Update minimum remaining time
        minm = remaining_time[shortest];
        if (minm == 0) {
            minm = INT_MAX;
        }

        // If a process gets completely executed
        if (remaining_time[shortest] == 0) {
            complete++;
            check = false;
            finish_time = t + 1;

            // Calculate waiting time
            waiting_time[shortest] = finish_time - burst_time[shortest] - arrival_time[shortest];
            if (waiting_time[shortest] < 0) {
                waiting_time[shortest] = 0;
            }
        }

        // Increment time
        t++;
    }
}

// Function to calculate turn around time
void findTurnAroundTime(int processes[], int n, int burst_time[], int waiting_time[], int turn_around_time[]) {
    for (int i = 0; i < n; i++) {
        turn_around_time[i] = burst_time[i] + waiting_time[i];
    }
}

// Function to calculate average time
void findAvgTime(int processes[], int n, int burst_time[], int arrival_time[]) {
    int waiting_time[n], turn_around_time[n], total_wt = 0, total_tat = 0;

    // Calculate waiting time for each process
    findWaitingTime(processes, n, burst_time, arrival_time, waiting_time);

    // Calculate turn around time for each process
    findTurnAroundTime(processes, n, burst_time, waiting_time, turn_around_time);

    // Display processes along with their burst time, waiting time, and turn around time
    cout << "Processes    Burst Time    Arrival Time    Waiting Time    Turn Around Time\n";

    for (int i = 0; i < n; i++) {
        total_wt += waiting_time[i];
        total_tat += turn_around_time[i];
        cout << "   " << i+1 << "\t\t" << burst_time[i] << "\t\t" << arrival_time[i] << "\t\t" << waiting_time[i] << "\t\t" << turn_around_time[i] << endl;
    }

    cout << "\nAverage waiting time = " << (float)total_wt / n;
    cout << "\nAverage turn around time = " << (float)total_tat / n << endl;
}

int main() {
    // Process IDs
    int processes[] = {1, 2, 3, 4};

    // Number of processes
    int n = sizeof(processes) / sizeof(processes[0]);

    // Burst time of each process
    int burst_time[] = {6, 8, 7, 3};

    // Arrival time of each process
    int arrival_time[] = {1, 1, 2, 3};

    findAvgTime(processes, n, burst_time, arrival_time);
    return 0;
}
