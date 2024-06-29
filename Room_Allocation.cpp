#include<bits/stdc++.h>
using namespace std;

#define int long long 

void solve(){
    int n;
    cin>>n;
    vector<pair<pair<int,int>,int>> v(n);
    for(int i=0;i<n;i++){
       cin>>v[i].first.first>>v[i].first.second;
        v[i].second = i;
    }
    sort(v.begin(),v.end());
    vector<int> ans(n);
    int rooms = 0;

    priority_queue<pair<int,int>> pq;

    for(int i=0;i<n;i++){
        if(pq.empty()){
            rooms++;
            pq.push({-v[i].first.second,rooms});
            ans[v[i].second] = rooms;
        }else{
            auto x = pq.top();
            if(-x.first<v[i].first.first){
                pq.pop();
                pq.push({-v[i].first.second,x.second});
                ans[v[i].second] = x.second;
            }else{
                rooms++;
                pq.push({-v[i].first.second,rooms});
                ans[v[i].second] = rooms;
            }
        }    
    }

    cout<<rooms<<endl;
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}