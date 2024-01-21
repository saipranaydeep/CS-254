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

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);    

    ll m, n;
    cin >> m >> n;

    ll arr[m + n];
    for(int i = 0; i < m + n; i++) cin >> arr[i];

    merge(arr, 0, m, m + n);

    for(int i = 0; i < n + m; i++) cout << arr[i] << " ";
}