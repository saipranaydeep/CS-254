#include <iostream>
#include <vector>

using namespace std;

int numVertices;

bool isBipartite(int startVertex, int color, vector<int> &colors, vector<vector<bool>> &graph) {
    if (colors[startVertex] > -1) {
        if (color != colors[startVertex])
            return false;
        return true;
    }
    colors[startVertex] = color;
    for (int i = 0; i < numVertices; i++)
        if (graph[startVertex][i] && !isBipartite(i, 1 - color, colors, graph))
            return false;
    return true;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int testCases;
    cin >> testCases;
    while (testCases--) {
        cin >> numVertices;
        vector<vector<bool>> adjacencyMatrix(numVertices, vector<bool>(numVertices));
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                bool connected;
                cin >> connected;
                if (i != j)
                    adjacencyMatrix[i][j] = !connected;
            }
        }
        vector<int> colors(numVertices, -1);
        int result = 1;
        for (int i = 0; i < numVertices; i++)
            if (colors[i] == -1)
                if (!isBipartite(i, 0, colors, adjacencyMatrix))
                    result = 0;
        if (result)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
