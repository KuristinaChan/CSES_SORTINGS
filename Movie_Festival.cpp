#include<bits/stdc++.h>
using namespace std;

#define int long long 

void solve(){
    int n;

    cin>>n;

    vector<pair<int,int>> v;

    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({b,a});
    }

    sort(v.begin(),v.end());

    int ans=0;

    int end=0;


    for(int i=0;i<n;i++){
        if(v[i].second>=end){
            ans++;
            end=v[i].first;
        }
    }

    cout<<ans<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}