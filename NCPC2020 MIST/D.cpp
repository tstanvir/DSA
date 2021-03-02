#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define IOS ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define SET(x) memset(x, 0, sizeof(x))
#define CLR(x) memset(x, -1, sizeof(x))
#define mp make_pair
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define ppb pop_back
#define highest(x) numeric_limits<x>::max()
#define lowest(x) numeric_limits<x>::min()
#define minv(v) *min_element(v.begin(),v.end())
#define maxv(v) *max_element(v.begin(),v.end())
#define PI acos(-1)
#define border(i, j , row, column) ((i >= 0 && i < row) && (j >= 0 && j < column))
#define uniq(vec) vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())))
#define sz(a) int(a.size())
#define ff first
#define ss second
#define endl "\n"
#define forch(it,s) for(auto it:s)
#define rep(i,a) for(int i=0; i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define irep(i,b,a) for(int i=(b);i>=(a);--i)
#define no1(n) __builtin_popcount(n)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int> >
#define preci cout<<fixed<<setprecision(9);
 
 
vector<string> vec_splitter(string s) {
    s += ',';
    vector<string> res;
    while(!s.empty()) {
        res.push_back(s.substr(0, s.find(',')));
        s = s.substr(s.find(',') + 1);
    }
    return res;
}
 void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx,
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
    if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
    stringstream ss; ss << H;
    cerr << args[idx] << " = " << ss.str();
    debug_out(args, idx + 1, LINE_NUM, T...);
}

#define XOX
#ifdef XOX
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
 

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pair<int,int>> vpii;
typedef vector<pair<ll,ll>> vpll;
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> omst;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ost; 
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[] = {0, 0, 1, -1};
int dy4[] = {1, -1, 0, 0};
const int maxx=400005;
const long long MOD = 1000000007;
const double rad=(acos(-1)/180.00);
const int INF    = 0x3f3f3f3f;
const ll LL_INF  = 0x3f3f3f3f3f3f3f3f;

 
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }  /// When MOD is prime.
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }
ll gcd(ll a, ll b) { if (a == 0) return b; return gcd(b % a, a);}
ll lcm(ll a, ll b) {return (a*b)/gcd(a,b);}
double sq(double x) {return x*x;} 
ll po(ll b,ll p){ ll res=1; while(p){ res*=b; p--;} return res;}
ll lg2(ll x){ ll res=0; while(x>1){ res++; x/=2ll;} return res;}
bool sortinrev(const pair<int,int> &a,const pair<int,int> &b)
{
    return a.first>b.first;
}
/*struct tN{
    int t,n;
    bool operator < (const tN &other) const{
        
        if(t==block_other){
            return r<other.r;
        }
        return block_own<block_other;
    }
};*/
vi edg[maxx],vis(maxx),st(maxx),en(maxx),sbtreeSz(maxx);
int n,tim;
void init(){
    rep(i,n+1) edg[i].clear();
    fill(ALL(vis),0);
    tim=0;
    fill(ALL(st),0);
    fill(ALL(en),0);
    fill(ALL(sbtreeSz),0);
}
void dfs(int par){
    vis[par]=1;
    st[par]=++tim;
    sbtreeSz[par]++;
    forch(it,edg[par]){
        if(!vis[it]){
            dfs(it);
            sbtreeSz[par]+=sbtreeSz[it];
        }
    }
    en[par]=++tim;
}
void solve(){
    init();
    cin>>n;
    rep(i,n-1){
        int u,v;
        cin>>u>>v;
        edg[u].pb(v);
        edg[v].pb(u);
    }
    rep1(i,1,n){
        sort(ALL(edg[i]));
    }
    dfs(1);
    set<pair<int,int>> unfilled;
    rep1(i,1,n){
        unfilled.insert({en[i],i});
    }
    /*sort(ALL(entimNode));
    deque<int>dq;
    vi inThatPos(n+1);
    rep(i,n){
        dq.pb(entimNode[i].ss);
        inThatPos[entimNode[i].ss]=i;
    }
    /*forch(it,dq){
        cout<<it<<" ";
    }
    rep1(i,1,n) {
        debug(i,sbtreeSz[i]);
    }
    cout<<endl;*/
    int q;
    cin>>q;
    vi unemployed(n+1);
    rep(i,q){
        int t;
        cin>>t;
        if(t==1){
            int x,val;
            cin>>x>>val;
            while(val--){
                auto it=unfilled.lower_bound({st[x],0});
                if(it==unfilled.end() or (*it).ff>en[x]) break;
                unemployed[(*it).ss]=1;
                unfilled.erase(it);
            }
            
        }
        else{
            int x;
            cin>>x;
            if(unemployed[x]==0){
                cout<<0<<endl;
            }
            else {
                cout<<1<<endl;
            }
        }
    }
}
 
signed main()
 
{
    IOS;
    int t;
    t=1;
    cin>>t;
    int cs=0;
    while(t--){
        cout<<"Case "<<++cs<<":"<<endl;
        solve();
    }
    return 0;
 
}