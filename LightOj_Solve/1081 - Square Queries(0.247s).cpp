/// Bismillahir Rahmanir Rahim
//Author: Tanvir Hussain
//ICE,NSTU
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
const long long MOD = 1000000007;
const double rad=(acos(-1)/180.00);
#define SET(x) memset(x, 0, sizeof(x))
#define SET2d(x,m,n) memset(x, 0, sizeof(x[0][0]) * m * n)
#define SETBOOL(x) memset(x,false,sizeof(x))
#define CLR(x) memset(x, -1, sizeof(x))
#define CLR2d(x,m,n) memset(x, -1, sizeof(x[0][0]) * m * n)
#define mp make_pair
#define PII pair<int, int>
#define pf printf
#define sf scanf
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define np std::string::npos
#define highest(x) numeric_limits<x>::max()
#define lowest(x) numeric_limits<x>::min()
#define Inf INFINITY
#define minv(v) *min_element(v.begin(),v.end())
#define maxv(v) *max_element(v.begin(),v.end())
#define cases(cs,t) for(int cs=1;cs<=t;cs++)
#define PI acos(-1)
#define no1 __builtin_popcount
#define BOUNDARY(i, j) ((i >= 0 && i < row) && (j >= 0 && j < column))
#define uniq(vec) vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())))
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define sz(a) int(a.size())
#define ff first
#define ss second
#define endl "\n"
#define forch(it,s) for(auto it:s)
#define each(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define rep(i,a) for(int i=0; i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define irep(i,b,a) for(int i=(b);i>=(a);--i)
#define bits(n) __builtin_popcount(n)
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


int gcd(int a, int b) { if (a == 0) return b; return gcd(b % a, a);}
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pair<int,int>> vpii;
typedef vector<pair<ll,ll>> vpll;
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[] = {0, 0, 1, -1};
int dy4[] = {1, -1, 0, 0};
const int maxx=505;;
const int maxln=(int)log2(maxx)+5;

inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }  /// When MOD is prime.
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }




//this fuction sorts vector pair according to first element in descending order.
bool sortinrev(const pair<int,int> &a,const pair<int,int> &b)
{
    return a.first>b.first;
}

template<typename T>inline T Bigmod(T base, T power, T MOD){
    T ret=1;
    while(power)
    {
        if(power & 1)ret=(ret*base)%MOD;
        base=(base*base)%MOD;
        power>>=1;
    }
    return ret;
}
double sq(double x) {return x*x;}
ll po(ll b,ll p){
    ll res=1;
    while(p){
        res*=b;
        p--;
    }
    return res;
}
ll lg2(ll x){
    ll res=0;
    while(x>1){
        res++;
        x/=2ll;
    }
    return res;
}

#define XOX
#ifdef XOX
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
int n,sparsT[maxx][maxx][maxln],q;
void prepo(){
    //debug("chk");
    //debug(n);
    int col=(int)log2(n)+1;
    //debug(col);
    rep1(k,1,col){
        for(int i=0;i+po(2,k)-1<n;i++){
            for(int j=0;j+po(2,k)-1<n;j++){
                int x=i+po(2,k-1),y=j+po(2,k-1);
                //debug(x,y);
                sparsT[i][j][k]=max(sparsT[i][j][k-1],sparsT[i][y][k-1]);
                sparsT[i][j][k]=max(sparsT[i][j][k],max(sparsT[x][j][k-1],sparsT[x][y][k-1]));
            }
        }
    }
}
int minQ(int x1,int y1,int x2,int y2){
    int Lx=x2-x1+1,Ly=y2-y1+1;
    int kx=(int)log2(Lx),ky=int(log2(Ly));
    int slidex=x1+(Lx-po(2,kx)),slidey=y1+(Ly-po(2,ky));
    int m1=max(sparsT[x1][y1][ky],sparsT[x1][slidey][ky]);
    int m2=max(sparsT[slidex][y1][kx],sparsT[slidex][slidey][kx]);
    return max(m1,m2);

}
void solve(){
    n,q;
    scanf("%d%d",&n,&q);
    rep(i,n){
        rep(j,n){
            scanf("%d",&sparsT[i][j][0]);
        }
    }
    //debug(n);
    prepo();
    rep(k,q){
        int i,j,s;
        scanf("%d%d%d",&i,&j,&s);
        int i1=i+s-1,j1=j+s-1;
        i--,j--;
        i1--,j1--;
        printf("%d\n",minQ(i,j,i1,j1));
    }

}

signed main()

{
    /*#ifndef ONLINE_JUDGE
        freopen ("input.txt","r",stdin);
        freopen ("output.txt","w",stdout);
    #endif*/
    int t;
    scanf("%d",&t);
    int cs=0;
    while(t--){
        printf("Case %d:\n",++cs);
        solve();
    }

     return 0;

}
///Alhamdulillah
