#include <iostream>
using namespace std;

int main() {
int n, temp = 0;
cout << "Enter the number of processes: ";
cin >> n;
int burstTimes[n], turnaroundTimes[n], waitingTimes[n];


for (int i = 0; i < n; i++) {
cout << "Enter burst time for process " << i + 1 << ": ";
cin >> burstTimes[i];
temp += burstTimes[i];
turnaroundTimes[i] = temp;
waitingTimes[i] = turnaroundTimes[i] - burstTimes[i];
}



cout << "P\t\tB.T.\t\tT.A.\t\tC.T.\t\tW.T.\n";
for (int i = 0; i < n; i++) {
cout << "P" << i + 1 << "\t\t" << burstTimes[i] << "\t\t" <<
turnaroundTimes[i] << "\t\t" << turnaroundTimes[i] << "\t\t" <<
waitingTimes[i] << "\n";
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