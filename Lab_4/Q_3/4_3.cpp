#include<bits/stdc++.h>
using namespace std;

using ll = long long;

// Using Priority Queue (Min Heap) ---- Time Complexity is O(klogn)
ll Kthlargest_MH(ll arr[], ll size, ll k){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < size; i++){
        pq.push(arr[i]);
        if(pq.size() > k) pq.pop();
    }
    return pq.top();
}

// Using Quick Sort algorith ---- Worst Case Time complexity is O(n^2)
ll Partition(ll arr[], ll l, ll r){
    ll lst = arr[r], i = l, j = l;
    while (j < r) {
        if (arr[j] < lst) {
            swap(arr[i], arr[j]);
            i++;
        }
        j++;
    }
    swap(arr[i], arr[r]);
    return i;
}
ll Kthlargest_QS(ll arr[], ll l, ll r, ll k){
    if(l <= r){
        ll n = r - l + 1;
        ll pivot = rand() % n;
        swap(arr[l + pivot], arr[r]);
        ll ind = Partition(arr, l, r);

        if(ind == k){
            return arr[ind];
        }
        if(ind >= k){
            return Kthlargest_QS(arr, l, ind - 1, k);
        }
        else{
            return Kthlargest_QS(arr, ind + 1, r, k);
        }
    }
    return -1;
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll size, k;
    cin >> size >> k;

    ll arr[size];
    for(int i = 0; i < size; i++) cin >> arr[i];

    cout << "Kth largest element using Min Heap is " << Kthlargest_MH(arr, size, k) << "\n";
    cout << "Kth largest element using Quick Sort is " << Kthlargest_QS(arr, 0, size - 1, size - k) << "\n";

}