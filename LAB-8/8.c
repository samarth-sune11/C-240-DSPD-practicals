#include <stdio.h>
#include <stdlib.h>

#define MAX 100


struct Edge {
    int src, dest, weight;
};


struct Subset {
    int parent, rank;
};


int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}


void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}


int compare(const void *a, const void *b) {
    struct Edge *a1 = (struct Edge *)a;
    struct Edge *b1 = (struct Edge *)b;
    return a1->weight - b1->weight;
}


void KruskalMST(struct Edge edges[], int V, int E) {
    struct Edge result[MAX]; 
    int e = 0; 
    int i = 0; 

    if (V <= 0 || E <= 0 || V > MAX || E > MAX) {
        printf("Invalid number of vertices or edges\n");
        return;
    }
    
    qsort(edges, E, sizeof(struct Edge), compare);

    struct Subset *subsets = (struct Subset *) malloc(V * sizeof(struct Subset));
    if (subsets == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

   
    while (e < V - 1 && i < E) {
        struct Edge next_edge = edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    
    printf("\nEdges in the Minimum Spanning Tree:\n");
    int minimumCost = 0;
    for (i = 0; i < e; ++i) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
        minimumCost += result[i].weight;
    }
    printf("Minimum Cost of Spanning Tree = %d\n", minimumCost);
    free(subsets);  // Free allocated memory
}


int main() {
    int V, E;
    struct Edge edges[MAX];

    printf("Enter number of vertices: ");
    if (scanf("%d", &V) != 1 || V <= 0 || V > MAX) {
        printf("Invalid number of vertices. Must be between 1 and %d\n", MAX);
        return 1;
    }

    printf("Enter number of edges: ");
    if (scanf("%d", &E) != 1 || E <= 0 || E > MAX) {
        printf("Invalid number of edges. Must be between 1 and %d\n", MAX);
        return 1;
    }

    printf("Enter each edge (source destination weight):\n");
    for (int i = 0; i < E; i++) {
        printf("Edge %d: ", i + 1);
        if (scanf("%d%d%d", &edges[i].src, &edges[i].dest, &edges[i].weight) != 3) {
            printf("Invalid input format. Please enter three numbers\n");
            return 1;
        }
        
        // Validate vertex numbers
        if (edges[i].src < 0 || edges[i].src >= V || edges[i].dest < 0 || edges[i].dest >= V) {
            printf("Invalid vertex numbers. Must be between 0 and %d\n", V - 1);
            return 1;
        }

        // Validate weight
        if (edges[i].weight < 0) {
            printf("Invalid weight. Must be non-negative\n");
            return 1;
        }
    }

    KruskalMST(edges, V, E);

    return 0;
}
