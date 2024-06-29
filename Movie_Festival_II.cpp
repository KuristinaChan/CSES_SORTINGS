#include<bits/stdc++.h>
using namespace std;

#define int long long 

void solve(){
    int n, k;
    cin>>n>>k;
    vector<pair<int, int>> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i].second>>v[i].first;
    }
    sort(v.begin(), v.end());
    int ans = 0;
    multiset<int> s;
    for(int i=0; i<k; i++){
        s.insert(0);
    }

    for(int i=0;i<n;i++){
        auto it = s.upper_bound(v[i].second);
        if(it!=s.begin()){
            s.erase(--it);
            s.insert(v[i].first);
            ans++;
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