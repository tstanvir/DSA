// Problem: Sardar and GCD
// Contest: CodeChef - Code Senso Division 2 (Rated)
// URL: https://www.codechef.com/CSNS21B/problems/DLTNODE
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

//find_by_order(k): It returns to an iterator to the kth element 
//(counting from zero) in the set in O(logn) time.
//To find the first element k must be zero.

// order_of_key(k) : It returns to the number of items that 
// are strictly smaller than our item k in O(logn) time.

//using namespace __gnu_pbds;
using namespace std;

//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
#define di deque<int>
#define dll deque<ll>
#define pf push_front
#define ppf pop_front
#define preci cout<<fixed<<setprecision(9);
#define omst tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>
#define ost tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>


typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pair<int,int>> vpii;
typedef vector<pair<ll,ll>> vpll;

 
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

 
 


//typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> omst;
//typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ost; 
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[] = {0, 0, 1, -1};
int dy4[] = {1, -1, 0, 0};
const int maxx=100005;
const long long MOD = 1000000007;
const double rad=(acos(-1)/180.00);
const int INF    = 0x3f3f3f3f;
const ll LL_INF  = 0x3f3f3f3f3f3f3f3f;
const ll negInf=-1e18;
const ll posInf=1e18;
#define EPS  0.000000001

 
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
bool get_bit(int mask,int pos) {return mask&(1<<pos);}
bool sortinrev(const pair<int,int> &a,const pair<int,int> &b)
{
    return a.first>b.first;
}
int cs=0;
vi edg[maxx],st(maxx),en(maxx),A(maxx),baseA(2*maxx),par(maxx);
int segT[8*maxx];
int timer=0;
void dfs(int v,int p){
	assert(v>=1 and v<maxx);
    st[v]=++timer;
    assert(timer<2*maxx);
    par[v]=p;
    baseA[timer]=A[v];
    for(int u:edg[v])
    {
        if(u!=p){
        	dfs(u,v);
        }
    }
    
    en[v]=++timer;
    assert(timer<2*maxx);
    baseA[timer]=A[v];
}

//range gcd query
//gcd
void build(int treeL,int treeR,int pos){
	assert(pos<8*maxx);
	if(treeL==treeR){
		segT[pos]=baseA[treeL];
		return;
	}
	int mid=treeL+(treeR-treeL)/2;
	build(treeL,mid,2*pos);
    build(mid+1,treeR,2*pos+1);
    segT[pos]=gcd(segT[2*pos],segT[2*pos+1]);
}
int query(int treeL,int treeR,int l,int r,int pos){
	assert(pos<8*maxx);
	if(treeR<l or treeL>r) return 0;
	if(l<=treeL and treeR<=r){
        return segT[pos];
    }
    int mid=treeL+(treeR-treeL)/2;
    return gcd(query(treeL,mid,l,r,2*pos),query(mid+1,treeR,l,r,2*pos+1));
}
void init(int n){
	rep(i,n+1) edg[i].clear(),st[i]=0,en[i]=0;
	rep(i,timer+1) baseA[i]=0;
	SET(segT);
	timer=0;
	
}
void solve(){
    //cout<<"Case "<<++cs<<": ";
    int n;
    cin>>n;
    init(n);
    rep(i,n-1){
    	int u,v;
    	cin>>u>>v;
    	edg[u].pb(v);
    	edg[v].pb(u);
    }
    
    rep1(i,1,n) cin>>A[i];
    dfs(1,0);
    // rep1(i,1,timer){
    	// debug(i);
    	// debug(baseA[i]);
    // }
    // rep1(i,1,n){
    	// debug(st[i]);
    	// debug(en[i]);
    // }
    build(1,timer,1);
    ll ans=1;
    rep1(i,1,n){
    	ll val=0; 
    	forch(u,edg[i]){
    		int l=st[u],r=en[u];
    		// if(i==3) {
    			// debug(val);
    			// debug(u);
    		// }
    		if(u==par[i])
    		{
    			// l=1,r=st[i]-1;
    			val+=gcd(query(1,timer,1,st[i]-1,1),query(1,timer,en[i]+1,timer,1));
    			// l=en[u]+1,r=timer;
    			// val+=query(1,timer,l,r,1);
    			continue;
    		}
    		
    		//debug(i);
    		//debug(u);
    		val+=query(1,timer,l,r,1);
    		
    	}
    	ans=max(ans,val);
    }
    cout<<ans<<endl;
}
 
signed main()
 
{
    IOS;
    int t;
    t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
 
}