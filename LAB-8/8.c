#include<stdio.h>
#define MAX 20
int parent[MAX];
int find(int i) {
    while (parent[i] != -1) {
        i = parent[i];
    }
    return i;
}
void union1(int i, int j) {
    int a = find(i);
    int b = find(j);
    
        parent[a] = b;
    
}
int main() {
    int n, edges;
    int cost[MAX][MAX];
    int i,j,u,v,mincost=0,ne=1;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = 999;
            }
        }
    }
    for(i=0;i<n;i++) {
        parent[i] = -1;
    }
    printf("The edges of Minimum Cost Spanning Tree are:\n");
    while (ne < n) {
        int min = 999,a=-1,b=-1;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        if (find(a) != find(b)) {
            printf("%d edge (%d,%d) =%d\n", ne++, a + 1, b + 1, min);
            mincost += min;
            union1(a, b);
            cost[a][b] = cost[b][a] = 999;
           
        }
         
    }
    printf("Minimum cost = %d\n", mincost);
    return 0;
}


