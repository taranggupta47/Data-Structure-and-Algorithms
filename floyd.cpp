
//FLOYD'S ALGORITHM - ALL PAIR SHORTEST PATH ALGORITHM
#include<stdio.h>
#include<conio.h>
int main()
{
    int i,j,k,n,a[10][10],d[10][10];
        printf("enter the no of vertices\n");
    scanf("%d",&n);
    printf("enter the cost matrix\n");
    printf("enter 0 for self loops & 999 for no edges\n");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
        scanf("%d",&a[i][j]);
        d[i][j]=a[i][j];
    }
    for(k=1;k<=n;k++)
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    if((d[i][k]+d[k][j])<d[i][j])
    d[i][j]=d[i][k]+d[k][j];
    printf("All pairs shortest path\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        printf("%5d",d[i][j]);
        printf("\n");
    }
    getch();
}

