#include <bits/stdc++.h>
using namespace std;

struct UnionSet{
    vector<int> f,sz;
    UnionSet(int n){
        f.assign(n+1,0);
        for(int i=0;i<=n;i++) f[i]=i;
        sz.assign(n+1,1);
    }
    int find(int x){
        if(f[x]!=x) f[x]=find(f[x]);
        return f[x];
    }
    int size(int x){
        return sz[find(x)];
    }
    void merge(int a,int b){
        int fa=find(a),fb=find(b);
        if(fa!=fb){
            f[fa]=fb;
            sz[fb]+=sz[fa];
        }
    }   
};
