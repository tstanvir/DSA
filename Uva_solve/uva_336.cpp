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
typedef long long ll;
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[] = {0, 0, 1, -1};
int dy4[] = {1, -1, 0, 0};
const int maxx=100005;

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
map<unsigned int,vector<unsigned int>>edg;
map<unsigned int,int>vis;
int whole=0;
map<unsigned int,int>dest;
/*void dfs(int src,int tf){
    vis[src]=1;
    for(int i=0;i<edg[src].size();i++){
        int v=edg[src][i];
        if(vis[v]==0 && tf>0){
                dfs(v,tf-1);
                whole++;
        }
    }
}*/
void bfs(int src){
    dest[src]=0;
    queue<unsigned int>q;
    q.push(src);
    vis[src]=1;
    while(!q.empty()){
        unsigned u=q.front();
        q.pop();
        for(int i=0;i<edg[u].size();i++){
            int v=edg[u][i];
            if(vis[v]==0){
                vis[v]=1;
                q.push(v);
                dest[v]=dest[u]+1;
            }
        }
    }
}

int main()

{
	//IOS;
	//freopen("input.txt", "r", stdin);
     //freopen("output.txt", "w", stdout);
     int n;
     int cs=0;
     while(scanf("%d",&n)){
        if(n==0) break;
        edg.clear();
        set<unsigned>st;
        map<unsigned,int>pre;
        for(int i=0;i<n;i++){
            unsigned u,v;
            scanf("%u%u",&u,&v);
            st.insert(u),st.insert(v);
            pre[u]=1;
            pre[v]=1;
            edg[u].pb(v);
            edg[v].pb(u);
        }
        unsigned node,tf;
        while(scanf("%u%u",&node,&tf) ){
            if(node==0 && tf==0) break;
            dest.clear();
            for(auto i=st.begin();i!=st.end();i++){
                unsigned int val=*i;
                dest[val]=highest(unsigned);
            }
            bfs(node);
            whole=0;
            vis.clear();
            for(auto i=st.begin();i!=st.end();i++){
                unsigned val=*i;
                if(dest[val]!=0 && dest[val]<=tf) whole++;
            }
            //dfs(node,tf);
            unsigned ans=pre[node]==1?st.size()-1-whole:st.size()-whole;
            printf("Case %d: %u nodes not reachable from node %d with TTL = %u.\n",++cs,ans,node,tf);
        }
        //printf("%d\n",n);
     }

	 return 0;

}
///Alhamdulillah
