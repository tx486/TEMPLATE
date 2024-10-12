#include<bits/stdc++.h>
using namespace std;

class AcMatch{
public:
    vector<vector<int>> tr;
    vector<bool> isEnd;
    vector<int> fail;
    int cnt;
    AcMatch(){}
    AcMatch(int MAXSIZE){
        tr.assign(MAXSIZE+1,vector<int>(26,0));
        isEnd.assign(MAXSIZE+1,false);
        fail.assign(MAXSIZE+1,0);
        cnt=0;
    }
    void assign(int MAXSIZE){
        tr.assign(MAXSIZE+1,vector<int>(26,0));
        isEnd.assign(MAXSIZE+1,false);
        fail.assign(MAXSIZE+1,0);
        cnt=0;
    }
    void insert(string& s){
        int u=0;
        for(auto& c:s){
            if(!tr[u][c-'a']) tr[u][c-'a']=++cnt;
            u=tr[u][c-'a'];
        }
        isEnd[u]=true;
    }
    void setFail(){
        deque<int> q;
        for(int i=0;i<26;i++) if(tr[0][i]) q.push_back(tr[0][i]);
        while(!q.empty()){
            int u=q.front();
            q.pop_front();
            for(int i=0;i<26;i++){
                int v=tr[u][i];
                if(v){
                    fail[v]=tr[fail[u]][i];
                    q.push_back(v);
                }else tr[u][i]=tr[fail[u]][i];
            }
        }
        for(int i=0;i<=cnt;i++) isEnd[i]=isEnd[i]|isEnd[fail[i]];
    }
};
