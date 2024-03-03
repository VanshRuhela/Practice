/*
You are given a map of a building, and your task is to count the number of its
rooms. The size of the map is n \times m squares, and each square is either
floor or wall. You can walk left, right, up, and down through the floor squares.
Input
The first input line has two integers n and m: the height and width of the map.
Then there are n lines of m characters describing the map. Each character is
either . (floor) or # (wall). Output Print one integer: the number of rooms.
Constraints

1 \le n,m \le 1000

Example
Input:
5 8
########
#..#...#
####.#.#
#..#...#
########

Output:
3

. (floor) or # (wall).

*/

#include <iostream>
#include <vector>
using namespace std;

int n = 0, m = 0;
char graph[1001][10001];
int vis[1001][1001];

int dirx[4] = {0, 0, -1, 1};
int diry[4] = {1, -1, 0, 0};

bool findRooms(int i, int j) {
    if (graph[i + 1][j] == '#' and graph[i - 1][j] == '#' and
        graph[i][j + 1] == '#' and graph[i][j - 1] == '#')
        return true;
}

bool isValid(int y, int x) {
    if (y < 0) return false;
    if (x < 0) return false;
    if (y >= n) return false;
    if (x >= m) return false;
    if (graph[y][x] == '#') return false;
    return true;
}

void DFS(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int dx = x + dirx[i];
        int dy = y + diry[i];
        if(isValid(dx , dy)){
            if(!vis[dx][dy])
                DFS(dx , dy);
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            vis[i][j] = 0;
        }
    }

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == '.' and !vis[i][j]) {
                DFS(i, j);
                cnt++;
            }
        }
    }

    cout<<cnt<<"\n";

    return 0;
}