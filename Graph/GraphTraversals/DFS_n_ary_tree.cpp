/*=============================================================================
#  PROBLEM: DFS for a n-ary tree (acyclic graph) represented as adjacency l
A tree consisting of n nodes is given, we need to print its DFS.
Examples :

Input : Edges of graph
        1 2
        1 3
        2 4
        3 5
Output : 1 2 4 3 5
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

// Graph
#define MAX 10001
vector<int> l[MAX];

void dfs(int node , int arrival){
    cout<< node <<"\n";

    for(int i=0; i<l[node].size(); i++){
        if(l[node][i] != arrival)
            dfs(l[node][i] , node);
    }
}

int main() {
    int n = 5;
    l[1].push_back(2);
    l[2].push_back(1);

    l[1].push_back(3);
    l[3].push_back(1);

    l[2].push_back(4);
    l[4].push_back(2);

    l[3].push_back(5);
    l[5].push_back(3);

    dfs(1,0);

    return 0;
}