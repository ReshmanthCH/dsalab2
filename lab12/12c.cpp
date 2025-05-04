#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define INF INT_MAX

int graph[MAX_VERTICES][MAX_VERTICES];
int V;

void addEdge(int u, int v, int w) {
    if (u >= 0 && u < V && v >= 0 && v < V) {
        graph[u][v] = w;
        graph[v][u] = w;
    } else {
        printf("Invalid vertices!\n");
    }
}

void displayGraph() {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", graph[i][j]);
        }
        printf("\n");
    }
}

void primMST() {
    int parent[MAX_VERTICES], key[MAX_VERTICES];
    bool inMST[MAX_VERTICES];

    for (int i = 0; i < V; i++) {
        key[i] = INF;
        inMST[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int min = INF, u;
        for (int v = 0; v < V; v++) {
            if (!inMST[v] && key[v] < min) {
                min = key[v];
                u = v;
            }
        }

        inMST[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printf("\nPrim's MST:\n");
    int cost = 0;
    for (int i = 1; i < V; i++) {
        printf("%d - %d\n", parent[i], i);
        cost += graph[i][parent[i]];
    }
    printf("Total cost: %d\n", cost);
}

int find(int parent[], int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

void unionSets(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

typedef struct {
    int src, dest, weight;
} Edge;

int compareEdges(const void* a, const void* b) {
    Edge* e1 = (Edge*)a;
    Edge* e2 = (Edge*)b;
    return e1->weight - e2->weight;
}

void kruskalMST() {
    Edge edges[MAX_VERTICES * MAX_VERTICES];
    int edgeCount = 0;

    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j] != INF) {
                edges[edgeCount++] = (Edge){i, j, graph[i][j]};
            }
        }
    }

    qsort(edges, edgeCount, sizeof(Edge), compareEdges);

    int parent[MAX_VERTICES], rank[MAX_VERTICES] = {0};
    for (int i = 0; i < V; i++)
        parent[i] = i;

    printf("\nKruskal's MST:\n");
    int cost = 0;

    for (int i = 0; i < edgeCount; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;

        int x = find(parent, u);
        int y = find(parent, v);

        if (x != y) {
            printf("%d - %d : %d\n", u, v, edges[i].weight);
            cost += edges[i].weight;
            unionSets(parent, rank, x, y);
        }
    }
    printf("Total cost: %d\n", cost);
}

void dijkstra(int start) {
    int dist[MAX_VERTICES];
    bool visited[MAX_VERTICES] = {false};

    for (int i = 0; i < V; i++)
        dist[i] = INF;

    dist[start] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = -1, min = INF;
        for (int i = 0; i < V; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1) break;
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("\nDijkstra's Shortest Path from %d:\n", start);
    for (int i = 0; i < V; i++) {
        printf("To %d : %d\n", i, dist[i]);
    }
}

int main() {
    int choice, u, v, w, src;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = INF;

    do {
        printf("\n----- Graph ADT Menu -----\n");
        printf("1. Insert Edge\n2. Display Graph\n3. Prim's MST\n4. Kruskal's MST\n5. Dijkstra's Algorithm\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter source, destination and weight: ");
                scanf("%d%d%d", &u, &v, &w);
                addEdge(u, v, w);
                break;
            case 2:
                displayGraph();
                break;
            case 3:
                primMST();
                break;
            case 4:
                kruskalMST();
                break;
            case 5:
                printf("Enter source vertex: ");
                scanf("%d", &src);
                dijkstra(src);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}