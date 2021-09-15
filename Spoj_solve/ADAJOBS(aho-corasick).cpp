//Aho-corasick: https://returnzerooo.wordpress.com/2017/09/28/আহো-কোরাসিক/


// Problem: Ada and Jobs
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/ADAJOBS/
// Memory Limit: 1536 MB
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
const int maxx=2000005;
const int sqMaxx=sqrt(maxx);
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
vi finishedHere;
struct trie{
	int tree[maxx][26];
	int sz=1;
	
	int freq[maxx];
	int falseNode[maxx];
	void init(){
		SET(tree);
		sz=1;
		//SET(finishedHere);
		SET(freq);
		SET(falseNode);
	}
	int insert(string s,int id){
		//building the trie tree.
		int cur=0;
		int len=sz(s);
		rep(i,len){
			int c=s[i]-'a';
			if(!tree[cur][c]) tree[cur][c]=sz++;
			cur=tree[cur][c];
		}
		//storing minimum query id from all of that query
		// which are finished in this cur node.
		finishedHere[cur]=min(finishedHere[cur],id);
		return cur;
	}
	void build_falseNode(){
		//falseNode serves much like prefix
    	//function in KMP, to reduce time 
    	//complexity by skipping some character matching
		queue<int>q;
		rep(i,26){
			if(tree[0][i]){
				q.push(tree[0][i]);
			}
		}
		while(!q.empty()){
			int u=q.front();
			//pushing down the minimum query id,which will reduce time complexity
			finishedHere[u]=min(finishedHere[u],finishedHere[falseNode[u]]);
			q.pop();
			rep(c,26){
				int cur=tree[u][c];
				if(!cur) continue;
				q.push(cur);
				int fN=falseNode[u];
				while(fN and !tree[fN][c]){
					fN=falseNode[fN];
				}
				falseNode[cur]=tree[fN][c];
			}
		}
	}
	
	bool search(string s,int id){
		//stores the frequency of the pattern that occurred
		// in the string s.
		int fN=0;
		int len=sz(s);
		rep(i,len){
			int c=s[i]-'a';
			while(fN and !tree[fN][c]){
				fN=falseNode[fN];
			}
			fN=tree[fN][c];
			int temp=fN;
			if(finishedHere[temp]<=id) return 1;
		}
		return 0;
	}
	
}trieDs;
void solve(){
	//trieDs.init();
    //cout<<"Case "<<++cs<<": ";
    finishedHere.resize(maxx,INF);
    int q;
    cin>>q;
    int id=0;
    deque<pair<string,int>>dq;
    while(q--){
    	int op;
    	cin>>op;
    	if(op){
    		string s;
    		cin>>s;
    		dq.pb({s,id});
    	}
    	else{
    		string p;
    		cin>>p;
    		trieDs.insert(p,id);
    	}
    	id++;
    }
    trieDs.build_falseNode();
    while(!dq.empty()){
    	pair<string,int>p=dq.front();
    	dq.pop_front();
    	if(trieDs.search(p.ff,p.ss)){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
    }
}
 
signed main()
 
{
    IOS;
    int t;
    t=1;
   // cin>>t;
    while(t--){
        solve();
    }
    return 0;
 
}