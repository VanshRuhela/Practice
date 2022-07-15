/*=============================================================================
#  PROBLEM:          FInding the single source shortest path

dist calc by level order = shortest dist
unweighted graphs

=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

template <typename T>

class Graph {
   public:
   list<int>* l;
   Graph(int V){
    l = new list<int>[V];
   }
   void addEdge(int x , int y){
    l[x].push_back(y);
    l[y].push_back(x);
   }
    void bfs(int src) {
        map<T, int> dist;
        queue<T> q;
       

        for(auto node_pair : l){
            T node = node_pair.fist;
            dist[node] = INT_MAX;
        }
         q.push(src);
        visited[src] = 0;
        while (!q.empty()) {
            T node = q.front();
            q.pop();
            
            for(int nbr : l[node]){
                if(dist[nbr] == INT_MAX){
                    q.push(nbr);
                   // visited[nbr] = true;
                    dist[nbr] = dist[node] + 1;
                }
            }
        }
    }
};

int main() { return 0; }