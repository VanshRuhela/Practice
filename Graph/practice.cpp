#include <bits/stdc++.h>
using namespace std;
// === Debug macro starts here ===

#define tr(...) pr("(", __LINE__, ")[", #__VA_ARGS__, "]: ["), pc(__VA_ARGS__)

template <class T1, class T2>
istream& operator>>(istream& is, pair<T1, T2>& p) {
    is >> p.first >> p.second;
    return is;
}
template <class T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto& x : v) is >> x;
    return is;
}
auto re = [](auto&&... args) { (cin >> ... >> args); };

template <class T1, class T2>
ostream& operator<<(ostream& os, pair<T1, T2> p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

#define Vout(Con)                                 \
    template <class T>                            \
    ostream& operator<<(ostream& os, Con<T>& v) { \
        bool fst = 1;                             \
        os << "{";                                \
        for (auto& x : v) {                       \
            if (!fst) os << ", ";                 \
            os << x;                              \
            fst = 0;                              \
        }                                         \
        os << "}";                                \
        return os;                                \
    }
#define Vout2(Con)                                     \
    template <class T1, class T2>                      \
    ostream& operator<<(ostream& os, Con<T1, T2>& v) { \
        bool fst = 1;                                  \
        os << "{";                                     \
        for (auto& [x, y] : v) {                       \
            if (!fst) os << ", ";                      \
            os << x << ": " << y;                      \
            fst = 0;                                   \
        }                                              \
        os << "}";                                     \
        return os;                                     \
    }
Vout(vector) Vout(set) Vout(multiset) Vout2(map)

#define Out(f, delim, lst)                    \
    auto f = [](auto&& arg, auto&&... args) { \
        cout << arg;                          \
        ((cout << delim << args), ...);       \
        cout << lst;                          \
    };
    Out(pr, "", "") Out(pw, ' ', ' ') Out(ps, ' ', '\n';)
        Out(pc, ", ", "]" << '\n';)

            auto ptrace = [](const char* name, auto&& A, auto&&... rest) {
                const char* open = strchr(name, '[');
                cout.write(name, open - name);
                ((cout << '[' << rest << ']'), ...);
                cout << " = " << A << '\n';
                ;
            };
// === Debug macro ends here ===

/*=============================================================================
#  PROBLEM: single source shortest path
You are given an undirected graph with n nodes (numbered from 1 to n). The graph
is represented by a list of edges where each edge consists of two nodes x and y,
indicating that there is an edge between node x and node y.

Your task is to implement a function that finds the shortest path from a given
source node src to all other nodes in the graph. The distance between two
adjacent nodes is considered as 1. If a node is unreachable from the source
node, the distance to that node should be represented as INT_MAX
=============================================================================*/
template <typename T>
class Graph {
    map<T, list<T>> l;

   public:
    void addEdge(int x, int y) {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void bfs(T src) {
        unordered_map<T, int> dist;
        queue<T> q;

        for (auto node_pair : l) {
            T node = node_pair.first;
            dist[node] = INT_MAX;
        }
        q.push(src);
        dist[src] = 0;

        while (!q.empty()) {
            T curr = q.front();
            q.pop();

            for (auto x : l[curr]) {
                if (dist[x] == INT_MAX) {  // unvisited neighbour
                    q.push(x);
                    dist[x] = dist[curr] + 1;
                }
            }
        }

        // printing the dist to every node

        for (auto node_pair : l) {
            T node = node_pair.first;
            cout << "Node: " << node << " Dist from src " << dist[node] << "\n";
        }
    }
};

int main() {
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.bfs(0);
}