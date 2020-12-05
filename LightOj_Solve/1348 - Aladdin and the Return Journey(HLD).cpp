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
const int maxx=30005;

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
int n,q,ht,timer,chainNo, chainInd[maxx], chainHead[maxx], posInBase[maxx],ptr;
ll cost[maxx],baseArray[maxx],BIT[maxx],ans=0;
vi edg[maxx],st(maxx),en(maxx),par(maxx),heavy_child(maxx);
vector<vector<int>>up;
int dfs(int v,int p){
    st[v]=++timer;
    up[v][0]=p;
    int szz=1;
    int mxsz=0;
    for(int i=1;i<=ht;i++){
        up[v][i]=up[up[v][i-1]][i-1];
    }
    for(int u:edg[v])
    {
        if(u!=p){
            par[u]=v;
            int ch_sz=dfs(u,v);
            szz+=ch_sz;
            if(ch_sz>mxsz){
                mxsz=ch_sz;
                heavy_child[v]=u;
            }
        }
    }
    en[v]=++timer;
    return szz;
}
bool is_ancestor(int u,int v){
    return st[u]<=st[v] and en[u]>=en[v];
}
int lca_qu(int u,int v){
        if(is_ancestor(u,v)) return u;
        if(is_ancestor(v,u)) return v;
        for(int i=ht;i>=0;i--){
            if(!is_ancestor(up[u][i],v))
                u=up[u][i];
        }
        return up[u][0];
}
void HLD(int cur){
    if(chainHead[chainNo]==-1) chainHead[chainNo]=cur;
    chainInd[cur]=chainNo;
    posInBase[cur]=ptr;
    baseArray[ptr++]=cost[cur];
    if(heavy_child[cur]!=-1) HLD(heavy_child[cur]);
    forch(it,edg[cur]){
        if(it!=par[cur] and it!=heavy_child[cur]){
            chainNo++;
            HLD(it);
        }
    }

}
void update(int p,ll val){
    while(p<=ptr){
        BIT[p]+=val;
        p+=(p&-p);
    }
}
ll query(int p){
    ll res=0;
    while(p>0){
        res+=BIT[p];
        p-=(p&-p);
    }
    return res;
}
void treeQ(int u,int v){
    int uchain,vchain=chainInd[v];
    while(1){
        uchain=chainInd[u];
        //debug(uchain,vchain);
        if(uchain==vchain){
            //debug(pos[u],pos[v]);
            ans+=(query(posInBase[u]+1)-query(posInBase[v]));
            break;
        }
        ans+=(query(posInBase[u]+1)-query(posInBase[chainHead[uchain]]));
        //debug(uchain,head[uchain],par[u]);
        u=chainHead[uchain];
        //debug(uchain,head[uchain],par[u]);
        u=par[u];
    }
}

void init(){
    chainNo=0;
    ptr=0;
    fill(baseArray,baseArray+(n+5),0);
    fill(chainInd,chainInd+(n+5),-1);
    fill(chainHead,chainHead+(n+5),-1);
    fill(posInBase,posInBase+(n+5),-1);
    rep(i,n+5) edg[i].clear();
    fill(st.begin(),st.begin()+(n+5),0);
    fill(en.begin(),en.begin()+(n+5),0);
    timer=0;
    ht=ceil(log2(n));
    up.assign(n, vector<int>(ht + 1));
    fill(par.begin(),par.begin()+(n+5),0);
    fill(heavy_child.begin(),heavy_child.begin()+(n+5),-1);
    fill(BIT,BIT+(n+5),0);

}

void solve(){
    scanf("%d",&n);
    init();
    rep(i,n) scanf("%d",&cost[i]);
    rep(i,n-1){
        int u,v;
        scanf("%d%d",&u,&v);
        edg[u].pb(v);
        edg[v].pb(u);
    }
    dfs(0,0);
    HLD(0);
    rep(i,ptr+1){
        update(i+1,baseArray[i]);
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==0){
            int u,v;
            scanf("%d%d",&u,&v);
            int lc=lca_qu(u,v);
            treeQ(u,lc);
            treeQ(v,lc);
            ans-=cost[lc];
            printf("%lld\n",ans);
            ans=0;

        }
        else{
            int u;
            ll val;
            scanf("%d%lld",&u,&val);
            update(posInBase[u]+1,-cost[u]);
            cost[u]=val;
            update(posInBase[u]+1,cost[u]);
        }
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
