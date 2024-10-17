#include <bits/stdc++.h>
using namespace std;
 
struct Node{
    int v,i;
    Node(){}
    Node(int v,int i):v(v),i(i){}
    bool operator < (const Node &o) const{
        return v<o.v;
    }
};

struct Node{
    int u,v,w;
    Node(){}
    Node(int u,int v,int w):u(u),v(v),w(w){}
    bool operator < (const Node &o) const{
        return w<o.w;
    }
};
