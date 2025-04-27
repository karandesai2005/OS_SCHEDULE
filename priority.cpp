#include <iostream>
#include <algorithm>
using namespace std;

struct Process
{
    int pid;      // Process ID
    int bt;       // Burst Time
    int priority; // Priority (lower number = higher priority)
    int ct;       // Completion Time
    int tat;      // Turnaround Time
    int wt;       // Waiting Time
};

int main()
{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    Process proc[n];

    cout << "Enter burst time and priority for each process:\n";
    for (int i = 0; i < n; i++)
    {
        proc[i].pid = i + 1;
        cout << "Process " << proc[i].pid << ": ";
        cin >> proc[i].bt >> proc[i].priority;
    }

    // Sort processes by priority (lower priority number = higher priority)
    sort(proc, proc + n, [](Process a, Process b)
         { return a.priority < b.priority; }); 
         // Place process a before process b if a.priority is smaller than b.priority

    // Calculate completion, turnaround, and waiting times
    int currentTime = 0;
    for (int i = 0; i < n; i++)
    {
        proc[i].ct = currentTime + proc[i].bt; // Completion time
        currentTime = proc[i].ct;              // Update current time
        proc[i].tat = proc[i].ct;              // TAT = CT (since AT=0)
        proc[i].wt = proc[i].tat - proc[i].bt; // Waiting time
    }

    // Display results
    cout << "\nPID\tBT\tPriority\tCT\tTAT\tWT\n";
    float avgTAT = 0, avgWT = 0;
    for (int i = 0; i < n; i++)
    {
        cout << proc[i].pid << "\t" << proc[i].bt << "\t" << proc[i].priority << "\t\t"
             << proc[i].ct << "\t" << proc[i].tat << "\t" << proc[i].wt << "\n";
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