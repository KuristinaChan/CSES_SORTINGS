#include<bits/stdc++.h>
#include<cassert>
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
unordered_map<ll,int> cnt;
void solve(){
    int n, k;
    cin>>n>>k;
    vll a(n);
    rep(i,0,n)cin>>a[i];
    int r = 0;
    int fl = -1;int fr = -1;
    int cur=0;
    rep(i,0,n){
        
        while(r<n){
            if(++cnt[a[r]]==1)cur++;
            if(cur>k){
                if(--cnt[a[r]]==0)cur--;
                break;
            }
            r++;
        }
        if((fr-fl)<(r-i)){fr=r;fl=i;}
        if(--cnt[a[i]]==0)cur--;
    }
    cout<<fl+1<<" "<<fr<<ln;
}
int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;}