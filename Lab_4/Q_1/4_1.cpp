#include<bits/stdc++.h>
using namespace std;

using ll = long long;
// Time complexity is O(nlogn) 
// Space complexity is O(n)

ll merge(ll arr[], ll start, ll mid, ll end) {
    ll s1 = mid - start + 1;
    ll s2 = end - mid;

    // Creating two arrays and copying values
    ll *one = new ll[s1];
    ll *two = new ll[s2];

    for (int i = 0; i < s1; i++) one[i] = arr[start + i];
    for (int i = 0; i < s2; i++) two[i] = arr[mid + 1 + i];

    ll i = 0, j = 0, k = 0, ans = 0;

    while(i < s1 && j < s2) {
        if(one[i] <= two[j]) arr[start + k++] = one[i++];
        else {
            arr[start + k++] = two[j++];
            ans += s1 - i;
        }
    }

    while(i < s1) arr[start + k++] = one[i++];
    while(j < s2) arr[start + k++] = two[j++];

    delete[] one;
    delete[] two;
    return ans;
}

ll totInversions(ll arr[], ll start, ll end) {
    ll ans = 0;
    if(start < end) {
        ll mid = start + (end - start) / 2;
        ans += totInversions(arr, start, mid);
        ans += totInversions(arr, mid + 1, end);
        ans += merge(arr, start, mid, end);
    }
    return ans;
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll size;
    cin >> size;
    ll arr[size];

    for(int i = 0; i < size; i++) cin >> arr[i];

    cout << "Number of inversions in the array are " << totInversions(arr, 0, size - 1);
}
