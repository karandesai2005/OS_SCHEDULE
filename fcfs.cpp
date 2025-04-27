#include <iostream>

using namespace std;

struct process
{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};

int main()
{
    int n;
    cout << "enter number of process";
    cin >> n;
    process pro[n];

    cout << "enter arrival time and burst time for each process";
    for (int i = 0; i < n; i++)
    {
        pro[i].pid = i+1;
        cout <<"process " << pro[i].pid << " : ";
        cin >> pro[i].at >> pro[i].bt;
    }

    int currentTime = 0;
    for (int i = 0; i < n; i++)
    {
        currentTime = max(currentTime,pro[i].at);
        pro[i].ct = currentTime + pro[i].bt;
        currentTime = pro[i].ct;
        pro[i].tat = pro[i].ct - pro[i].at;
        pro[i].wt = pro[i].tat - pro[i].bt;
    }
    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    float avgTAT = 0, avgWT = 0;
    for (int i = 0; i < n; i++) {
        cout << pro[i].pid << "\t" << pro[i].at << "\t" << pro[i].bt << "\t"
             << pro[i].ct << "\t" << pro[i].tat << "\t" << pro[i].wt << "\n";
        avgTAT += pro[i].tat;
        avgWT += pro[i].wt;
    }

    // Calculate and display averages
    avgTAT /= n;
    avgWT /= n;
    cout << "Average TAT: " << avgTAT << "\n";
    cout << "Average WT: " << avgWT << "\n";

    
}