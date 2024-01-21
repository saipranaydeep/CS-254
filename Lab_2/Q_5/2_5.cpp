#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout); 

    ll size;
    cin>> size;

    ll arr[size];
    for(int i = 0; i < size; i++) cin >> arr[i];

    int first_small = INT_MAX;
    int second_small = INT_MAX;

    for(int i = 0; i < size; i++) {
        if(arr[i] <= first_small) {
            second_small = first_small;
            first_small = arr[i];
        }
        else if(arr[i]< second_small) {
            second_small = arr[i];
        }
    }

    cout << "First smallest element is " << first_small << " and Second smallest element is " << second_small << "\n";

}