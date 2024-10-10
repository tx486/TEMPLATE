#include<bits/stdc++.h>
using namespace std;

vector<int> manacher(string& s){
	int n=s.size()*2+1;
	string t(n,'#');
    for(int i=1;i<=n;i+=2) t[i]=s[(i-1)/2];
	vector<int> pi(n);
    for(int i=0,c=0,r=0,len;i<n;i++){
        len=r>i?min(pi[2*c-i],r-i):1;
        while(i+len<n&&i-len>=0&&t[i+len]==t[i-len]) len++;
        if(i+len>r) c=i,r=i+len;
        pi[i]=len-1;
    }
    return pi;
}