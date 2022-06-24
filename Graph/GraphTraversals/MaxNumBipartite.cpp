/*=============================================================================
#  PROBLEM:           Maximum number of edges to be added to a tree so that it
stays a Bipartite graph.
A tree is always a Bipartite Graph as we can always
break into two disjoint sets with alternate levels. In other words we always
color it with two colors such that alternate levels have same color. The task is
to compute the maximum no. of edges that can be added to the tree so that it
remains Bipartite Graph. Examples:


Input : Tree edges as vertex pairs
        1 2
        1 3
Output : 0
Explanation :
The only edge we can add is from node 2 to 3.
But edge 2, 3 will result in odd cycle, hence
violation of Bipartite Graph property.

Input : Tree edges as vertex pairs
        1 2
        1 3
        2 4
        3 5
Output : 2
Explanation : On colouring the graph, {1, 4, 5}
and {2, 3} form two different sets. Since, 1 is
connected from both 2 and 3, we are left with
edges 4 and 5. Since, 4 is already connected to
2 and 5 to 3, only options remain {4, 3} and
{5, 2}.

1) Do a simple DFS (or BFS) traversal of graph and color it with two colors. 
2) While coloring also keep track of counts of nodes colored with the two colors. Let the two counts be count_color0 and count_color1. 
3) Now we know maximum edges a bipartite graph can have are count_color0 x count_color1. 
4) We also know tree with n nodes has n-1 edges. 
5) So our answer is count_color0 x count_color1 – (n-1).


=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

#define MAX 10001
vector<int> adj[MAX];

int cnt_color[2];

void dfs(int node, int parent , int color){
    cnt_color[color]++;

    for(int i=0; i<adj[node].size(); i++){
        if(adj[node][i] != parent){
            dfs(adj[node][i] , node , !color);
        }
    }
}

int findMaxEdges(int n){
    dfs(1,0,0);

    return cnt_color[0] * cnt_color[1] - (n-1);
}

int main() { 
    int n = 5;
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[3].push_back(5);
    cout << findMaxEdges(n);
    return 0;
}