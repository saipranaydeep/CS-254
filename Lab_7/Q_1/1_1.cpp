#include <bits/stdc++.h>
using namespace std;

int knapsack_10(int i, int w, string* items, vector<vector<int>> k, vector<vector<int>> &dp, set<string> &to_include){
    if(w < 0 || i < 0) return INT_MIN;
    if(dp[i][w] != -1) return dp[i][w];

    if(i == 0 || w == 0) return dp[i][w] = 0;
    if(w < k[i-1][1]) return dp[i][w] = knapsack_10(i-1, w, items, k, dp, to_include);

    return dp[i][w] = max(k[i - 1][2] + knapsack_10(i - 1, w - k[i - 1][1], items, k, dp, to_include), knapsack_10(i - 1, w, items, k, dp, to_include));

}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
    int T; 
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        string *items = new string[n];
        vector<vector<int>> knapsack(n, vector<int>(3));

        for(int i = 0; i < n; i++){
            knapsack[i][0] = i;
            cin >> items[i];
        }
        for(int i = 0; i < n; i++) cin >> knapsack[i][1];
        for(int i = 0; i < n; i++) cin >> knapsack[i][2];

        int W; cin >> W;
        sort(knapsack.begin(), knapsack.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
        });
        
        vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
        set<string> to_include;
        int prof = knapsack_10(n, W, items, knapsack, dp, to_include);

        // for printing what objects are selected
        int curr_prof = prof;
        int i = n, w = W;
        while(curr_prof != 0){
            if(dp[i-1][w] == dp[i][w]){
                i = i - 1;
            }
            else{
                cout << items[knapsack[i-1][0]] << " ";
                curr_prof -= knapsack[i-1][2];
                w -= knapsack[i-1][1];
                i -= 1;
            }
        }


        cout << "with profit " << prof << endl;
    }
}