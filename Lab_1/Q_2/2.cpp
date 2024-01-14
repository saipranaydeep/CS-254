#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll knapsack(ll Weight, ll weight[], ll value[], ll n, vector<vector<ll>> &dp) {
    if(n < 0 || Weight == 0) return 0;

    if(dp[n][Weight] != -1) return dp[n][Weight];

    if(weight[n] > Weight) { 
        return dp[n][Weight] = knapsack(Weight, weight, value, n - 1, dp);
    }

    return dp[n][Weight] = max(value[n] + knapsack(Weight - weight[n], weight, value, n - 1, dp), knapsack(Weight, weight, value, n - 1, dp));
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);    

    ll size;
    cin >> size;

    ll weight[size],value[size];
    for(int i = 0; i < size; i++) cin >> weight[i];
    for(int i = 0; i < size; i++) cin >> value[i];

    ll maxWeight;
    cin >> maxWeight;

    ll answer = 0;

    vector<vector<ll>> dp(size , vector<ll> (maxWeight + 1, -1));

    cout << knapsack(maxWeight, weight, value, size - 1, dp) << "\n";

}