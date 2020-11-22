/// Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;
#define SET(x) memset(x, 0, sizeof(x))
#define SET2d(x,m,n) memset(x, 0, sizeof(x[0][0]) * m * n)
#define SETBOOL(x) memset(x,false,sizeof(x))
#define CLR(x) memset(x, -1, sizeof(x))
#define mp make_pair
#define PII pair<int, int>
#define pf printf

#define sf scanf

#define ALL(x) x.begin(),x.end()
#define pb push_back

#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define np std::string::npos
#define for0(i,n) for(int i=0;i<n;i++)
#define forn(i,n) for(int i=n-1;i>=0;i--)
#define highest(x) numeric_limits<x>::max()
#define lowest(x) numeric_limits<x>::min()
#define Inf INFINITY
#define minv(v) *min_element(v.begin(),v.end())
#define maxv(v) *max_element(v.begin(),v.end())
#define cases(cs,t) for(int cs=1;cs<=t;cs++)
#define PI acos(-1)
#define no1 __builtin_popcount
typedef long long ll;
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[] = {0, 0, 1, -1};
int dy4[] = {1, -1, 0, 0};
const int maxx=100005;
int G[105][105];

//this fuction sorts vector pair according to first element in descending order.
bool sortinrev(const pair<int,int> &a,const pair<int,int> &b)
{
    if((!G[a.second][b.second] && !G[b.second][a.second])) return a.second<b.second;
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
vector<int>edg[maxx];
int vis[maxx];
int ftim[maxx];
int Time=0;

void dfs(int src){
    vis[src]=1;
    Time++;
    for(int i=0;i<edg[src].size();i++){
        int v=edg[src][i];
        if(!vis[v]){
            dfs(v);
        }
    }
    ftim[src]=++Time;
}

int main()

{
    IOS;
    //freopen("input.txt", "r", stdin);
     //freopen("output.txt", "w", stdout);
     int n,m;
     int cs=0;
     while(cin>>n){
            map<string,int>_stoi;
            map<int,string>_itos;
        for(int i=0;i<maxx;i++) edg[i].clear();
        SET(vis);
        SET(ftim);
        SET2d(G,105,105);
        int ind[n+1];
        SET(ind);
        for(int i=1;i<=n;i++){
            string s;
            cin>>s;
            _stoi[s]=i;
            _itos[i]=s;
        }
        int m;
        cin>>m;
        for(int i=0;i<m;i++){
            string u,v;
            cin>>u>>v;
            int uu=_stoi[u],vv=_stoi[v];
            edg[uu].pb(vv);
            G[uu][vv]=1;
            ind[vv]++;

        }
        priority_queue<int,vector<int>,greater<int>>q;
        int v=0;
        for(int i=1;i<=n;i++)
        {
            if(ind[i]==0) q.push(i);
        }
        cout<<"Case #"<<++cs<<": Dilbert should drink beverages in this order: ";
        while(!q.empty()){
            int u=q.top();
            q.pop();
            cout<<_itos[u];
            v++;
            for(int i=0;i<edg[u].size();i++){
                if(--ind[edg[u][i]]==0) q.push(edg[u][i]);
            }
            if(v!=n) cout<<" ";
        }
        cout<<"."<<endl;
        cout<<endl;

     }

     return 0;

}
///Alhamdulillah

