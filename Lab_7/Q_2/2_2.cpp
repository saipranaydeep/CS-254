#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solution(vector <vector<int>> jobs, string names[]){
    // jobs(idx, deadline, profit)
    int n = jobs.size();

    sort(jobs.begin(), jobs.end(), [](const vector<int>&a, const vector<int>&b){
        return a[2] > b[2];
    });
    // for(auto itr : jobs){
    //     cout << itr[2] << endl;
    // }
    cout << "Following is the maximum profit sequence of jobs: [ ";
    int max_profit = 0;
    int curr_time = 0;
    for(auto itr : jobs){
        if(itr[1] - curr_time > 0){
            max_profit+=itr[2];
            cout << names[itr[0]] << " ";
            curr_time++;
        }
    }
    cout << "], Total profit = " << max_profit << endl;
    return;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string *job_names = new string[n];
        vector <vector<int>> jobs(n, vector<int>(4));
        for(int i = 0; i < n; i++){
            jobs[i][0] = i;
            cin >> job_names[i];
        }
        for(int i = 0; i < n; i++) cin >> jobs[i][1];
        for(int i = 0; i < n; i++) cin >> jobs[i][2];

        solution(jobs, job_names);
    }
}
