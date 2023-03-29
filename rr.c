#include <stdio.h>

typedef struct pros
{
    int id;
    int bt;
    int at;
    int wt;
    int ct;
    int tt;
} process;

int main()
{
    int n;
    int tq;
    int time = 0;
    process p[10];
    printf("Enter total number of process: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter process pid: ");
        scanf("%d", &p[i].id);
        printf("Enter process burst time: ");
        scanf("%d", &p[i].bt);
        printf("Enter process arrival time: ");
        scanf("%d", &p[i].at);
    }

    printf("\nEnter Time Quantum :");
    scanf("%d",&tq);


    int i = 0;
    while (i < n)
    {
        if (p[i].bt <= tq && p[i].bt > 0)
        {
            time += p[i].bt;
            p[i].bt = 0;
            p[i].ct = time;
            p[i].tt = p[i].ct - p[i].at;
            p[i].wt = p[i].tt - p[i].bt;
            i++;
        }
        else if (p[i].bt > 0)
        {
            time += tq;
            p[i].bt -= tq;
            if (i == n-1)
            {
                i = 0;
            }
            else if (p[i+1].at <= time)
            {
                i++;
            }
            else
            {
                i = 0;
            }
        }
        else
        {
            i++;
        }
    }

    int twt = 0, ttt = 0, avgwt, avgtt;

    for (int j = 0; j < n; j++)
    {
        ttt += p[j].tt;
        twt += p[j].wt;
    }
    avgwt = twt / n;
    avgtt = ttt / n;

    printf("\n| PID | Burst Time | Arrival Time | Completion Time | Turnaround Time | Waiting Time |\n");

    for (int i = 0; i < n; i++)
    {
        printf("| %d   |      %d     |       %d      |         %d       |        %d       |    %d          |\n"
               , p[i].id, p[i].bt, p[i].at, p[i].ct, p[i].tt, p[i].wt);
    }

    printf("\n******** STATISTICS **********\n");
    printf("\n");
    printf("Total Waiting Time      : %d\n", twt);
    printf("Average Waiting Time    : %d\n", avgwt);
    printf("Total Turnaround Time   : %d\n", ttt);
    printf("Average Turnaround Time : %d\n", avgtt);

    printf("\n");

    printf(" ");

    for (int i = 0; i < n - 1; i++)
    {
        printf(" ");
    }
    printf("\n|");

    for (int i = 0; i < n; i++)
    {
        for (int j =0; j<p[i].bt - 1; j++)
        {
            printf(" ");
        }
        printf("P%d", p[i].id);
        for(int j=0; j<p[i].bt-1; j++)
        {
            printf(" ");
        }
        printf("|");
    }

    for(int i=0; i<n; i++)
    {

        printf(" ");
    }
    printf("\n");





}
