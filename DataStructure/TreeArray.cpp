#include <bits/stdc++.h>
using namespace std;

struct TreeArray{
using ll=long long;
    int n;
    vector<ll> tr;
    TreeArray(){}
    TreeArray(int n){
        this->n = n;
        tr.assign(n+1, 0);
    }
    void add(int i,ll x){
        for(; i <= n; i += i&-i)
            tr[i] += x;
    }
    void range_add(int l,int r,ll x){
        add(l,x);
        add(r+1,-x);
    }
    ll sum(int i){
        ll res = 0;
        for(; i; i -= i&-i)
            res += tr[i];
        return res;
    }
    ll range_sum(int l,int r){
        return sum(r) - sum(l-1);
    }
};
