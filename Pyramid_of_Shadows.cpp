#include <bits/stdc++.h>
#define lli long long int
#define fr(i,n) for(lli i=0;i<(n);i++)
#define frs(i,s,n) for(lli i=s;i<=(n);i++)
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
vec2(v,T+1);
fr1(i,T){
    lli l=i;
    fr1(k,l){
        int x;cin>>x;
        v[i].push_back(x);
    }
}
for(lli i=T-1;i>=1;i--){
  for(lli k=0;k<i;k++){
    v[i][k]+=max(v[i+1][k],v[i+1][k+1]);
  }
}
cout<<v[1][0]<<endl;
 
}