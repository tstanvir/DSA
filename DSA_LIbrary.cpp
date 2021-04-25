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
//inclusion-exclusion
//how many numbers in 1 to m are divisable by a certain set of numbers a
ll cnt(di a, ll m)
{
    int n=sz(a);
    ll odd = 0, even = 0;
    ll counter, i, j, p = 1;
    ll pow_set_size = (1ll << n);
    for (counter = 1; counter < pow_set_size; counter++) {
        p = 1;
        for (j = 0; j < n; j++) {
            if (counter & (1ll << j)) {
                p *= a[j];
            }
        }
        if (__builtin_popcount(counter) & 1)
            odd += (m / p);
        else
            even += (m / p);
    }
    return odd - even;
}



//lexvalue("a") = 1, lexvalue("b") = 2, …, lexvalue("z") = 26,
//lexvalue("aa") = 27, lexvalue("ab") = 28, …, lexvalue("az") = 52,
//lexvalue("ba") = 53, lexvalue("bb") = 54, …, lexvalue("bz") = 78, …, 
//lexvalue("za") = 677,lexvalue("zb") = 678, …, lexvalue("zz") = 702, 
//lexvalue("aaa") = 703, lexvalue("aab") = 704, …, lexvalue("aaz") = 728, …, 
//lexvalue("zzz") =18278, …
//lexicogrpahical value
//Number representation in base 26
ll lexV(string s){
    int n=sz(s);
    ll res=0;
    rep(i,n){
        res=res*26+s[i]-'a'+1;
    }
    return res;
}



//manachar
//manachar's
//0-based indexing
//p[0][i] is the maximum length of half palindrome around half index i
//p[1][i] is the maximum length of half palindrome around character i
//Anachor
vector<int> p[2];
//O(n)
void manacher(const string &s){
    int n = s.size();
    p[0] = vector<int>(n+1);
    p[1] = vector<int>(n);

    for(int z=0;z<2;z++){
        for(int i=0, l=0, r=0; i<n; i++){
            int t = r - i + !z;
            if(i<r)p[z][i] = min(t,p[z][l+t]);
            int L = i-p[z][i], R = i+p[z][i]- !z;
            while(L>=1 && R+1<n && s[L-1] == s[R+1])
                p[z][i]++,L--,R++;
            if(R>r)l=L, r=R;
        }
    }
}
//checks if substring from l to r is palindrome or not (0 indexed)
bool isPalindrome(int l, int r){
    int mid = (l+r+1)/2;
    int sz= r-l+1;
    bool b = sz%2;
    int len = p[b][mid];
    len = 2*len +b;
    return len>=sz;
}
/// manachar another version
int pal[2*maxx];
string get(string &s)
{
    string r;
    r.pb('#');
    int szz=sz(s);
   	rep(i,szz){
          r.pb(s[i]);
          r.pb('#');
    }
    return r;

}
void manach(string s){
	
    int i, now = 0;
    //pal[0] = 0;
    int szz=sz(s);
    for(i = 0; i<szz; i++){
        pal[i] = max(0,min(pal[now]-(i-now),pal[now-(i-now)])) + 1;
        while(i-pal[i]>=0 && s[i+pal[i]]==s[i-pal[i]]) pal[i]++;
        pal[i]--;
        if(i+pal[i]>now+pal[now]) now = i;
    }
}
bool isPalindrome(int l, int r){
    int mid = (l+r+1)/2;
    int sz= r-l+1;
    int len = pal[mid];
    len = 2*len+1;
    //len/=2;
    return len>=sz;
}









/**
*Anachor(cf)


Simple Library for String Hashing
Uses Rolling Double Hash.
Hash(abc........z) = a*p^n + b*p^(n-1) + ...... + z
Cautions:
1.  You may assign any integer values to characters.
    Common is 'a' = 1, 'b' = 2 ..........
    Here the ascii values of characters is used.
    But never assign any character the value 0.
    For example if 'a' = 0; 'abc' and 'bc' has the same hash.
2.  Single Hashing with an unusual mod is often enough,
    but will surely fail for good enough judge-data.
    In order to convert to Single Hash -
        o Delete operator overloads (optional)
        o Replace all pll with LL
        o Change mp pairs to appropriate value
Some Primes:
1000000007, 1000000009, 1000000861, 1000099999      ( < 2^30 )
1088888881, 1111211111, 1500000001, 1481481481      ( < 2^31 )
2147483647 (2^31-1),
**/



const pll M=mp(1e9+7, 1e9+9);   ///Should be large primes
const ll base=347;              ///Should be a prime larger than highest value
const int N = 1e6+7;            ///Highest length of string

ostream& operator<<(ostream& os, pll hash) {
    return os<<"("<<hash.ff<<", "<<hash.ss<<")";
}

pll operator+ (pll a, ll x)     {return mp(a.ff + x, a.ss + x);}
pll operator- (pll a, ll x)     {return mp(a.ff - x, a.ss - x);}
pll operator* (pll a, ll x)     {return mp(a.ff * x, a.ss * x);}
pll operator+ (pll a, pll x)    {return mp(a.ff + x.ff, a.ss + x.ss);}
pll operator- (pll a, pll x)    {return mp(a.ff - x.ff, a.ss - x.ss);}
pll operator* (pll a, pll x)    {return mp(a.ff * x.ff, a.ss * x.ss);}
pll operator% (pll a, pll m)    {return mp(a.ff % m.ff, a.ss % m.ss);}

pll power (pll a, ll p) {
    if (p==0)   return mp(1,1);
    pll ans = power(a, p/2);
    ans = (ans * ans)%M;
    if (p%2)    ans = (ans*a)%M;
    return ans;
}

///Magic!!!!!!!
pll inverse(pll a)  {
    return power(a, (M.ff-1)*(M.ss-1)-1);
}

pll pb[N];      ///powers of base mod M
pll invb;

///Call pre before everything
void hashPre() {
    pb[0] = mp(1,1);
    for (int i=1; i<N; i++)
        pb[i] = (pb[i-1] * base)%M;
    invb = inverse(pb[1]);
}

///Calculates Hash of a string
pll Hash (string s) {
    pll ans = mp(0,0);
    for (int i=0; i<(int)s.size(); i++)
        ans=(ans*base + s[i])%M;
    return ans;
}

///appends c to string
pll append(pll cur, char c) {
    return (cur*base + c)%M;
}

///prepends c to string with size k
pll prepend(pll cur, int k, char c) {
    return (pb[k]*c + cur)%M;
}

///replaces the i-th (0-indexed) character from right from a to b;
pll replace(pll cur, int i, char a, char b) {
    cur = (cur + pb[i] * (b-a))%M;
    return (cur + M)%M;
}

///Erases c from the back of the string
pll pop_back(pll hash, char c) {
    return (((hash-c)*invb)%M+M)%M;
}

///Erases c from front of the string with size len
pll pop_front(pll hash, int len, char c) {
    return ((hash - pb[len-1]*c)%M+M)%M;
}

///concatenates two strings where length of the right is k
pll concat(pll left, pll right, int k) {
    return (left*pb[k] + right)%M;
}

///Calculates hash of string with size len repeated cnt times
///This is O(log n). For O(1), pre-calculate inverses
pll repeat(pll hash, int len, ll cnt) {
    pll mul = (pb[len*cnt] - 1) * inverse(pb[len]-1);
    mul = (mul%M+M)%M;
    pll ans = (hash*mul)%M;

    if (pb[len].ff == 1)    ans.ff = hash.ff*cnt;
    if (pb[len].ss == 1)    ans.ss = hash.ss*cnt;
    return ans;
}

///Calculates hashes of all prefixes of s including empty prefix
vector<pll> res(maxx);
vector<pll> hashList(string s) {
    int n = s.size();
    res[0] = mp(0,0);

    for (int i=1; i<=n; i++)
        res[i] = (res[i-1] * base + s[i-1])%M;
    return res;
}

///Calculates hash of substring s[l..r] (1 indexed)
pll substringHash(const vector<pll> &hashlist, int l, int r) {
    int len = (r-l+1);
    return ((hashlist[r] - hashlist[l-1]*pb[len])%M+M)%M;
}

bool equalSub(const int l1,const int r1,const int l2,const int r2,const vpll& h1,const vpll& h2){
	return substringHash(h1,l1,r1)==substringHash(h2,l2,r2);
}

///Solves LightOJ 1255-Substring Frequency
///You are given two strings A and B. You have to find
///the number of times B occurs as a substring of A.
char buffer[N];
int main()
{
    hashPre();
    int t;
    scanf("%d", &t);

    for (int cs=1; cs<=t; ++cs)
    {
        string a, b;
        scanf("%s", buffer); a = buffer;
        scanf("%s", buffer); b = buffer;
        int na = a.size(), nb = b.size();

        pll hb = Hash(b);
        vector<pll> ha = hashList(a);
        int ans = 0;

        for (int i=1; i+nb-1<=na; i++)
            if (substringHash(ha, i, i+nb-1) == hb)  ans++;
        printf("Case %d: %d\n", cs, ans);
    }
}







//Largest rectangle Area in a histogram in O(n)
 int getMaxArea(int hist[], int n) 
{ 
    // Create an empty stack. The stack holds indexes  
    // of hist[] array. The bars stored in stack are  
    // always in increasing order of their heights. 
    stack<int> s; 
  
    int max_area = 0; // Initialize max area 
    int tp;  // To store top of stack 
    int area_with_top; // To store area with top bar 
                       // as the smallest bar 
  
    // Run through all bars of given histogram 
    int i = 0; 
    while (i < n) 
    { 
        // If this bar is higher than the bar on top  
        // stack, push it to stack 
        if (s.empty() || hist[s.top()] <= hist[i]) 
            s.push(i++); 
  
        // If this bar is lower than top of stack,  
        // then calculate area of rectangle with stack  
        // top as the smallest (or minimum height) bar.  
        // 'i' is 'right index' for the top and element  
        // before top in stack is 'left index' 
        else
        { 
            tp = s.top();  // store the top index 
            s.pop();  // pop the top 
  
            // Calculate the area with hist[tp] stack  
            // as smallest bar 
            area_with_top = hist[tp] * (s.empty() ? i :  
                                   i - s.top() - 1); 
  
            // update max area, if needed 
            if (max_area < area_with_top) 
                max_area = area_with_top; 
        } 
    } 
  
    // Now pop the remaining bars from stack and calculate 
    // area with every popped bar as the smallest bar 
    while (s.empty() == false) 
    { 
        tp = s.top(); 
        s.pop(); 
        area_with_top = hist[tp] * (s.empty() ? i :  
                                i - s.top() - 1); 
  
        if (max_area < area_with_top) 
            max_area = area_with_top; 
    } 
  
    return max_area; 
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




//Basic Dijkstra
int src=1;
dist[src]=0;
multiset<pair<int,int>>q;
q.insert({0,src});
while(!q.empty()){
    int u=(*q.begin()).ss,w=(*q.begin()).ff;
    //debug(u,w,vis[u]);
    q.erase(q.begin());
    if(vis[u]) continue;
    //debug("chk");
    vis[u]=1;
    //debug(edg[u].size());
    forch(it,edg[u]){
        int v=it.ff,cost=it.ss;
        if(cost+w<dist[v]){
            dist[v]=cost+w;
            q.insert({dist[v],v});
        }
    }
}
if(dist[n]<(int)1e7) printf("%d\n",dist[n]);
else printf("Impossible\n");




//next greater element O(n) using stack
pair<vi,vi> nge(int arr[],int n){//next greater element
    vi ngeElement(n,-1),ngeInd(n,-1);
    stack<int>sEl,sInd;
    sEl.push(arr[0]);
    sInd.push(0);
    rep1(i,1,n-1){
        if(sEl.empty())
        {
            sEl.push(arr[i]);
            sInd.push(i);
            continue;
        }
        while(!sEl.empty() and sEl.top()<arr[i]){
            ngeElement[sInd.top()]=arr[i];
            ngeInd[sInd.top()]=i;
            sEl.pop();
            sInd.pop();
        }
        sEl.push(arr[i]);
        sInd.push(i);
    }
    return {ngeElement,ngeInd};
}
//next greater element O(n) using stack reverse order
pair<vi,vi> ngerev(vi arr,int n){//next greater element
    vi ngeElement(n,-1),ngeInd(n,-1);
    stack<int>sEl,sInd;
    sEl.push(arr[n-1]);
    sInd.push(n-1);
    irep(i,n-2,0){
        if(sEl.empty())
        {
            sEl.push(arr[i]);
            sInd.push(i);
            continue;
        }
        while(!sEl.empty() and sEl.top()<arr[i]){
            ngeElement[sInd.top()]=arr[i];
            ngeInd[sInd.top()]=i;
            sEl.pop();
            sInd.pop();
        }
        sEl.push(arr[i]);
        sInd.push(i);
    }
    return {ngeElement,ngeInd};
}



//HLD heavy light decomposition 
int chainNo, chainInd[maxx], chainHead[maxx], posInBase[maxx],ptr;
ll baseArray[maxx];
vi edg[maxx],par(maxx),heavy_child(maxx); //heavy_child refers to the child who has the maximum subtree size, we can find that using dfs.
int dfs(int v,int p){
    int szz=1;
    int mxsz=0;
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
    return szz;
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





//segment tree without update for finding rmq
ll minSeg[4*maxx],maxSeg[4*maxx],arr[maxx];
void build(int treeL,int treeR,int pos){
    if(treeL==treeR){
        minSeg[pos]=arr[treeL];
        maxSeg[pos]=arr[treeR];
        return;
    }
    int mid=treeL+(treeR-treeL)/2;
    build(treeL,mid,2*pos+1);
    build(mid+1,treeR,2*pos+2);
    minSeg[pos]=min(minSeg[2*pos+1],minSeg[2*pos+2]);
    maxSeg[pos]=max(maxSeg[2*pos+1],maxSeg[2*pos+2]);
}
ll minQ(int treeL,int treeR,int L,int R,int pos){
    if(treeR<L or treeL>R) return highest(ll);
    if(L<=treeL and treeR<=R){
        return minSeg[pos];
    }
    int mid=treeL+(treeR-treeL)/2;
    return min(minQ(treeL,mid,L,R,2*pos+1),minQ(mid+1,treeR,L,R,2*pos+2));
}
ll maxQ(int treeL,int treeR,int L,int R,int pos){
    if(treeR<L or treeL>R) return lowest(ll);
    if(L<=treeL and treeR<=R){
        return maxSeg[pos];
    }
    int mid=treeL+(treeR-treeL)/2;
    return max(maxQ(treeL,mid,L,R,2*pos+1),maxQ(mid+1,treeR,L,R,2*pos+2));
}



// min in a range with lazy propagation.
struct SegmentTree
{
	typedef int T;
	#define MAX 500007
	#define lc (at<<1)
	#define rc ((at<<1)|1)
 
	pii Tree[4*MAX];
	T Lazy[4*MAX];
 
	SegmentTree() { }
 
	void pushdown(int at)
	{
		if(Lazy[at])
		{
			Lazy[lc]+=Lazy[at];
			Lazy[rc]+=Lazy[at];
			Tree[lc].first+=Lazy[at];
			Tree[rc].first+=Lazy[at];
			Lazy[at]=0;
		}
	}
 
	void build(int at, int l, int r)
	{
		Lazy[at]=0;
		if(l==r)
		{
			Tree[at] = pii(a[l], l); // Tree[at] = in[l]; input values
			return;
		}
		int mid=(l+r)/2;
		build(lc,l,mid);
		build(rc,mid+1,r);
		Tree[at]=min(Tree[lc],Tree[rc]);
		Lazy[at]=0;
	}
	// Range update
	void update(int at, int l, int r, int x, int y, T val)
	{
		if(x>r || y<l) return;
		if(x<=l && r<=y)
		{
			Tree[at].first+=val;
			Lazy[at]+=val;
			return;
		}
 
		if(l!=r) pushdown(at);	
 
		int mid=(l+r)/2;
		update(lc,l,mid,x,y,val);
		update(rc,mid+1,r,x,y,val);
		Tree[at]=min(Tree[lc],Tree[rc]);
	}
	// Range query
	pii query(int at, int l, int r, int x, int y)
	{
		if(x>r || y<l) return pii(inf, -1);
		if(x<=l && r<=y) return Tree[at];
		if(l!=r) pushdown(at);
 
		int mid=(l+r)/2;
		return min(query(lc,l,mid,x,y),query(rc,mid+1,r,x,y));
	}
} seg;



//kth smallest number in a range 
vector<int> seg[4*maxx]; 
void build(int ci, int st, int end, pair<int, int>* B) 
{ 
    if (st == end) { 
        seg[ci].push_back(B[st].second); 
        return; 
    } 
  
    int mid = (st + end) / 2; 
    build(2 * ci + 1, st, mid, B); 
    build(2 * ci + 2, mid + 1, end, B);  
    merge(seg[2 * ci + 1].begin(), seg[2 * ci + 1].end(), 
          seg[2 * ci + 2].begin(), seg[2 * ci + 2].end(), 
          back_inserter(seg[ci])); 
} 
int query(int ci, int st, int end, int l, int r, int k) 
{ 

    if (st == end) 
        return seg[ci][0]; 
    int p = upper_bound(seg[2 * ci + 1].begin(), 
                        seg[2 * ci + 1].end(), r) 
            - lower_bound(seg[2 * ci + 1].begin(), 
                          seg[2 * ci + 1].end(), l); 
  
    int mid = (st + end) / 2; 
    if (p >= k) 
        return query(2 * ci + 1, st, mid, l, r, k); 
    else
        return query(2 * ci + 2, mid + 1, end, l, r, k - p); 
} 
void solve(){
    int n,q;
    cin>>n>>q;
    vi arr(n);
    rep(i,n) cin>>arr[i];
    pair<int, int> B[n]; 
  
    for (int i = 0; i < n; i++) { 
        B[i] = { arr[i], i }; 
    } 
    sort(B, B + n); 
    build(0, 0, n - 1, B); 
    while(q--){
        int l,r,k;
        cin>>l>>r>>k;
        l--,r--;
        cout<<arr[query(0, 0, n - 1, l, r, k)]<<endl;//gives kth smalleset element in the subarray 
                                                    //starts from l to rth index.
    }
}




//bit binary indexed tree
int bit[maxx];
void update(int pos,int val,int n){
    while(pos<=n){
        bit[pos]+=val;
        pos+=(pos&-pos);
    }
}
int query(int pos){
    int sum=0;
    while(pos>0){
        sum+=bit[pos];
        pos-=(pos&-pos);
    }
    return sum;
}



//segment tree "range update range sum query" with lazy propagation 
ll segsum[4*maxx],lazy[4*maxx];
void pushDown(int pos,int treeL,int treeR){
    if(lazy[pos]!=0){
        segsum[pos]+=(lazy[pos]*(treeR-treeL+1)*1ll);
        if(treeL!=treeR)
        {
            lazy[2*pos+1]+=lazy[pos];
            lazy[2*pos+2]+=lazy[pos];
        }
        lazy[pos]=0;
    }
}
void update(int treeL,int treeR,int ul,int ur,int pos,ll val){
    pushDown(pos,treeL,treeR);
    if(ul<=treeL and ur>=treeR){//total overlap
        segsum[pos]+=(val*(treeR-treeL+1)*1ll);
        if(treeL!=treeR){
            lazy[2*pos+1]+=val;
            lazy[2*pos+2]+=val;
        }
        return;
    }
    if(ul>treeR or ur<treeL) return;
    int mid=treeL+(treeR-treeL)/2;
    update(treeL,mid,ul,ur,2*pos+1,val);
    update(mid+1,treeR,ul,ur,2*pos+2,val);
    segsum[pos]=segsum[2*pos+1]+segsum[2*pos+2];
}
ll query(int treeL,int treeR,int ql,int qr,int pos){
    pushDown(pos,treeL,treeR);
    if(ql>treeR or qr<treeL) return 0ll;
    if(ql<=treeL and qr>=treeR){
        return segsum[pos];
    }
    int mid=treeL+(treeR-treeL)/2;
    return query(treeL,mid,ql,qr,2*pos+1)+query(mid+1,treeR,ql,qr,2*pos+2);
}




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


//Phi(x), number of i(1<=i<=x-1) where gcd(i,x)==1;
//Source: http://shoshikkha.com/archives/1472
ull phi[maxx] ;
void sievePHI(){
    ull i,j;
    for( i=2;i<maxx;i++){
        if( phi[i]==0){
            phi[i] = i-1;
            for( j = i*2; j<maxx; j+=i){
                if( phi[j] == 0 )phi[j] = j;
                phi[j] /= i ;
                phi[j] *= (i-1);
            }
        }
    }
}

//for a big number 
ll prime(ll a)
{
    for(int i=2;i*i<=a;i++)
        if(a%i==0) return 1;
    return 0;
}
ll phi(ll n)
{
    ll i,mul=1,holder,fre=0;
    if(prime(n)==0) mul=n-1;
    else
    {
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                while(n%i==0)
                {
                    fre++;n/=i;holder=i;
                }
                mul*=(po(holder,fre-1)*(holder-1));
                fre=0;
            }
        }
        if(n!=1)
            mul*=(n-1);
    }
    return mul;
}


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



//LCA using binaryLifting with O(logn) complexity per query and O(nlogn) complexity for precomputation
int n,ht,timer;
vector<vector<int>>up;
vector<int>edg[maxx];
vector<int>st,en;
void dfs(int v,int p){
    st[v]=++timer;
    up[v][0]=p;
    for(int i=1;i<=ht;i++){
        up[v][i]=up[up[v][i-1]][i-1];
    }
    for(int u:edg[v])
    {
        if(u!=p) dfs(u,v);
    }
    en[v]=++timer;
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
void prepo(int root){
    st.resize(n);
    en.resize(n);
    timer=0;
    ht=ceil(log2(n));
    //debug(ht);
    up.assign(n, vector<int>(ht + 1));
    dfs(root,root);
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



//to find number of unique prime factors for every number 1 to maxx
int nopf[maxx];
void sieve(){
    rep1(i,2,maxx-1){
        if(nopf[i]==0){
            for(int j=i;j<maxx;j+=i){
                nopf[j]++;
            }
        }
    }
}



//Smallest Prime Factor to find prime factor in O(nlognlogn) preprossesing and O(logn)

vll Spf(maxx);
void spf(){
    Spf[1]=1;
    rep1(i,1,maxx-1){
    	Spf[i]=i;
    }
    rep1(i,4,maxx-1){
    	Spf[i]=2;
    	i++;
    }
    for(ll i=3;i*i<maxx;i++){
        if(Spf[i]==i){
            for(ll j=i*i;j<maxx;j+=i){
                if(Spf[j]==j){
                	Spf[j]=i;
                }
            }
        }
    }
}
//Sum of Divisor using smallest prime factor
ll sumOfDiv(int x){
	ll d=1;
	while (x != 1) {
	     ll p = Spf[x];
	     ll val=1;
	     while (Spf[x] == p) {
	         val*=Spf[x];
	         x /= Spf[x];
	     }
     	val*=p;
     	d*=(val-1);
     	d/=(p-1);
	}
	return d;
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
    ll denom= (modPow(fact[k],MOD-2)+MOD)%MOD*(modPow(fact[n-k],MOD-2)+MOD)%MOD;
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
    inv[maxx-1]=modPow(fact[maxx-1],MOD-2);
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


//Binary indexed tree(BIT) point update point query
struct BIT{
    vector<int>bt;
    BIT(int n){
        bt.resize(n+1);
    }
    void update(int pos,int val,int upto){
        while(pos<=upto){
            bt[pos]+=val;
            pos+=(pos&-pos);
        }
    }
    int query(int pos){
        int res=0;
        while(pos>0){
            res+=bt[pos];
            pos-=(pos&-pos);
        }
        return res;
    }
};


//rmq by sparse table
struct rmq{
    vector<int>arr;
    vector<vector<int>>sparse;
    int maxxx;
    void init(int n,vector<int>vec){
        maxxx=n;
        arr=vec;
        sparse.resize(n);
        for(auto &it:sparse ){
            it.resize((int)log2(n)+1);
        }
    }
    int  po(int  base , int power){
        int ret=1;
        while(power){
            ret*=base;
            power--;
        }
        return ret;
    }
    ll lg2(ll x){
        ll res=0;
        while(x>1){
            res++;
            x/=2ll;
        }
        return res;
    }
    void prepo(){
        int col=lg2(maxxx)+1;
        for(int i=0;i<maxxx;i++) sparse[i][0]=i; /*the first column of sparse table is equal to the row number because
        the index of the minimum element in range start from ith index to the next 2^0 element is the i itself*/
        for(int j=1;j<=col;j++){
            for(int i=0;i+po(2,j)-1<maxxx;i++){ // this condition is for not going out of bound. else range may go out of bound.
                if(arr[sparse[i][j-1]]<arr[sparse[i+po(2,j-1)][j-1]]){ /*this conditions use the previous range's result. Basically,breaks the
                        present range into two halves that represents the previously calculated halves and compare between them. Seems like used
                        DP here*/
                    sparse[i][j]=sparse[i][j-1];
                }
                else {
                    sparse[i][j]=sparse[i+po(2,j-1)][j-1];
                }
            }
        }
    }
    int minQ(int l,int r){
        int tot=r-l+1;
        int k=log2(tot);
        int slide=l+(tot-pow(2,k));
        return min(arr[sparse[l][k]],arr[sparse[slide][k]]);
        /*
        dividing the range into to halves: 1st--> starting from l to next 2^k elements
                                           2nd--> starting from l+(number of the rest of the elements that was outside the 1st range) to next 2^k 
                                           elements
        */
    }
};



//2d rmq using sparse table, 0 indexed
int n,arr[maxx][maxx],q;
pair<int,int>sparsT[maxx][maxx][maxln];
void prepo(){
    rep(i,n){
        rep(j,n) sparsT[i][j][0]={i,j};
    }
    int col=(int)log2(n)+1;
    rep1(k,1,col){
        for(int i=0;i+po(2,k)-1<n;i++){
            for(int j=0;j+po(2,k)-1<n;j++){
                int x=i+po(2,k-1),y=j+po(2,k-1);
                int x1=sparsT[i][j][k-1].ff,y1=sparsT[i][j][k-1].ss,x2=sparsT[i][y][k-1].ff,y2=sparsT[i][y][k-1].ss;
                if(arr[x1][y1]>arr[x2][y2]){
                    sparsT[i][j][k]=sparsT[i][j][k-1];
                }
                else{
                    sparsT[i][j][k]=sparsT[i][y][k-1];
                }
                x1=sparsT[x][j][k-1].ff,y1=sparsT[x][j][k-1].ss,x2=sparsT[x][y][k-1].ff,y2=sparsT[x][y][k-1].ss;
                int x3,y3;
                if(arr[x1][y1]>arr[x2][y2]){
                    x3=sparsT[x][j][k-1].ff;
                    y3=sparsT[x][j][k-1].ss;
                }
                else{
                    x3=sparsT[x][y][k-1].ff;
                    y3=sparsT[x][y][k-1].ss;
                }
                x1=sparsT[i][j][k].ff,y1=sparsT[i][j][k].ss;
                if(arr[x1][y1]>arr[x3][y3]){
                    sparsT[i][j][k]=sparsT[i][j][k];
                }
                else{
                    sparsT[i][j][k]={x3,y3};
                }
            }
        }
    }
}
int minQ(int x1,int y1,int x2,int y2){
    int Lx=x2-x1+1,Ly=y2-y1+1;
    int kx=(int)log2(Lx),ky=int(log2(Ly));
    int slidex=x1+(Lx-po(2,kx)),slidey=y1+(Ly-po(2,ky));
    int a1=sparsT[x1][y1][ky].ff,b1=sparsT[x1][y1][ky].ss,a2=sparsT[x1][slidey][ky].ff,b2=sparsT[x1][slidey][ky].ss;
    int m1=max(arr[a1][b1],arr[a2][b2]);
    a1=sparsT[slidex][y1][kx].ff,b1=sparsT[slidex][y1][kx].ss,a2=sparsT[slidex][slidey][kx].ff,b2=sparsT[slidex][slidey][kx].ss;
    int m2=max(arr[a1][b1],arr[a2][b2]);
    return max(m1,m2);

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



//Minimum Spanning Tree (mst) using dsu
int n;
scanf("%d",&n); //number of nodes
vector<tuple<int,int,int>>edgs;
int u,v,w;
while(scanf("%d%d%d",&u,&v,&w)) { //given edges of that graph
        if(u==0 and v==0) break;
        edgs.pb(make_tuple(w,u,v));
}
sort(ALL(edgs)); //sorting acording to the ascending order of the cost of the edgs.
int szz=sz(edgs);
int minCost=0; //minimum cost of that spanning tree.
DSU d(n);
rep(i,szz){
    int w=get<0>(edgs[i]),u=get<1>(edgs[i]),v=get<2>(edgs[i]);
    if(d.root(u)!=d.root(v)){
        minCost+=w;
        d.merge(u,v);
    }
}




//articulation bridges 
//graph can not contain multiple edgs and self edgs
//graph can be disconnected
vi edg[maxx],st(maxx),low(maxx,highest(int)),vis(maxx); // st-> stores dicovery time of every node in dfs tree. 
vpii bridgs;                                            // low[u]-> sotres the lowest discovery time among set of nodes in the subtree of u 
int Time=0;
void init(int n){
    rep(i,n) edg[i].clear(),st[i]=0,low[i]=highest(int),vis[i]=0;
    bridgs.clear();
    Time=0;
}
void dfs(int u,int p){
    vis[u]=1;
    low[u]=st[u]=++Time;
    forch(v,edg[u]){
        if(v==p) continue;
        if(vis[v]){
            low[u]=min(low[u],st[v]);
        }
        else{
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(st[u]<low[v]){                       //this code is for bridges purpose. but por articulation point, just this condition 
                                                    // st[u]<low[v] will be replaced by st[u]<=low[v];
                bridgs.pb({min(u,v),max(u,v)});
            }
        }
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    init(n);
    rep(i,m){
        int u,v;
        cin>>u>>v;
        u--,v--;
        edg[u].pb(v);
        edg[v].pb(u);
    }
    rep(i,n){
        if(!vis[i]){
            dfs(i,-1);
        }
    }
    cout<<bridgs.size()<<endl;
    
}


//articulation points
vi edg[maxx],st(maxx),low(maxx,highest(int)),vis(maxx),par(maxx),points(maxx); // st-> stores dicovery time of every node in dfs tree.
                                            // low[u]-> sotres the lowest discovery time among set of nodes in the subtree of u
int Time=0;
void init(int n){
    rep(i,n) edg[i].clear(),st[i]=0,low[i]=highest(int),vis[i]=0,par[i]=-1,points[i]=0;
    Time=0;
}
void dfs(int u,int p){
    vis[u]=1;
    low[u]=st[u]=++Time;
    int ch=0;
    forch(v,edg[u]){
        if(v==p) continue;
        if(vis[v]){
            low[u]=min(low[u],st[v]);
        }
        else{
            par[v]=u;
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(st[u]<=low[v] and par[u]!=-1){                       //this code is for bridges purpose. but por articulation point, just this condition
                points[u]=1;                                    // st[u]<low[v] will be replaced by st[u]<=low[v];
            }
            ch++;
        }
        if(par[u]==-1 and ch>1) points[u]=1;
    }

}
void solve(){
    int n,m;
    scanf("%d%d",&n,&m);
    init(n);
    rep(i,m){
        int u,v;
        scanf("%d%d",&u,&v);
        u--,v--;
        edg[u].pb(v);
        edg[v].pb(u);
    }
    dfs(0,-1);
    int ans=0;
    rep(i,n) ans+=points[i];
    printf("%d\n",ans);

}



//trie data structure
struct node {
    bool endmark;
    node* next[26 + 1];
    node()
    {
        endmark = false;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
} * root;
void ins(string str)
{
    int len=sz(str);
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }
    curr->endmark = true;
}
bool srch(string str)
{
    int len=sz(str);
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            return false;
        curr = curr->next[id];
    }
    return curr->endmark;
}
void del(node* cur)
{
    for (int i = 0; i < 26; i++)
        if (cur->next[i])
            del(cur->next[i]);

    delete (cur);
}

void solve(){
    root=new node();
    //all other code

    del(root);
}



//bipartite checking
//bipertite
//biper
int n;
vector<vector<int>> edg;

vector<int> inSet(n, -1);//isSet[i]=0 means ith node is in set 0
						// isSet[i]=1 means ith node is in set 1
bool is_bipartite = true;
queue<int> q;
for (int st = 0; st < n; ++st) {
    if (inSet[st] == -1) {
        q.push(st);
        inSet[st] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            forch(u,edg[v]) {
                if (inSet[u] == -1) {
                    inSet[u] = inSet[v] ^ 1;
                    q.push(u);
                } else {
                    is_bipartite &= inSet[u] != inSet[v];
                }
            }
        }
    }
}

cout << (is_bipartite ? "YES" : "NO") << endl;





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



