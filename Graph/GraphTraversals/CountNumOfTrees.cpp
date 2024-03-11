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

// Problem statement : find the number of connected componets in a graph
// ex 1 -- 2  4 -- 5
//    |
//    3
// ans : 2

// 0 -- 1
// |
// 2

// 3 -- 4
class Graph {
   public:
    unordered_map<int, list<int> > l;
    set<int> s;  // Fix: Add template argument specifying the type of elements
                 // stored in the set

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
        s.insert(u);
        s.insert(v);
    }
    void dfs(int e) {
        if (s.find(e) != s.end()) {
            s.erase(e);
            if (l.find(e) != l.end()) {
                for (auto x : l[e]) {
                    if (s.find(x) != s.end()) dfs(x);
                }
            }
        }
    }
    int improvedApproach() {
        int ans = 0;
        tr(s);


        while (s.size() != 0)
        {
            auto x = s.begin();
            dfs(*x);
            tr(s);
            ans++;
        }
        

        // for (auto x : s) {
        //     if (s.find(x) != s.end()) {
        //         ans++;
        //         dfs(x);
        //         tr(s);
        //     }
        // }
        return ans;
    }

    void dfs_helper(int src, map<int, bool>& visited) {
        visited[src] = true;
        for (auto nbr : l[src]) {
            if (!visited[nbr]) {
                dfs_helper(nbr, visited);
            }
        }
    }
    void dfs() {
        map<int, bool> visited;

        for (auto x : l) {
            int node = x.first;
            visited[node] = false;
        }

        int res = 0;

        for (auto x : l) {
            if (visited[x.first] == false) {  // visited nahi hai
                dfs_helper(x.first, visited);
                res++;
            }
        }

        cout << res << "\n";
    }
};

int main() {
    Graph g;
    int n;
    cin >> n;
    while (n--) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    g.dfs();

    cout << "improved -- \n";
    cout << g.improvedApproach() <<"\n";

    return 0;
}
