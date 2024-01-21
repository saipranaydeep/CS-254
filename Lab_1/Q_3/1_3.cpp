#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int calculateTotalDistance(const vector<vector<int>>& graph, const vector<int>& path) {
    int totalDistance = 0;
    int n = path.size();

    for (int i = 0; i < n - 1; ++i) {
        int from = path[i];
        int to = path[i + 1];
        totalDistance += graph[from][to];
    }

    totalDistance += graph[path[n - 1]][path[0]];

    return totalDistance;
}

void tspBruteForce(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> path(n);
    for (int i = 0; i < n; ++i) {
        path[i] = i;
    }

    int minDistance = INT_MAX;
    vector<int> minPath;

    do {
        int currentDistance = calculateTotalDistance(graph, path);
        if (currentDistance < minDistance) {
            minDistance = currentDistance;
            minPath = path;
        }
    } while (next_permutation(path.begin() + 1, path.end()));

    cout << "Optimal TSP Tour: ";
    cout << "Total Distance: " << minDistance << endl;
}


int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);    

    ll size;
    cin >> size;

    vector<vector<ll>> graph(size, vector<ll>(size));

    for(int i = 0; i < size; i++) for(int j = 0; j < size; j++) cin >> graph[i][j];

    vector<int> path(size);
    for (int i = 0; i < size; ++i) {
        path[i] = i;
    }

    int minDistance = INT_MAX;
    vector<int> minPath;

    do {
        int totalDistance = 0;
        for (int i = 0; i < size - 1; ++i) {
            int from = path[i];
            int to = path[i + 1];
            totalDistance += graph[from][to];
        }

        totalDistance += graph[path[size - 1]][path[0]];
        if (totalDistance < minDistance) {
            minDistance = totalDistance;
            minPath = path;
        }
    } while (next_permutation(path.begin() + 1, path.end()));

    cout << minDistance << endl;    
}