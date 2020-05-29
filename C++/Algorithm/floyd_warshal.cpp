#include<stdio.h>
int i, j, k,n, adjmatrix[10][10];

void floydWarshell ()
{
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (adjmatrix[i][k] + adjmatrix[k][j] < adjmatrix[i][j])//comparing the shortest path between the vertices in the current matrix(via an intermediate vertex)
                    adjmatrix[i][j] = adjmatrix[i][k] + adjmatrix[k][j];//and using previous matrix.
}
int main()
{
    int i,j;
    printf("enter no of vertices :");
    scanf("%d",&n);
    printf("\n");
    for(i=0;i<n;i++)
       {
            for(j=0;j<n;j++)
        {
            printf("adjacency_matrix[%d][%d]:",i,j);
            scanf("%d",&adjmatrix[i][j]);
        }printf("\n");
       }
    printf (" \n\nadjacency_matrix \n");
     for (int i = 0; i < n; i++)
     {
      for (int j = 0; j < n; j++)
       printf ("%d\t", adjmatrix[i][j]);
      printf("\n");
     }
    floydWarshell();
    printf (" \n\n shortest distances between every pair of vertices \n");
     for (int i = 0; i < n; i++)
     {
      for (int j = 0; j < n; j++)
       printf ("%d\t", adjmatrix[i][j]);
      printf("\n");
     }
     return 0;
}
// { {0,   5,  INF, 10},
// {INF,  0,  3,  INF},
// {INF, INF, 0,   1},
// {INF, INF, INF, 0} }