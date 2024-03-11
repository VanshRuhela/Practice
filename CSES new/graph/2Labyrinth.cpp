// === Debug macro starts here ===
#include <bits/stdc++.h>
using namespace std;
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
// === Debug macro Bs here ===
/*=============================================================================
#  PROBLEM:           You are given a map of a labyrinth, and your task is to
find a path from start to B. You can walk left, right, up and down. Input The
first input line has two integers n and m: the height and width of the map. Then
there are n lines of m characters describing the labyrinth. Each character is .
(floor), # (wall), A (start), or B (B). There is exactly one A and one B in
the input. Output First print "YES", if there is a path, and "NO" otherwise. If
there is a path, print the length of the shortest such path and its description
as a string consisting of characters L (left), R (right), U (up), and D (down).
You can print any valid solution. Constraints

1 <= n,m <= 1000

Example
Input:
5 8
########
#.A#...#
#.##.#B#
#......#
########

Output:
YES
9
LDDRRRRRU



=============================================================================*/

int n;
int m;

char G[1005][1005];
int D[1005][1005];
int prevstep[1005][1005];
pair<int, int> A;
pair<int, int> B;

int dirx[4] = {0, 0, -1, 1};
int diry[4] = {1, -1, 0, 0};
char dir[4] = {'R', 'L', 'U', 'D'};

bool isValid(int y, int x) {
    if (y < 0) return false;
    if (x < 0) return false;
    if (y >= n) return false;
    if (x >= m) return false;
    if (G[y][x] == '#') return false;
    if (D[y][x] != INT_MAX) return false;
    return true;
}

void BFS() {
    queue<pair<int, int>> q;
    q.push(A);
    D[A.first][A.second] = 0;
    // prevstep[A.first][A.second]= '';
    // tr(q);
    while (q.size() != 0) {
        pair<int, int> node = q.front();
        q.pop();

        // cout<<"node " << node.first <<" "<< node.second;

        for (int i = 0; i < 4; i++) {
            int nx = node.first + dirx[i];
            int ny = node.second + diry[i];
            if (isValid(nx, ny)) {
                q.push(make_pair(nx, ny));
                D[nx][ny] = D[node.first][node.second] + 1;
                prevstep[nx][ny] = i;
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> G[i][j];
            D[i][j] = INT_MAX;
            if (G[i][j] == 'A') A = make_pair(i, j);
            if (G[i][j] == 'B') B = make_pair(i, j);
            // path[i][j] = "";
        }
    }

    BFS();

    int ans = D[B.first][B.second];
    if (ans != INT_MAX) {
        cout << "YES\n";
        cout << ans << "\n";
        vector<int> steps;
        while (B != A) {
            int p = prevstep[B.first][B.second];
            steps.push_back(p);
            B = make_pair(B.first - dirx[p], B.second - diry[p]);
        }
        string stepDir = "RLUD";

        reverse(steps.begin(), steps.end());
        // cout << steps.size() << "\n";
        for (char c : steps) cout << stepDir[c];
        cout << "\n";
    } else
        cout << "NO\n";
    return 0;
}


//  Equivalent DFS SOlution
/* #include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1000;
char grid[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
pair<int, int> start, end;
int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char dir[4] = {'U', 'R', 'D', 'L'};
pair<int, int> parent[MAX_N][MAX_N];

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#' && !visited[x][y];
}

void dfs(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny)) {
            parent[nx][ny] = {x, y};
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') start = {i, j};
            if (grid[i][j] == 'B') end = {i, j};
        }
    }
    dfs(start.first, start.second);
    if (!visited[end.first][end.second]) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        string path;
        while (end != start) {
            pair<int, int> p = parent[end.first][end.second];
            if (end.first - p.first == 1) path += 'D';
            else if (end.first - p.first == -1) path += 'U';
            else if (end.second - p.second == 1) path += 'R';
            else path += 'L';
            end = p;
        }
        reverse(path.begin(), path.end());
        cout << path.size() << "\n" << path << "\n";
    }
    return 0;
} */