#include <iostream>
#include <algorithm>
using namespace std;

struct Process {
    int pid;      // Process ID
    int bt;       // Burst Time
    int ct;       // Completion Time
    int tat;      // Turnaround Time
    int wt;       // Waiting Time
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    Process proc[n];

    // Input burst time for each process
    cout << "Enter burst time for each process:\n";
    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        cout << "Process " << proc[i].pid << ": ";
        cin >> proc[i].bt;
    }

    // Sort processes by burst time (shortest first)
    sort(proc, proc + n, [](Process a, Process b) {
        return a.bt < b.bt;
    });

    // Calculate completion, turnaround, and waiting times
    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        proc[i].ct = currentTime + proc[i].bt; // Completion time
        currentTime = proc[i].ct;              // Update current time
        proc[i].tat = proc[i].ct;              // TAT = CT (since AT=0)
        proc[i].wt = proc[i].tat - proc[i].bt; // Waiting time
    }

    // Display results
    cout << "\nPID\tBT\tCT\tTAT\tWT\n";
    float avgTAT = 0, avgWT = 0;
    for (int i = 0; i < n; i++) {
        cout << proc[i].pid << "\t" << proc[i].bt << "\t" << proc[i].ct << "\t"
             << proc[i].tat << "\t" << proc[i].wt << "\n";
        avgTAT += proc[i].tat;
        avgWT += proc[i].wt;
    }

    // Calculate and display averages
    avgTAT /= n;
    avgWT /= n;
    cout << "Average TAT: " << avgTAT << "\n";
    cout << "Average WT: " << avgWT << "\n";

    return 0;
}