#include<stdio.h>
#include<conio.h>
void dfs(int n, int a[10][10], int u, int visited[])
{
  int v;
  visited[u]=1;
  for(v=0;v<n;v++)
  {
    if((a[u][v]==1)&&(visited[v]==0))
    {
      dfs(n,a,v,visited);
    }
  } 

}
void main()
{
int n, i, j, a[10][10], visited[10],flag, connected;
printf("Enter number of vertices:");
scanf("%d",&n);
printf("\nEnter adjacency matrix:\n");
for(i=0;i<n;i++)
{
 for(j=0;j<n;j++)
 {
  scanf("%d",&a[i][j]);
 }
} 
connected=0;
for(i=0;i<n;i++)
{
 for(j=0;j<n;j++)
 {
   visited[j]=0;
 }
 dfs(n,a, i, visited);
 flag=0;
} 
for(j=0;j<n;j++)
{
 if(visited[j]==0)
   flag=1;
 if(flag==0)
   connected=1;
}
if(connected==1)
   printf("\nGraph is connected");
else
   printf("\nGraph is not connected");
getch();
}