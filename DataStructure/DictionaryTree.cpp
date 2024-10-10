#include<bits/stdc++.h>
using namespace std;

class DictionaryTree{
    vector<vector<int>> tr;
    vector<int> freq;
    int cnt;
public:
    DictionaryTree(int MAXSIZE){
        tr.assign(MAXSIZE,vector<int>(26,0));
        freq.assign(MAXSIZE,0);
        cnt=0;
    }
    void insert(string& s){
        int u=0;
        for(auto& c:s){
            if(!tr[u][c-'a']) tr[u][c-'a']=++cnt;
            u=tr[u][c-'a'];
        }
        freq[u]++;
    }
    vector<int> countPrefix(string& s){
        int n=s.size();
        vector<int> ans(n);
        for(int i=0,u=0;i<n;i++){
            if(!tr[u][s[i]-'a']) break;
            u=tr[u][s[i]-'a'];
            ans[i]=freq[u];
        }
        return ans;
    }
};