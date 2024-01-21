#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int Partition(ll arr[], ll l, ll r){
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

void median(ll arr[], ll l, ll r, ll k, ll &a, ll &b) {
    if(l <= r){
        ll n = r - l + 1;
        ll pivot = rand() % n;
        swap(arr[l + pivot], arr[r]);
        ll ind = Partition(arr, l, r);

        if(ind == k){
            b = arr[ind];
            if(a != -1) {
                return;
            }
        }
        else if(ind == k - 1){
            a = arr[ind];
            if(b != -1){
                return;
            }
        }

        if(ind >= k){
            return median(arr, l, ind - 1, k, a, b);
        }
        else{
            return median(arr, ind + 1, r, k, a, b);
        }
    }
    return;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout); 
    ll size;
    cin >> size;

    ll a = (size & 1)? -1 : 0, b = -1; 
    // if size is even, there is no need to find a. So when b is found we will return b then. But when size is odd, we have to find both a and b.

    ll arr[size];
    for(int i = 0; i < size; i++) cin >> arr[i];

    median(arr, 0, size - 1, size/2, a, b);

    
    if(size&1) cout << "The median of the array is " << b << "\n";
    else cout << "The medians of the array are " << a << " and " << b << "\n";
}