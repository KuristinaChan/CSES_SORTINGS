#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define si set<int>
#define sll set<long long>
#define sc set<char>
#define vc vector<char>

#define rep(i,a,b) for(int i=a;i<b;i++)
#define repb(i,a,b) for(int i=a;i<=b;i++)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define ff first
#define ss second
#define ln endl

#define mp make_pair
#define pqueue priority_queue
#define pb push_back

ll gcd(const ll a, const ll b){return(b==0?a:gcd(b,a%b));}
ll lcm(const ll a, const ll b){return a/gcd(a,b)*b;}
ll binpow(ll a,ll n){ll ans=1;for(;n;n/=2,a*=a)if(n&1)ans*=a;return ans;}
ll binpow(ll a,ll n,const ll&mod){ll ans=1;for(;n;n/=2,a=a*a%mod)if(n&1)ans=ans*a%mod;return ans;}
ll cdiv(const ll&a,const ll&b){return(a/b+((a^b)>0 && a%b));}
ll fdiv(const ll&a,const ll&b){return a/b-((a^b)<0 && a%b);}
const ll mod = 1000000007;
// const ll mod = 998244353;
multiset<ll> up;
multiset<ll> down;
int k;
void ins(ll x){
    if(x>*down.rbegin()){
        up.insert(x);
        if(up.size()>(k/2)){
            down.insert(*up.begin());
            up.erase(up.find(*up.begin()));
        }
    }else{
        down.insert(x);
        if(down.size()>((k+1)/2)){
            up.insert(*down.rbegin());
            down.erase(down.find(*down.rbegin()));
        }
    }
}

void er(ll x){
    if(up.find(x)!=up.end()){
        up.erase(up.find(x));
    }else{
        down.erase(down.find(x));
    }
    if(down.empty()){
        down.insert(*up.begin());
        up.erase(up.find(*up.begin()));
    }
}

void solve(){
    ll n,m;
    cin>>n>>m;
    vll a(n);
    k = m;
    rep(i,0,n)cin>>a[i];
    if(k==1){
        rep(i,0,n){
            cout<<a[i]<<" ";
        }
        return;
    }
    down.insert(a[0]);
    rep(i,1,k){
        ins(a[i]);
    }
    cout<<*down.rbegin()<<" ";
    rep(i,k,n){
        er(a[i-k]);
        ins(a[i]);
        cout<<*down.rbegin()<<" ";
    }
    cout<<ln;
    return;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}