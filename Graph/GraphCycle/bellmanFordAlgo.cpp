/*=============================================================================
#  PROBLEM:           Given a graph and a source vertex src in graph, find
shortest paths from src to all vertices in the given graph. The graph may
contain negative weight edges.

Algorithm:

Following are the detailed steps.

Input: Graph and a source vertex src
Output: Shortest distance to all vertices from src. If there is a negative
weight cycle, then shortest distances are not calculated, negative weight cycle
is reported.

1) This step initializes distances from the source to all vertices as infinite
and distance to the source itself as 0. Create an array dist[] of size |V| with
all values as infinite except dist[src] where src is source vertex. 2) This step
calculates shortest distances. Do following |V|-1 times where |V| is the number
of vertices in given graph. …..a) Do following for each edge u-v ………………If
dist[v] > dist[u] + weight of edge uv, then update dist[v] ………………….dist[v] =
dist[u] + weight of edge uv 3) This step reports if there is a negative weight
cycle in graph. Do following for each edge u-v ……If dist[v] > dist[u] + weight
of edge uv, then “Graph contains negative weight cycle” The idea of step 3 is,
step 2 guarantees the shortest distances if the graph doesn’t contain a negative
weight cycle. If we iterate through all edges one more time and get a shorter
path for any vertex, then there is a negative weight cycle

How does this work? Like other Dynamic Programming Problems, the algorithm
calculates shortest paths in a bottom-up manner. It first calculates the
shortest distances which have at-most one edge in the path. Then, it calculates
the shortest paths with at-most 2 edges, and so on. After the i-th iteration of
the outer loop, the shortest paths with at most i edges are calculated. There
can be maximum |V| – 1 edges in any simple path, that is why the outer loop runs
|v| – 1 times. The idea is, assuming that there is no negative weight cycle, if
we have calculated shortest paths with at most i edges, then an iteration over
all edges guarantees to give shortest path with at-most (i+1) edges (Proof is
simple, you can refer this or MIT Video Lecture)

Example:

Let us understand the algorithm with following example graph. The images are
taken from this source. Let the given source vertex be 0. Initialize all
distances as infinite, except the distance to the source itself. Total number of
vertices in the graph is 5, so all edges must be processed 4 times.


Bellman–Ford Algorithm Example Graph 1

Let all edges are processed in the following order: (B, E), (D, B), (B, D), (A,
B), (A, C), (D, C), (B, C), (E, D). We get the following distances when all
edges are processed the first time. The first row shows initial distances. The
second row shows distances when edges (B, E), (D, B), (B, D) and (A, B) are
processed. The third row shows distances when (A, C) is processed. The fourth
row shows when (D, C), (B, C) and (E, D) are processed.


Bellman–Ford Algorithm Example Graph 2

The first iteration guarantees to give all shortest paths which are at most 1
edge long. We get the following distances when all edges are processed second
time (The last row shows final values).


Bellman–Ford Algorithm Example Graph 3

The second iteration guarantees to give all shortest paths which are at most 2
edges long. The algorithm processes all edges 2 more times. The distances are
minimized after the second iteration, so third and fourth iterations don’t
update the distances.

=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
};

void printArr(int dist[], int n) {
    cout << "Vertex dist from src\n";
    for (int i = 0; i < n; i++) cout << i << " " << dist[i] << "\n";
}

void BellmanFord(struct Graph* graph, int src) {
    int V = graph->V;
    int E = graph->E;
    int dist[V];
    memset(dist, INT_MAX, V);

    dist[src] = 0;

    for (int i = 1; i < V; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int w = graph->edge[j].weight;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    // checking for cycles
    for (int i = 0; i < E; i++) {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle");
            return;
        }
    }

    printArr(dist, V);
}

int main() {
    int V = 5;  // Number of vertices in graph
    int E = 8;  // Number of edges in graph
    struct Graph* graph = createGraph(V, E);

    // add edge 0-1 (or A-B in above figure)
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = -1;

    // add edge 0-2 (or A-C in above figure)
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 4;

    // add edge 1-2 (or B-C in above figure)
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 3;

    // add edge 1-3 (or B-D in above figure)
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 2;

    // add edge 1-4 (or B-E in above figure)
    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 2;

    // add edge 3-2 (or D-C in above figure)
    graph->edge[5].src = 3;
    graph->edge[5].dest = 2;
    graph->edge[5].weight = 5;

    // add edge 3-1 (or D-B in above figure)
    graph->edge[6].src = 3;
    graph->edge[6].dest = 1;
    graph->edge[6].weight = 1;

    // add edge 4-3 (or E-D in above figure)
    graph->edge[7].src = 4;
    graph->edge[7].dest = 3;
    graph->edge[7].weight = -3;

    BellmanFord(graph, 0);

    return 0;
}