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
    process p[10];
    printf("Enter total number of process: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter process pid: ");
        scanf("%d", &p[i].id);
        printf("Enter process burst time: ");
        scanf("%d", &p[i].bt);
        printf("Enter process arrival  time: ");
        scanf("%d", &p[i].at);


    }

    printf("\nEnter Time Quantum :");
    scanf("%d",&tq);

    for (int j = 1; j < n; j++)
    {
        p[j].ct = p[j-1].ct + p[j].bt;
        p[j].at=0;
        p[j].tt = p[j].ct - p[j].at;
        p[j].wt = p[j].tt - p[j].bt;

    }

    int twt = 0, ttt = 0, avgwt, avgtt;

    for (int j = 0; j < n; j++)
    {
        ttt+=p[j].tt;
    }
    avgwt = p[n-1].wt / n;
    avgtt = ttt / n;




    printf("| PID | Burst Time | Arrival Time | Completion Time | Turnaround Time | Waiting Time |\n");


    for(int i=0; i<n; i++)
    {
        printf("| %d   |      %d     |       %d      |         %d       |        %d       |    %d          |\n"
               , p[i].id, p[i].bt,p[i].at,p[i].ct, p[i].tt, p[i].wt );

    }




    printf("******** STATISTICS **********\n");
    printf("\n");
    printf("Total Waiting Time      : %d\n", p[n-1].wt);
    printf("Average Waiting Time    : %d\n", avgwt);
    printf("Total Turnaround Time   : %d\n", ttt);
    printf("Average Turnaround Time : %d\n", avgtt);

    printf("\n");

    printf(" ");

    for (int i = 0; i < n-1; i++)
    {

        printf(" ");
    }
    printf("\n|");


    for(int i=0; i<n; i++)
    {
        for(int j=0; j<p[i].bt - 1; j++)
        {
            printf(" ");
        }
        printf("P%d", p[i].id);
        for(int j=0; j<2; j++)
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



    printf("0");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<p[i].bt; j++)
        {
            printf("  ");
        }

        printf("%d", p[i].tt);

    }
    printf("\n");




}
