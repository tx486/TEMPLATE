#include <bits/stdc++.h>
using namespace std;
class Combination{
using ll=long long;
private:
    static constexpr int MOD=1e9+7;
    static ll fp(ll a,ll b){
        ll res=1;
        while(b){
            if(b&1) res=res*a%MOD;
            b>>=1;
            a=a*a%MOD;
        }
        return res;
    };
    static ll inv(ll a){
        return fp(a,MOD-2);
    }
    vector<ll> fac;
public:
    Combination(int n){
        fac.resize(n+1);
        fac[0]=1;
        for(int i=1;i<=n;i++){
            fac[i]=fac[i-1]*i%MOD;
        }
    }
    ll comb(int a,int b){
        return fac[a]*inv(fac[b])%MOD*inv(fac[a-b])%MOD;
    }
};
