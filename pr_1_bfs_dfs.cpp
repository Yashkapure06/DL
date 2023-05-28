#include <bits/stdc++.h>
#include <omp.h>

using namespace std;

const int N = 1e5 + 5;
vector<int> g[N];
bool vis[N];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    vis[s] = true;

    while (!q.empty()) {
        int u = q.front();
        cout << u << " ";
        q.pop();

        #pragma omp parallel for
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

void dfs(int u) {
    vis[u] = true;
    cout << u << " ";
    

    #pragma omp parallel for
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (!vis[v])
            dfs(v);
    }
}

int main() {
    int n, m, s, choice;
    cin >> n >> m >> s >> choice;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    if (choice == 1){
        cout << "BFS : ";
        bfs(s);}
    else if (choice == 2){
        cout << "DFS : ";
        dfs(s);}
    else
        cout << "Invalid choice\n";
    

    return 0;
}


// Test cases:
// Input:
// 6 7 1 1
// 1 2
// 1 3
// 2 4
// 2 5
// 3 5
// 4 6
// 5 6
// Output:
// The result of traversal:
// BFS 1 2 3 4 5 6
// DFS : 1 2 4 6 5 3