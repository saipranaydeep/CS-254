#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void merge(ll arr[], ll ind1, ll ind2, ll size) {
    while(ind1 < size && ind2 < size && ind1 < ind2) {
        if(arr[ind1] <= arr[ind2]) ind1++;
        else {
            ll val = arr[ind2];
            ll ind = ind2;
            while(ind != ind1) {
                arr[ind] = arr[ind - 1];
                ind--;
            }
            arr[ind1] = val;
            ind2++;
            ind1++;
        }
    }
}

void mergeSort(ll arr[], ll start, ll end) {
    if(start < end) {
        ll mid = start + (end - start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout); 

    ll size;
    cin >> size;

    ll arr[size];
    for(int i = 0; i < size; i++) cin >> arr[i];

    mergeSort(arr, 0, size - 1);

    cout << "After sorting the array using inplace merge sort algorithm : \n";
    for(int i = 0; i < size; i++) cout << arr[i] << " ";
}