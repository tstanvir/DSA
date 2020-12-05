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
const int N=100005;
int tree[300000];
int arr[N];
int n;
void init(){
    SET(tree);
    SET(arr);
}
void build(int node,int Start,int End){
    if(Start==End){
        tree[node]=arr[Start];
    }
    else{
        int mid=(Start+End)/2;
        build(2*node+1,Start,mid);
        build(2*node+2,mid+1,End);
        tree[node]=tree[2*node+1]+tree[2*node+2];
    }
}
void update(int node,int Start,int End,int idx,int val){
    if(Start==End){
        arr[idx]+=val;
        tree[node]+=val;
    }
    else {
        int mid=(Start+End)/2;
        if(idx>=Start&&idx<=mid){
            update(2*node+1,Start,mid,idx,val);
        }
        else {
            update(2*node+2,mid+1,End,idx,val);
        }
        tree[node]=tree[2*node+1]+tree[2*node+2];
    }
}
int query(int node,int Start,int End,int l,int r){
    if(l>End || r<Start) return 0;
    if(l<=Start&&r>=End) return tree[node];
    int mid=(Start+End)/2;
    int p1=query(2*node+1,Start,mid,l,r);
    int p2=query(2*node+2,mid+1,End,l,r);
    //cout<<p1<<" "<<p2<<endl;
    return (p1+p2);
}
int main()

{
	//IOS;
	//freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        int t;
        sf("%d",&t);

        for(int tc=1;tc<=t;tc++){
            init();
            pf("Case %d:\n",tc);
            int q;
            sf("%d%d",&n,&q);
           /* if(pow((double)2,log2((double)n))==n){
                N=2*n-1;
            }
            else{
                N=(int)log2((double)n)+1;
                N=pow((double)2,(double)N);
                N*=2;
                N--;
            }*/
            //int arr[n];
            for(int i=0;i<n;i++){
                sf("%d",&arr[i]);
            }
            build(0,0,n-1);
            while(q--){
                int a;
                sf("%d",&a);
                if(a==1){
                    int idx;
                    sf("%d",&idx);
                    pf("%d\n",arr[idx]);
                    update(0,0,n-1,idx,-arr[idx]);
                    arr[idx]=0;
                }
                if(a==2)
                {
                    int idx,val;
                    sf("%d%d",&idx,&val);
                    update(0,0,n-1,idx,val);
                }
                if(a==3){
                    int i,j;
                    sf("%d%d",&i,&j);
                    pf("%d\n",query(0,0,n-1,i,j));
                }
            }


        }

	 return 0;

}

