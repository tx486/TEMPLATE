#include <bits/stdc++.h>
using namespace std;
 
struct Node{
    int v,i;
    Node(){}
    Node(int v,int i):v(v),i(i){}
    bool operator <(Node& other){
        return v<other.v;
    }
    bool operator <(const Node& other){
        return v<other.v;
    }
};
