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
    process p[10];
    printf("Enter total number of process: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter process pid: ");
        scanf("%d", &p[i].id);
        printf("Enter process burst time: ");
        scanf("%d", &p[i].bt);
    }


        for(int i=0; i<n-1; i++)
    {

        for(int j=0; j<n-1-i; j++)
        {
            if(p[j].bt > p[j+1].bt)
            {
                process temp;
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }


    p[0].ct = p[0].bt;
    p[0].at = 0;
    p[0].wt = 0;
    p[0].tt=p[0].ct-p[0].at;





    for (int j = 1; j < n; j++)
    {
        p[j].ct = p[j-1].ct + p[j].bt;
        p[j].at = 0;
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
        printf("| %d   |      %d     |       %d      |         %d       |        %d       |    %d        |\n"
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
