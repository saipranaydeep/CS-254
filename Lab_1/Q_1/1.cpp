#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);    

    ll size;
    cin>>size;

    ll array[size];
    for(int i = 0; i < size; i++) cin >> array[i];

    ll maximum = INT_MIN, second_maximun = INT_MAX;

    for(int i = 0; i < size; i++) {
        if(array[i] >= maximum) {
            second_maximun = maximum;
            maximum = array[i];
        }
        else if(array[i] > second_maximun) {
            second_maximun = array[i];
        }
    }

    cout << maximum + second_maximun << "\n";
}