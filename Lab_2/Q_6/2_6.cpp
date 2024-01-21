#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int Partition(vector<ll> arr, ll l, ll r){
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

void median(vector<ll> arr, ll l, ll r, ll k, ll &a, ll &b) {
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

int find_median(vector<ll> a){
    ll md1 = -1, md2 = -1, n = a.size();
    median(a, 0, n-1, n/2, md1, md2);
    return md2;
}

int medianPosition(ll arr[], int l, int r){
    if(l == r) return l;
    vector<ll> b;
    for(int i=l; i <= r; i++)
        b.push_back(arr[i]);
    int mdv = find_median(b);
    for(int i=l; i<=r; i++)
        if(arr[i] == mdv)
            return i;
}

int partition(ll arr[], ll l, ll r){
    int p = medianPosition(arr, l, r);
    swap(arr[p], arr[r]);
    int pivot = arr[r];
    int low = l;
    for(int i=l; i<r; i++){
        if(arr[i] < pivot)
            swap(arr[i], arr[low++]);
    }
    swap(arr[low], arr[r]);
    return low;
}

void quickSort(ll arr[], ll low, ll high){
    if(low<high){ 
        int ind = partition(arr, low, high); 
        quickSort(arr, low, ind - 1);
        quickSort(arr, ind + 1, high);
    }
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout); 
    
    ll size;
    cin >> size;

    ll arr[size];
    for(int i = 0; i < size; i++) cin >> arr[i];

    quickSort(arr, 0, size - 1);

    for(int i = 0; i < size; i++) cout << arr[i] << " ";
}