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
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
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
#define IOS ios::sync_with_stdio(false); cin.tie(0);
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



int gcd(int a, int b) { if (a == 0) return b; return gcd(b % a, a);}
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pair<int,int>> vpii;
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[] = {0, 0, 1, -1};
int dy4[] = {1, -1, 0, 0};
const int maxx=100005;

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

//points template
struct point
{
    double x, y;
    point() {}  //constructor
    point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    double dist(point p) //euclidean distance
    {
        p.x -= x, p.y -= y;
        return sqrt(p.x*p.x + p.y*p.y);
    }
    void input()
    {
        double xx, yy;
        cin >> xx >> yy;
        x = xx;
        y = yy;
    }
    void leftmid(point p, point q) //leftmid point of the distance between these two point p, q
    {
        x = p.x + (q.x-p.x)/3.0;
        y = p.y + (q.y-p.y)/3.0;
    }
    void rightmid(point p, point q)//rightmid point of the distance between these two point p,q;
    {
        x = q.x - (q.x-p.x)/3.0;
        y = q.y - (q.y-p.y)/3.0;
    }
 
} a, b, c, d;




//BST[n] means number of binary search tree can be formed by n distinct number. It is also known as catalan number.
// BST[n]==Cn[i]
//Cn[n]=(2n)!/((n+1)!*n!)=C(2n,n)/n+1
const int maxxn=20000;
ll BST[maxxn];
rep(i,maxxn){
    if (i==0 || i==1){
        BST[i]=1;
    }
    else{
        ll sum =0;ll left, right;
        rep1(k,1,i){
            left = BST[k-1] % MOD;
            right= BST[i-k] % MOD;
            sum =(sum%MOD+ (left * right)%MOD)%MOD;
        }
        BST[i]=sum;
    }
}
BST[0]=0;
//Total number of binary tree possible with n nodes is given by :—
//BT(n) = BST(n)*n!




//using pair as a key in unordered map
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};
unordered_map<pair<int,int>,ll,hash_pair>dp;





// Mo's algo
int k;
ll sum=0;
ll arr[maxx];
ll ans[maxx];
ll cnt[maxx*10];
struct query{
    int index,l,r;
    bool operator < (const query &other) const{
        int block_own=l/k;
        int block_other=other.l/k;
        if(block_own==block_other){
            return r<other.r;
        }
        return block_own<block_other;
    }
}Query[maxx];
void add(int x){
    sum+=arr[x];
}
void rmove(int x){
    sum-=arr[x];
}
int main()
{
    int n;
    cin>>n;
    k=sqrt(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int q;
    cin>>q;
    for(int i=0;i< q;i++){
        int l,r;
        cin>>l>>r;
        l--,r--;
       // Query[i]={i,l,r};
        Query[i].l=l;
        Query[i].r=r;
        Query[i].index=i;
    }
    sort(Query,Query+q);
    int L=0,R=-1;
    for(int i=0;i<q;i++){
        while(R<Query[i].r) add(++R);
        while(R>Query[i].r) rmove(R--);
        while(L<Query[i].l) rmove(L++);
        while(L>Query[i].l) add(--L);
        ans[Query[i].index]=sum;
    }
    for(int i=0;i<q;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}





//bfs path finding from root to vertex v;
ll w[maxx],par[maxx];
vi edg[maxx],vis(maxx);
void bfs(int src){
    queue<int>q;
    q.push(src);
    vis[src]=1;
    par[src]=-1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        forch(it,edg[u]){
            if(!vis[it]){
                vis[it]=1;
                par[it]=u;
                q.push(it);
            }
        }
    }
}

int crwl=par[u];
vi path; //contains the path from root to vertex u in reverse order
path.pb(u);
while(crwl!=-1){
    path.pb(crwl);
    crwl=par[crwl];
}



//dfs my version
vll edg[maxx],a(maxx),out(maxx),lefs(maxx),sum(maxx),vis(maxx),parent(maxx,-1);
int n;
void dfs(int par){
    lefs[par]=out[par]==0;
    vis[par]=1;
    sum[par]+=a[par];
    forch(it,edg[par]){
        if(!vis[it]){
            parent[it]=par;
            dfs(it);
            sum[par]+=sum[it]; //accessing the child nodes
            lefs[par]+=lefs[it];
        }
    }
}

//another clean version
vll edg[maxx],a(maxx),out(maxx),lefs(maxx),sum(maxx),vis(maxx),parent(maxx,-1),ans(maxx);
int n;
void dfs(ll child,ll par){
    lefs[child]=!(edg[child].size());
    //vis[par]=1;
    sum[child]=a[child];
    ans[child]=0;
    forch(it,edg[child]){
        if(it!=par){
            //parent[it]=par;
            dfs(it,child);
            sum[child]+=sum[it];
            lefs[child]+=lefs[it];
            ans[child]=max(ans[child],ans[it]);
        }
    }
    ans[child]=max(ans[child],((sum[child]+lefs[child]-1)/lefs[child]));
}



//base^power%MOD(1000000007) for big power
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


//Bruteforce bitmasking generating all possible subsets of an array length n
void bitmask(int n){
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                
            }
        }
    }
}




//simple Sieve O(n*log(log(n)))
bool isp[maxx];
vi primes;
void sieve(){
    fill(isp+2,isp+maxx,1);
    rep1(i,2,maxx-1){
        if(isp[i]){
            primes.pb(i);
            for(int j=2*i;j<maxx;j+=i){
                isp[j]=0;
            }
        }
    }
}



//NCR in O(T*logn)
vll fact(maxx);
void init(){
    fact[0]=1;
    rep1(i,1,maxx-1){
        fact[i]=(fact[i-1]*i)%MOD;
        fact[i]%=MOD;
    }
}
ll ncr(ll n,ll k){
    if(k==0 || n-k==0) return 1;
    ll res=fact[n];
    //cout<<n<<" "<<fact[n]<<endl;
    ll denom= (Bigmod(fact[k],MOD-2,MOD)+MOD)%MOD*(Bigmod(fact[n-k],MOD-2,MOD)+MOD)%MOD;
    denom%=MOD;
    return (res%MOD*denom%MOD)%MOD;
}


//NCR in T*O(1)
vll fact(maxx),inv(maxx);
void init(){
    fact[0]=1;
    rep1(i,1,maxx-1){
        fact[i]=(fact[i-1]*i)%MOD;
        fact[i]%=MOD;
    }
    inv[maxx-1]=Bigmod(fact[maxx-1],MOD-2,MOD);
    irep(i,maxx-2,0){
        inv[i]=(inv[i+1]*(i+1))%MOD;
    }
}
ll ncr(ll n,ll k){
    if(n<0 or k<0) return 0;
    if(n<k) return 0;
    ll res=fact[n];
    //cout<<n<<" "<<fact[n]<<endl;
    ll denom=(inv[k]*inv[n-k])%MOD;
    return (res%MOD*denom%MOD)%MOD;
}



//Disjoint Set Union
struct DSU{
    vector <int> arr, szz;//arr[i]=j means j is the root of  i; //
    DSU(int n) {
        arr.resize(n + 1); szz.resize(n + 1, 1);
        for(int i = 1; i <= n; i++) {
            arr[i] = i; //initially ith node's root is i itself
        }
    }
    int root(int i) { //this func returns the root of ith node
        while(i!=arr[i]){
            arr[i]=arr[arr[i]];
            i=arr[i];
        }
        return i;
    }
    void merge(int a, int b) { //this func merges two nodes a and b.
        int root_a=root(a),root_b=root(b);
        if(root_a==root_b) return;
        if(szz[root_a]<szz[root_b]){
            arr[root_a]=arr[root_b];
            szz[root_b]+=szz[root_a];
        }
        else{
            arr[root_b]=arr[root_a];
            szz[root_a]+=szz[root_b];
        }
    }
};




void solve(){


}



signed main()

{
    IOS;
    /*#ifndef ONLINE_JUDGE
        freopen ("input.txt","r",stdin);
        freopen ("output.txt","w",stdout);
    #endif*/
    int t;
    cin>>t;
    while(t--){
        solve();
    }

     return 0;

}
///Alhamdulillah



