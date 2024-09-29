#include <iostream>
using namespace std;

int main() {
    int n, temp = 0;
    cout << "Enter the number of processes: ";
    cin >> n;

    int arrivalTimes[n], burstTimes[n], completionTimes[n], turnaroundTimes[n], waitingTimes[n];

    // Input arrival and burst times
    for (int i = 0; i < n; i++) {
        cout << "Enter arrival time for process " << i + 1 << ": ";
        cin >> arrivalTimes[i];
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> burstTimes[i];
    }

    // Sort processes by arrival time (FCFS scheduling works in order of arrival)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arrivalTimes[i] > arrivalTimes[j]) {
                swap(arrivalTimes[i], arrivalTimes[j]);
                swap(burstTimes[i], burstTimes[j]);
            }
        }
    }

    // Calculate completion times, turnaround times, and waiting times
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            completionTimes[i] = arrivalTimes[i] + burstTimes[i];
        } else {
            // Make sure that the CPU idles if the next process arrives after the current one finishes
            if (arrivalTimes[i] > completionTimes[i - 1]) {
                completionTimes[i] = arrivalTimes[i] + burstTimes[i];
            } else {
                completionTimes[i] = completionTimes[i - 1] + burstTimes[i];
            }
        }
        turnaroundTimes[i] = completionTimes[i] - arrivalTimes[i]; // Turnaround time = Completion time - Arrival time
        waitingTimes[i] = turnaroundTimes[i] - burstTimes[i];       // Waiting time = Turnaround time - Burst time
    }

    // Output the process details
    cout << "P\tA.T.\tB.T.\tC.T.\tT.A.T.\tW.T.\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t" << arrivalTimes[i] << "\t" << burstTimes[i] << "\t" 
             << completionTimes[i] << "\t" << turnaroundTimes[i] << "\t" << waitingTimes[i] << "\n";
    }

    // Calculate and print the average turnaround time and waiting time
    double avgTurnaroundTime = 0, avgWaitingTime = 0;
    for (int i = 0; i < n; i++) {
        avgTurnaroundTime += turnaroundTimes[i];
        avgWaitingTime += waitingTimes[i];
    }
    avgTurnaroundTime /= n;
    avgWaitingTime /= n;

    cout << "\nAverage Turnaround Time: " << avgTurnaroundTime << endl;
    cout << "Average Waiting Time: " << avgWaitingTime << endl;

    return 0;
}
