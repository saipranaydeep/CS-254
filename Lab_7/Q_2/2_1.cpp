#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<pair<string, pair<int,int>>> jobs(n);
    int max_deadline = 0;
    for(int i = 0; i < n; i++){
        cin >> jobs[i].first;
        cin >> jobs[i].second.first;
        cin >> jobs[i].second.second;
        max_deadline = max(max_deadline, jobs[i].second.first);
    }
    int max_profit = 0;
    vector<string> vis(max_deadline, "null");
    sort(jobs.begin(), jobs.end(), [](const pair<string, pair<int, int>>& a, const pair<string, pair<int, int>>& b){
        return a.second.second > b.second.second;
    });

    for(int i = 0; i < n; i++) {
        int deadline = jobs[i].second.first;
        int profit = jobs[i].second.second;
        while(deadline >= 1 && vis[deadline-1] != "null") {
            deadline--;
        }
        if(deadline >= 1){
            vis[deadline-1] = jobs[i].first;
            max_profit += profit;
        }
    }
    cout << "Following is the maximum profit sequence of jobs: [";
    for(string x : vis) if(x != "null") cout << x << " ";
    cout << "], Total Profit = " << max_profit << "\n";
    return 0;
}
