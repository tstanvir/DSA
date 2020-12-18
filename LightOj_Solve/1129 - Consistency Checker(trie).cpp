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
typedef long long ll;


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
int root;
int nnode;
int tree[100004][10];
int endofnum[100004];
void init(){
    memset(tree,0,sizeof tree[0][0]*100004*10);
    memset(endofnum,0,sizeof endofnum);
    root =0;
    nnode=0;
    for(int i=0;i<10;i++) tree[root][i]=-1;
}
bool isPre(string a){
    int l=a.size();
    int now=root;
    for(int i=0;i<l;i++){
        if(tree[now][a[i]-'0']==-1){
            tree[now][a[i]-'0']=++nnode;
        }
        for(int i=0;i<10;i++) tree[nnode][i]=-1;
        now=tree[now][a[i]-'0'];
        if(endofnum[now]==1) return true;

    }
    endofnum[now]=1;
    return false;




}

int main()

{
	IOS;
	int t;
	cin>>t;
	for(int o=1;o<=t;o++){
        int n;
        cin>>n;
        vector<pair<int,string>>vec;
        while(n--){
            string a;
            cin>>a;
            vec.pb(mp((int)a.size(),a));
        }
        sort(ALL(vec));
        init();
        bool chk=false;
        for(int i=0;i<vec.size();i++) {
                if(isPre(vec[i].second)) {
                    cout<<"Case "<<o<<": NO\n";
                    chk=true;
                    break;


                }
        }
        if(!chk) cout<<"Case "<<o<<": YES\n";

	}

	 return 0;

}

