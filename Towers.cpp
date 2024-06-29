#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans = 0;
    multiset<int> s;
    for(int i=0;i<n;i++){
        auto it = s.upper_bound(a[i]);
        if(it!=s.end()){
            s.erase(it);
        }
        s.insert(a[i]);
        ans = max(ans,(int)s.size());
    }
    cout<<ans<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}