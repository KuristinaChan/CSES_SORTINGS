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
        v.push_back({a,1});
        v.push_back({b,-1});
    }

    sort(v.begin(),v.end());

    int ans=0;

    int count=0;

    for(int i=0;i<v.size();i++){
        count+=v[i].second;
        ans=max(ans,count);
    }

    cout<<ans<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}