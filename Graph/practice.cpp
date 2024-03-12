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
#  PROBLEM:           Detect cycle in an undirected graph

Given an undirected graph, how to check if there is a cycle in the graph?

Example,

Input: n = 4, e = 4
0 1, 1 2, 2 3, 0 2

Output: Yes
=============================================================================*/
map<int, vector<int>> g;
int n, e;
vector<bool> vis;

bool cycleDhund(int src, int last) {
    cout << src << " l " << last << "\n";
    // -1,0v -> 1v, 2v
    // 1v -> 0v, 2v
    // 2v -> 0, 1
    // 1 -- 0 -- 2 ... 1
    if (vis[src] == true and src != last) return true;
    vis[src] = true;
    for (auto x : g[src]) {
        if (x != last && vis[x]) return true;
        if (!vis[x] && cycleDhund(x, src)) return true;
    }
    return false;
}

int main() {
    cin >> n >> e;

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vis.resize(n + 1, false);
    for (auto x : vis) cout << x << " ";

    cycleDhund(1, -1) ? cout << "hai " : cout << "\nnhi h";
}