#include <bits/stdc++.h>
using namespace std;

class SegTree{// 区间更新,加减，维护最大值和累加和
using ll= long long;
public:
    void init(vector<int>& a){
        n=a.size();
        mx.resize(n<<2);
        sum.resize(n<<2);
        increase.resize(n<<2);
        change.resize(n<<2);
        updateTag.resize(n<<2);
        build(1,n,1,a);
    }
    void add(int l,int r,int v){
        if(l>r||r==0) return;
        add(l,r,v,1,n,1);
    }
    void update(int l,int r,int v){
        if(l>r||r==0) return;
        update(l,r,v,1,n,1);
    }
    ll querySum(int l,int r){
        if(l>r||r==0) return 0;
        return querySum(l,r,1,n,1);
    }
    int queryMax(int l,int r){
        if(l>r||r==0) return 0;
        return queryMax(l,r,1,n,1);
    }
private:
    int n;
    vector<int> mx,change,increase;
    vector<ll> sum;
    vector<bool> updateTag;
    void up(int i){
        mx[i]=max(mx[i<<1],mx[i<<1|1]);
        sum[i]=sum[i<<1]+sum[i<<1|1];
    }
    void build(int l,int r,int i,vector<int>& a){
        if(l==r) sum[i]=mx[i]=a[l-1];
        else{
            int mid=(l+r)>>1;
            build(l,mid,i<<1,a);
            build(mid+1,r,i<<1|1,a);
            up(i);
        }
        updateTag[i]=false;
        change[i]=0;
        increase[i]=0;
    }
    void down(int l,int r,int i){
        if(updateTag[i]){
            int mid=(l+r)>>1;
            lazy_update(l,mid,change[i],i<<1);
            lazy_update(mid+1,r,change[i],i<<1|1);
            updateTag[i]=false;
        }
        if(increase[i]){
            int mid=(l+r)>>1;
            lazy_add(l,mid,increase[i],i<<1);
            lazy_add(mid+1,r,increase[i],i<<1|1);
            increase[i]=0;
        }
    }
    void lazy_add(int l,int r,int v,int i){
        sum[i]+=1ll*(r-l+1)*v;
        mx[i]+=v;
        increase[i]+=v;
    }
    void lazy_update(int l,int r,int v,int i){
        mx[i]=v;
        sum[i]=v*(r-l+1);
        change[i]=v;
        updateTag[i]=true;
        increase[i]=0;
    }
    void update(int L,int R,int v,int l,int r,int i){
        if(L<=l&&r<=R) lazy_update(l,r,v,i);
        else{
            down(l,r,i);
            int mid=(l+r)>>1;
            if(L<=mid) update(L,R,v,l,mid,i<<1);
            if(R>mid) update(L,R,v,mid+1,r,i<<1|1);
            up(i);
        }
    }
    void add(int L,int R,int v,int l,int r,int i){
        if(L<=l&&r<=R) lazy_add(l,r,v,i);
        else{
            down(l,r,i);
            int mid=(l+r)>>1;
            if(L<=mid) add(L,R,v,l,mid,i<<1);
            if(R>mid) add(L,R,v,mid+1,r,i<<1|1);
            up(i);
        }
    }
    ll querySum(int L,int R,int l,int r,int i){
        if(L<=l&&r<=R) return sum[i];
        else{
            down(l,r,i);
            int mid=(l+r)>>1;
            ll res=0;
            if(L<=mid) res+=querySum(L,R,l,mid,i<<1);
            if(R>mid)  res+=querySum(L,R,mid+1,r,i<<1|1);
            return res;
        }
    }
    int queryMax(int L,int R,int l,int r,int i){
        if(L<=l&&R>=r) return mx[i];
        else{
            down(l,r,i);
            int mid=(l+r)>>1;
            int res=0;
            if(L<=mid) res=max(res,queryMax(L,R,l,mid,i<<1));
            if(R>mid) res=max(res,queryMax(L,R,mid+1,r,i<<1|1));
            return res;
        }
    }
};