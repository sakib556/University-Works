#include <iostream>
#include <climits> 
using namespace std;

void findWaitingTime(int processes[], int n, int burstTime[], int arrivalTime[], int waitingTime[]) {
    int remainingTime[n]; 
    for (int i = 0; i < n; i++) {
        remainingTime[i] = burstTime[i];
    }

    int complete = 0, t = 0, minm = INT_MAX, shortest = 0, finish_time;
    bool check = false;

    while (complete != n) {
        for (int j = 0; j < n; j++) {
            if (arrivalTime[j] <= t && remainingTime[j] < minm && remainingTime[j] > 0) {
                minm = remainingTime[j];
                shortest = j;
                check = true;
            }
        }

        if (!check) {
            t++;  
            continue;
        }

        remainingTime[shortest]--;

        minm = remainingTime[shortest];
        if (minm == 0) {
            minm = INT_MAX;
        }

        if (remainingTime[shortest] == 0) {
            complete++;
            check = false;
            finish_time = t + 1;

            waitingTime[shortest] = finish_time - burstTime[shortest] - arrivalTime[shortest];
            if (waitingTime[shortest] < 0) {
                waitingTime[shortest] = 0;
            }
        }

        t++;
    }
}

void findTurnAroundTime(int processes[], int n, int burstTime[], int waitingTime[], int turn_around_time[]) {
    for (int i = 0; i < n; i++) {
        turn_around_time[i] = burstTime[i] + waitingTime[i];
    }
}

void findAvgTime(int processes[], int n, int burstTime[], int arrivalTime[]) {
    int waitingTime[n], turn_around_time[n], total_wt = 0, total_tat = 0;

    findWaitingTime(processes, n, burstTime, arrivalTime, waitingTime);
    findTurnAroundTime(processes, n, burstTime, waitingTime, turn_around_time);
    cout << "Processes    Burst Time    Arrival Time    Waiting Time    Turn Around Time\n";

    for (int i = 0; i < n; i++) {
        total_wt += waitingTime[i];
        total_tat += turn_around_time[i];
        cout << "   " << i+1 << "\t\t\t" << burstTime[i] << "\t\t\t\t" << arrivalTime[i] << "\t\t\t\t" << waitingTime[i] << "\t\t\t\t\t" << turn_around_time[i] << endl;
    }

    cout << "\nAverage waiting time = " << (float)total_wt / n;
    cout << "\nAverage turn around time = " << (float)total_tat / n << endl;
}

int main() {

    int processes[] = {1, 2, 3, 4};
    int n = sizeof(processes) / sizeof(processes[0]);
    int burstTime[] = {6, 8, 7, 3};
    int arrivalTime[] = {1, 1, 2, 3};
    findAvgTime(processes, n, burstTime, arrivalTime);
   
    return 0;
}
