#include <bits/stdc++.h>
using namespace std;

class Graph{
    unordered_map<string , list <pair<string,int>>>l;
public:
    void addEdge(string x, string y, bool bidir, int wt){
        l[x].push_back({y,wt});

        if(bidir)
            l[y].push_back({x,wt});
        
    }

    void printGraph(){
        for(auto p : l){
            string city = p.first;

            list<pair<string, int>> nbrs = p.second;
            cout<<city <<" ";
            for(auto nbr : nbrs){
                cout<< nbr.first <<" "<<nbr.second <<" ";
            }
        cout<<"\n";
        }
    }


    
};


int main(){

    Graph g;
    g.addEdge("A", "B" , true, 2);
    g.addEdge("B", "C" , true, 2);
    g.addEdge("C", "D" , true, 2);
    g.addEdge("A", "D" , true, 2);
    g.addEdge("A", "C" , true, 2);
    g.printGraph();
    return 0;



}