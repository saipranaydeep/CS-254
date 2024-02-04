#include<bits/stdc++.h>
using namespace std;

using ll = long long;

// Time complexity of the code is O(min(size1, size2))

double Median(vector<ll> arr1, vector<ll> arr2) {
    int n1 = arr1.size();
    int n2 = arr2.size();

    if(n1 > n2) return Median(arr2, arr1); // Making arr1 as small beacuse we are using binary search, so less the size less the Time Complexity.

    ll half = (n1 + n2 + 1) / 2;
    ll low = 0, high = n1;             // In array 1
    while(low <= high) {
        ll partition1 =  low + (high - low) / 2;
        ll partition2 = half - partition1;

        // Checking bounds and taking 4 pointers
        ll left_1 = (partition1 > 0) ? arr1[partition1 - 1] : INT_MIN;
        ll left_2 = (partition2 > 0) ? arr2[partition2 - 1] : INT_MIN;
        ll right_1 = (partition1 < n1) ? arr1[partition1] : INT_MAX;
        ll right_2 = (partition2 < n2) ? arr2[partition2] : INT_MAX;

        if(left_1 <= right_2 && left_2 <= right_1) {
            if((n1 + n2) & 1) return max(left_1, left_2);
            else return ((double) (max(left_1, left_2) + min(right_1, right_2)) / 2.0);
        }
        else if(left_2 > right_1) low = partition1 + 1;
        else high = partition1 - 1;
    }
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    ll size1, size2;
    cin >> size1 >> size2;
    vector<ll> arr1(size1), arr2(size2);

    for(int i = 0; i < size1; i++) cin >> arr1[i];
    for(int i = 0; i < size2; i++) cin >> arr2[i];

    cout << "Median of two sorted arrays is " << Median(arr1, arr2);

}