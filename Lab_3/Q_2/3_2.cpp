#include<bits/stdc++.h>
using namespace std;

using ll = long long;

// OneTime Traversal O(n) solution
ll maximumSumOfSubarray(ll arr[], ll n) {
    ll maxSum = INT_MIN;
    ll currSum = 0;
    for(int i = 0; i < n; i++) {
        if(currSum + arr[i] <= 0){
            currSum = 0;
            maxSum = max(maxSum, arr[i]);
        }
        else {
            currSum += arr[i];
            maxSum = max(maxSum, currSum);
        }
    }
    return maxSum;
}

// Divide and Conquer O(nlogn) solution
ll sumWithMid(ll arr[], ll l, ll m, ll h) {
    // Includes left elements
    ll sum = 0;
    ll left_sum = INT_MIN;
    for(int i = m; i >= l; i--) {
        sum += arr[i];
        if(sum > left_sum) left_sum = sum;
    }

    // Includes right elements
    sum = 0;
    ll right_sum = INT_MIN;
    for(int i = m; i <= h; i++) {
        sum += arr[i];
        if(sum > right_sum) right_sum = sum;
    }
    return max(right_sum + left_sum - arr[m], max(left_sum, right_sum));
}
ll DCsum(ll arr[], ll l, ll h) {
    if(l > h) return INT_MIN;
    if(l == h) return arr[l];
    ll m = l + (h -l) / 2;
    ll left = DCsum(arr, l, m - 1);
    ll right = DCsum(arr, m + 1, h);
    ll midInc = sumWithMid(arr, l, m, h);

    return max(midInc, max(left, right));

}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll size;
    cin >> size;

    ll arr[size];
    for(int i = 0; i < size; i++) cin >> arr[i];

    cout << "Maximum sum of Subarray is " << maximumSumOfSubarray(arr, size) << "\n";
    cout << "Maximum sum of Subarray using divide and conquer O(nlogn) is " << maximumSumOfSubarray(arr, size) << "\n";

}