// Problem: D - Blue and Red Balls
// Contest: AtCoder - AtCoder Beginner Contest 132
// URL: https://atcoder.jp/contests/abc132/tasks/abc132_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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
vll fact(maxx);
void init(){
    fact[0]=1;
    rep1(i,1,maxx-1){
        fact[i]=(fact[i-1]*i)%MOD;
        fact[i]%=MOD;
    }
}
ll ncr(ll n,ll k){
	if(n<k) return 0;
    if(k==0 || n-k==0) return 1;
    ll res=fact[n];
    //cout<<n<<" "<<fact[n]<<endl;
    ll denom= (modPow(fact[k],MOD-2)+MOD)%MOD*(modPow(fact[n-k],MOD-2)+MOD)%MOD;
    denom%=MOD;
    return (res%MOD*denom%MOD)%MOD;
}
void solve(){
    //cout<<"Case "<<++cs<<": ";
    ll n,k;
    cin>>n>>k;
    ll r=n-k;
    //arrange the N − K red balls into a line.
    rep1(i,1,k){
    	ll bars=i;
    	ll stars=k-bars;
    	ll ans=ncr(r+1,i);
    	//Choose i spots out of the places between 
    	//the red balls or the left or right endpoint
    	//, and place the K blue balls to them;
    	// there are ncr(r+1,i) ways to do so.
    	
    	//For each ways of choosing, decide how many 
    	//balls to distribute to each spots. You have
    	// to put at least 1 ball into each spot, 
    	//so there are ncr(stars+bars-1,bars-1) ways to do so.
    	ans=modMul(ans,ncr(stars+bars-1,bars-1));
    	
    	cout<<ans<<endl;
    }
}
 
signed main()
 
{
    IOS;
    int t;
    t=1;
    init();
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
 
}