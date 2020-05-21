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
int segt[4*maxx][3];
//int trace[4*maxx];
int lazy[4*maxx];
void build(int nodel,int noder,int pos)
{
    if(nodel==noder){
        segt[pos][0]=1;
        return;
    }
    int mid=nodel+(noder-nodel)/2;
    build(nodel,mid,2*pos+1);
    build(mid+1,noder,2*pos+2);
    segt[pos][0]=segt[2*pos+1][0]+segt[2*pos+2][0];
}
void update(int ul,int ur,int nodel,int noder,int pos){
    if(lazy[pos]){
        for(int i=0;i<lazy[pos]%3;i++){
            int tmp=segt[pos][0];
            segt[pos][0]=segt[pos][2];
            segt[pos][2]=segt[pos][1];
            segt[pos][1]=tmp;
        }
        if(nodel!=noder){
            lazy[2*pos+1]=lazy[2*pos+1]+lazy[pos];
            lazy[2*pos+2]=lazy[2*pos+2]+lazy[pos];
        }
        lazy[pos]=0;
    }
    if(ul>noder || ur<nodel || nodel>noder) return;
    if(ul<=nodel && ur>=noder) {
        int tmp=segt[pos][0];
            segt[pos][0]=segt[pos][2];
            segt[pos][2]=segt[pos][1];
            segt[pos][1]=tmp;
        if(nodel!=noder){
            lazy[2*pos+1]=lazy[2*pos+1]+1;
            lazy[2*pos+2]=lazy[2*pos+2]+1;
        }
        return;
    }
    int mid=nodel+(noder-nodel)/2;
    update(ul,ur,nodel,mid,2*pos+1);
    update(ul,ur,mid+1,noder,2*pos+2);
    segt[pos][0]=segt[2*pos+1][0]+segt[2*pos+2][0];
    segt[pos][1]=segt[2*pos+1][1]+segt[2*pos+2][1];
    segt[pos][2]=segt[2*pos+1][2]+segt[2*pos+2][2];
}
int query(int ql,int qr,int nodel,int noder,int pos){
    if(lazy[pos]){
        for(int i=0;i<lazy[pos]%3;i++){
            int tmp=segt[pos][0];
            segt[pos][0]=segt[pos][2];
            segt[pos][2]=segt[pos][1];
            segt[pos][1]=tmp;
        }
        if(nodel!=noder){
            lazy[2*pos+1]=(lazy[2*pos+1]+lazy[pos]);
            lazy[2*pos+2]=(lazy[2*pos+2]+lazy[pos]);
        }
        lazy[pos]=0;
    }
    if(ql>noder || qr<nodel || nodel>noder) return 0;
    if(ql<=nodel && qr>=noder) {

        return segt[pos][0];
    }
    int mid=nodel+(noder-nodel)/2;
    return query(ql,qr,nodel,mid,2*pos+1)+query(ql,qr,mid+1,noder,2*pos+2);
}
int main()

{
	IOS;
	//freopen("input.txt", "r", stdin);
     //freopen("output.txt", "w", stdout);
     int n,m;
     //cin>>n>>m;
     scanf("%d%d",&n,&m);
     build(0,n-1,0);
     while(m--){
        int op;
       // cin>>op;
       scanf("%d",&op);
        if(op==0){
            int l,r;
           // cin>>l>>r;
           scanf("%d%d",&l,&r);
            update(l,r,0,n-1,0);

        }
        else{
            int l,r;
            //cin>>l>>r;
            scanf("%d%d",&l,&r);
            //cout<<query(l,r,0,n-1,0)<<endl;
            printf("%d\n",query(l,r,0,n-1,0));
        }
     }

	 return 0;

}
///Alhamdulillah
