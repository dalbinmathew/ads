#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n;
    printf("Enter no:of vertices: ");
    scanf("%d", &n);
    int a[n][n],visited[n],c=0;
    printf("Enter adjacency matrix: ");
    for (int i = 0; i < n; i++)
    {
        visited[i]=0;            
        for(int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    }
    printf("Topological: ");
    for(int i = 0; i < n; i++)
    {
        if(visited[i]==0)
        {
            c=0;
            for(int j = 0; j < n; j++)
            {
                if(a[j][i]!=0)
                {c=1;
                break;}
            }
            if(c==0)
            {   visited[i]=1;
                printf("%c->",i+65);
                for(int k=0;k<n;k++)
                    a[i][k]=0;
                i=-1;
            }
        }       
        
    }
    
}