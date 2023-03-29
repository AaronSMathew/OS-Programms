
#include <stdio.h>

typedef struct pros
{
    int id;
    int bt;
    int at;
    int wt;
    int ct;
    int tt;
    int priority;
} process;

int main()
{
    int n;
    process p[10];
    printf("Enter total number of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter process pid: ");
        scanf("%d", &p[i].id);
        printf("Enter process burst time: ");
        scanf("%d", &p[i].bt);
        printf("Enter process arrival time: ");
        scanf("%d", &p[i].at);
        printf("Enter process priority: ");
        scanf("%d", &p[i].priority);
    }

    // Sorting the processes based on their priority (lower value = higher priority)
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (p[i].priority > p[j].priority)
            {
                process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }


    int time = 0;
    for (int i = 0; i < n; i++)
    {
        time += p[i].bt;
        p[i].ct = time;
        p[i].tt = p[i].ct - p[i].at;
        p[i].wt = p[i].tt - p[i].bt;
    }


    int twt = 0, ttt = 0, avgwt, avgtt;
    for (int j = 0; j < n; j++)
    {
        ttt += p[j].tt;
        twt += p[j].wt;
    }
    avgwt = twt / n;
    avgtt = ttt / n;

    // Printing Gantt Chart
    printf("\nGantt Chart:\n");
    printf(" ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p[i].bt; j++)
        {
            printf("--");
        }
        printf(" ");
    }
    printf("\n|");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p[i].bt - 1; j++)
        {
            printf(" ");
        }
        printf("P%d", p[i].id);
        for (int j = 0; j < p[i].bt - 1; j++)
        {
            printf(" ");
        }
        printf("|");
    }
    printf("\n ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p[i].bt; j++)
        {
            printf("--");
        }
        printf(" ");
    }
    printf("\n");


    printf("\nProcess Details:\n");
    printf("| PID | Burst Time | Arrival Time | Priority | Completion Time | Turnaround Time | Waiting Time |\n");

    for(int i=0; i<n; i++)
    {
        printf("| %d   |      %d     |       %d      |         %d       |        %d       |    %d          |\n"
               , p[i].id, p[i].bt,p[i].at,p[i].priority,p[i].ct, p[i].tt, p[i].wt );

    }

        printf("******** STATISTICS **********\n");
    printf("\n");
    printf("Total Waiting Time      : %d\n", p[n-1].wt);
    printf("Average Waiting Time    : %d\n", avgwt);
    printf("Total Turnaround Time   : %d\n", ttt);
    printf("Average Turnaround Time : %d\n", avgtt);

    printf("\n");

    printf(" ");
}
