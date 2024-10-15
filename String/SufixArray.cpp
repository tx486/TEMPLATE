#include<bits/stdc++.h>
using namespace std;
vector<int> get_sa(string& s){
    int n=s.size(),m=127;
    vector<int> sa(n),old_sa(n),X(n<<1),cnt(max(n+1,128));
    for(int i=0;i<n;i++) cnt[X[i]=s[i]]++;
    for(int i=1;i<=m;i++) cnt[i]+=cnt[i-1];
    for(int i=n-1;i>=0;i--) sa[--cnt[X[i]]]=i;
    for(int k=1;k<n;k<<=1){
        //按第二关键字排序
        fill(cnt.begin(),cnt.end(),0);
        copy(sa.begin(),sa.end(),old_sa.begin());
        for(int i=0;i<n;i++) cnt[X[old_sa[i]+k]]++;
        for(int i=1;i<=m;i++) cnt[i]+=cnt[i-1];
        for(int i=n-1;i>=0;i--) sa[--cnt[X[old_sa[i]+k]]]=old_sa[i];
        //按第一关键字排序
        fill(cnt.begin(),cnt.end(),0);
        copy(sa.begin(),sa.end(),old_sa.begin());
        for(int i=0;i<n;i++) cnt[X[old_sa[i]]]++;
        for(int i=1;i<=m;i++) cnt[i]+=cnt[i-1];
        for(int i=n-1;i>=0;i--) sa[--cnt[X[old_sa[i]]]]=old_sa[i];
        //重新建桶
        vector<int> Y=X;
        m=0;
        for(int i=0;i<n;i++){
            if(i>0&&Y[sa[i]]==Y[sa[i-1]]&&Y[sa[i]+k]==Y[sa[i-1]+k]) X[sa[i]]=m;
            else X[sa[i]]=++m;
        }
        if(n==m) break;
    }
    return sa;
}