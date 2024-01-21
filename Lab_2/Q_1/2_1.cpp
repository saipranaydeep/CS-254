#include<bits/stdc++.h>
using namespace std;

using ll = long long;

// Merge function
vector<ll> mergeArrays(vector<ll> a, vector<ll> b) {
    if(a.size() > b.size()) return mergeArrays(b, a);

    vector<ll> Merge(a.size() + b.size());

    ll a_ind = 0, b_ind = 0, m_ind = 0;

    while(a_ind < a.size()) {
        if(a[a_ind] <= b[b_ind]) Merge[m_ind ++] = a[a_ind ++];
        else Merge[m_ind ++] = b[b_ind ++];
    }

    while(b_ind < b.size()) {
        Merge[m_ind ++] = b[b_ind ++];
    }
    
    return Merge;
}

// Union function
vector<ll> unionArray(vector<ll> a, vector<ll> b) {
    if(a.size() > b.size()) return unionArray(b, a);

    vector<ll> Union;

    ll a_ind = 0, b_ind = 0;

    while(a_ind < a.size()) {
        if(a[a_ind] <= b[b_ind]) Union.push_back(a[a_ind ++]);
        else Union.push_back(b[b_ind++]);
        while(a[a_ind] == Union.back()) a_ind++;
        while(b[b_ind] == Union.back()) b_ind++;
    }

    while(b_ind < b.size()) {
        Union.push_back(b[b_ind++]);
        while(b[b_ind] == Union.back()) b_ind++;
    }

    return Union;
}

// Intersection function
vector<ll> intersectionArray(vector<ll> a, vector<ll> b) {
    if(a.size() > b.size()) return intersectionArray(b, a);

    vector<ll> Intersection;

    ll a_ind = 0, b_ind = 0;

    while(a_ind < a.size()) {
        if(a[a_ind] == b[b_ind]){
            if (Intersection.empty() || Intersection.back() != a[a_ind]) Intersection.push_back(a[a_ind]);
            a_ind++;
            b_ind++;
        }
        while(a[a_ind] < b[b_ind]) a_ind++;
        while(a[a_ind] > b[b_ind]) b_ind++;
    }
    
    return Intersection;
}
int main(){
    freopen("input.txt","r",stdin);

    ll size1, size2;
    cin >> size1 >> size2;

    vector<ll> array1(size1), array2(size2);

    for(int i = 0; i < size1; i++) cin >> array1[i];
    for(int i = 0; i < size2; i++) cin >> array2[i];

    vector<ll> Merge, Union, Intersection;

    freopen("MergeOutput.txt","w",stdout);    
    Merge = mergeArrays(array1, array2);
    for(auto x: Merge) cout<<x<<" ";

    freopen("UnionOutput.txt","w",stdout);    
    Union = unionArray(array1, array2);
    for(auto x: Union) cout<<x<<" ";

    freopen("IntersectionOutput.txt","w",stdout);    
    Intersection = intersectionArray(array1, array2);
    for(auto x: Intersection) cout<<x<<" ";
}