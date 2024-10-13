#include <bits/stdc++.h>
using namespace std;



using ll=long long;
static constexpr int MOD=1e9+7;

vector<ll> fac;
ll fp(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=res*a%MOD;
        b>>=1;
        a=a*a%MOD;
    }
    return res;
}
ll inv(ll a){
    return fp(a,MOD-2);
}
ll comb(int a,int b){
    return fac[a]*inv(fac[b])%MOD*inv(fac[a-b])%MOD;
}
ll perm(int a,int b){
    return fac[a]*inv(fac[a-b])%MOD;
}
void build(int n){
    fac.resize(n+1);
    fac[0]=1;
    for(int i=1;i<=n;i++){
        fac[i]=fac[i-1]*i%MOD;
    }
}
