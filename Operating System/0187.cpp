#include <iostream>
using namespace std;

int main() {
    int n, temp = 0;
    cout << "Enter the number of processes: ";
    cin >> n;

    int arrivalTimes[n], burstTimes[n], completionTimes[n], turnaroundTimes[n], waitingTimes[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter arrival time for process " << i + 1 << ": ";
        cin >> arrivalTimes[i];
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> burstTimes[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arrivalTimes[i] > arrivalTimes[j]) {
                swap(arrivalTimes[i], arrivalTimes[j]);
                swap(burstTimes[i], burstTimes[j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            completionTimes[i] = arrivalTimes[i] + burstTimes[i];
        } else {
            if (arrivalTimes[i] > completionTimes[i - 1]) {
                completionTimes[i] = arrivalTimes[i] + burstTimes[i];
            } else {
                completionTimes[i] = completionTimes[i - 1] + burstTimes[i];
            }
        }
        turnaroundTimes[i] = completionTimes[i] - arrivalTimes[i];
        waitingTimes[i] = turnaroundTimes[i] - burstTimes[i];       
    }

    cout << "P\tA.T.\tB.T.\tC.T.\tT.A.T.\tW.T.\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t" << arrivalTimes[i] << "\t" << burstTimes[i] << "\t" 
             << completionTimes[i] << "\t" << turnaroundTimes[i] << "\t" << waitingTimes[i] << "\n";
    }

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
