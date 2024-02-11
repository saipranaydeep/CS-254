#include <bits/stdc++.h>
using namespace std;

int numRows, numCols;

void explore(int row, int col, int &regionSize, vector<vector<int>> &grid) {
    if (row < 0 || row >= numRows || col < 0 || col >= numCols || grid[row][col] != 1)
        return;
    grid[row][col] = -1;
    regionSize++;
    explore(row - 1, col - 1, regionSize, grid);
    explore(row - 1, col, regionSize, grid);
    explore(row - 1, col + 1, regionSize, grid);
    explore(row, col - 1, regionSize, grid);
    explore(row, col + 1, regionSize, grid);
    explore(row + 1, col - 1, regionSize, grid);
    explore(row + 1, col, regionSize, grid);
    explore(row + 1, col + 1, regionSize, grid);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int numTestCases;
    cin >> numTestCases;
    while (numTestCases--) {
        cin >> numRows >> numCols;
        vector<vector<int>> grid(numRows, vector<int>(numCols));
        for (int i = 0; i < numRows; i++)
            for (int j = 0; j < numCols; j++)
                cin >> grid[i][j];
        int largestRegionSize = 0;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                if (grid[i][j] == 1) {
                    int currentRegionSize = 0;
                    explore(i, j, currentRegionSize, grid);
                    largestRegionSize = max(largestRegionSize, currentRegionSize);
                }
            }
        }
        cout << "Largest Region Size: " << largestRegionSize << endl;
    }
    return 0;
}
