#include <bits/stdc++.h>
#define lli long long int
#define fr(i,n) for(lli i=0;i<(n);i++)
#define frs(i,s,n) for(lli i=s;i<(n);i++)
#define fr1(i,n) for(lli i=1;i<=(n);i++)
#define uint unsigned long long int
#define srt(v) sort(v.begin(),v.end())
#define rsrt(v) sort(v.rbegin(),v.rend())
#define vec(v,n) vector<lli>v(n)
#define vec2(v,n) vector<vector<lli>>v(n)
#define mxe(v)  *max_element(v.begin(),v.end())
#define mne(v)  *min_element(v.begin(),v.end())
using namespace std;
const int MOD=1e9+7;
int main(){
lli T; //number of test cases.
cin >>T;
 vector<string>v(T);
 string ans;
 fr(i,T){
    cin>>v[i];
 }
 int l=1;
fr(i,T){
    string k=v[i];
    fr(m,k.size()){
        if(k[m]+l>122)   k[m]=k[m]+l-26;
       else  k[m]=k[m]+l;
    }
    l=k.size();
    ans+=k;
}
 cout<<ans;
}