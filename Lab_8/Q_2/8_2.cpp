#include <bits/stdc++.h>
using namespace std;

int graph[18][18][2];
long long dp[1 << 18][18][2];

long long calculateMinCost(int n, int m, int mask, int prev, int col) {
    if (mask == ((1 << n) - 1)) {
        return 0;
    }

    if (dp[mask][prev][col] != 0) {
        return dp[mask][prev][col];
    }

    long long minimumCost = 1e9;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            if (graph[prev][i][j] && !(mask & (1 << i)) && (j != col)) {
                long long temp = graph[prev][i][j] + calculateMinCost(n, m, mask | (1 << i), i, j);
                minimumCost = min(temp, minimumCost);
            }
        }
    }

    return dp[mask][prev][col] = minimumCost;
}

void constructGraph(int m) {
    for (int i = 0; i < m; i++) {
        int a, b, cost;
        char color;
        cin >> a >> b >> cost >> color;
        a--;
        b--;
        graph[a][b][color == 'G'] = cost;
        graph[b][a][color == 'G'] = cost;
    }
}

int calculateTotalCost(int n, int m) {
    long long totalCost = 1e9;

    for (int i = 0; i < n; i++) {
        totalCost = min(totalCost, calculateMinCost(n, m, 1 << i, i, 2));
    }

    if (totalCost != 1e9) {
        return totalCost;
    }
    else {
        return -1;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n;
    cin >> m;

    constructGraph(m);
    cout << "Minimum total cost: " << calculateTotalCost(n, m) << '\n';

    return 0;
}
