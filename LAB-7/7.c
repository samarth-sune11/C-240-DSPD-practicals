#include<stdio.h>
int graph[10][10]={
    {0,0,1,0,1,0,0,0,0,0},
    {0,1,0,1,0,1,0,0,0,0},
    {0,0,1,0,0,0,0,0,1,0},
    {0,1,0,0,0,1,1,0,0,0},
    {0,0,1,0,1,0,1,1,0,0},
    {0,0,0,1,0,1,0,0,0,1},
    {0,0,0,0,1,0,0,0,1,0},
    {0,0,0,0,0,1,0,1,0,1},
    {0,0,0,0,0,0,1,0,1,0}
};
int visited[10];
void BFS(int start){
    int q[20],front=0,rear=0;
    q[rear++]=start;
    visited[start]=1;
    printf("BSF:  ");
    while(front<rear){
        int node= q[front++];
        printf("%d ",node);
        for(int i=1;i<=9;i++){
            if(graph[node][i]&& !visited[i]){
                visited[i]=1;
                q[rear++]=i;
            }
        }
    }
}
void DFS(int node){
    printf("%d ",node);
    visited[node]=1;
    for(int i=9;i>=1;i--){
        if(graph[node][i]&& !visited[i]){
            DFS(i);
        }
    }
}
int main(){
    BFS(1);
    for(int i=1;i<10;i++){
        visited[i]=0;}
        printf("\n DFS :");
        DFS(1);
    return 0;
}